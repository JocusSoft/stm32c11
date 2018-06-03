/*
 * File: startup.cpp
 * Project: stm32c11
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */

#include <stdint.h>

#include "peripherals/device_select.hpp"

#include "peripherals/device/stm32f0/interrupts_cpp.hpp"

#define INLINE inline __attribute__((always_inline))
typedef uint32_t u32;

int main();
extern u32 __etext;
extern u32 __data_start__;
extern u32 __data_end__;
extern u32 __bss_start__;
extern u32 __bss_end__;

/**
 * @brief Loads initialized data to RAM, and clears uninitialized data.
 */
static INLINE void initializeData()
{
  u32 *pSrc;
  u32 *pDest;

  // Load initialized data from FLASH to RAM
  pSrc = &__etext;
  pDest = &__data_start__;

  while (pDest < &__data_end__)
    *pDest++ = *pSrc++;

  // Clear uninitialized data
  pDest = &__bss_start__;

  while (pDest < &__bss_end__)
    *pDest++ = 0;
}

#define HSE_STARTUP_TIMEOUT   ((uint16_t)0x0500)

static void setSysClock()
{
    volatile static uint32_t StartUpCounter = 0, HSEStatus = 0;
    peripheral::regs::rcc::cr::hseon::set();
    do
    {
        HSEStatus = peripheral::regs::rcc::cr::hserdy::read();
        StartUpCounter++;
    } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));
    if (peripheral::regs::rcc::cr::hserdy::read() != 0)
    {
        HSEStatus = (uint32_t)0x01;
    }
    else
    {
        HSEStatus = (uint32_t)0x00;
    }
    if (HSEStatus == (uint32_t)0x01)
    {
        /* Enable Prefetch Buffer and set Flash Latency */
        peripheral::regs::flash::acr::latency::write(1);
        peripheral::regs::flash::acr::prftbe::write(1);
        

        /* HCLK = SYSCLK */
        peripheral::regs::rcc::cfgr::hpre::write(0);

        /* PCLK = HCLK */
        peripheral::regs::rcc::cfgr::ppre::write(0);

        /* PLL configuration = HSE * 6 = 48 MHz */
        peripheral::regs::rcc::cfgr::pllsrc::write(2);
        peripheral::regs::rcc::cfgr::pllxtpre::set();
        peripheral::regs::rcc::cfgr::pllmul::write(1);

        /* Enable PLL */
        peripheral::regs::rcc::cr::pllon::set();

        /* Wait till PLL is ready */
        while((peripheral::regs::rcc::cr::pllrdy::read()) == 0)
        {
        }

        /* Select PLL as system clock source */
        peripheral::regs::rcc::cfgr::sw::write(2);

        /* Wait till PLL is used as system clock source */
        while ((peripheral::regs::rcc::cfgr::sws::read()) != (uint32_t)2)
        {
        }
    }
    else
    { /* If HSE fails to start-up, the application will have wrong clock
         configuration. User can add here some code to deal with this error */
    }
}

static INLINE void systemInit()
{
    peripheral::regs::rcc::cr::hsion::set();
    
    peripheral::regs::rcc::cfgr::sw::clear();
    peripheral::regs::rcc::cfgr::hpre::write(0);
    peripheral::regs::rcc::cfgr::ppre::write(0);
    peripheral::regs::rcc::cfgr::adcpre::clear();
    peripheral::regs::rcc::cfgr::mco::clear();
    
    peripheral::regs::rcc::cr::hseon::clear();
    peripheral::regs::rcc::cr::csson::clear();
    peripheral::regs::rcc::cr::pllon::clear();
    peripheral::regs::rcc::cr::hsebyp::clear();
    
    peripheral::regs::rcc::cfgr::pllsrc::clear();
    peripheral::regs::rcc::cfgr::pllxtpre::clear();
    peripheral::regs::rcc::cfgr::pllmul::clear();
    
    peripheral::regs::rcc::cfgr2::prediv::clear();
    
    peripheral::regs::rcc::cfgr3::usart1sw::clear();
    peripheral::regs::rcc::cfgr3::usart2sw::clear();
    peripheral::regs::rcc::cfgr3::i2c1sw::clear();
    peripheral::regs::rcc::cfgr3::adcsw::clear();
    
    peripheral::regs::rcc::cr2::hsi14on::clear();
    
    peripheral::regs::rcc::cir::all::clear();
    
    setSysClock();
}



extern "C" void resetHandler()
{
  initializeData();
  
  systemInit();

  main();
}
