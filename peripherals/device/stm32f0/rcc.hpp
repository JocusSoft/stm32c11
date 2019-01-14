/*
 * File: rcc.hpp
 * Project: stm32f0
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */


#pragma once

#ifdef STM32F0

#include "core/register.h"

namespace peripheral
{
    namespace regs
    {
        /**
           Reset and clock control
        */
        struct rcc
        {
            static constexpr unsigned base_addr = 0x40021000;

            /**
               Clock control register
            */
            struct cr
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   Clock Security System enable
                */
                using csson = core::register_t<core::rw_regp, addr, 19, 1>;
                /**
                   External High Speed clock Bypass
                */
                using hsebyp = core::register_t<core::rw_regp, addr, 18, 1>;
                /**
                   External High Speed clock enable
                */
                using hseon = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   External High Speed clock ready flag
                */
                using hserdy = core::register_t<core::ro_regp, addr, 17, 1>;
                /**
                   Internal High Speed clock Calibration
                */
                using hsical = core::register_t<core::ro_regp, addr, 8, 8>;
                /**
                   Internal High Speed clock  enable
                */
                using hsion = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Internal High Speed clock ready flag
                */
                using hsirdy = core::register_t<core::ro_regp, addr, 1, 1>;
                /**
                   Internal High Speed clock trimming
                */
                using hsitrim = core::register_t<core::rw_regp, addr, 3, 5>;
                /**
                   PLL enable
                */
                using pllon = core::register_t<core::rw_regp, addr, 24, 1>;
                /**
                   PLL clock ready flag
                */
                using pllrdy = core::register_t<core::ro_regp, addr, 25, 1>;
            };

            /**
               Clock configuration register (RCC_CFGR)
            */
            struct cfgr
            {
                static constexpr unsigned addr = base_addr + 0x4;

                /**
                   ADC prescaler
                */
                using adcpre = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   AHB prescaler
                */
                using hpre = core::register_t<core::rw_regp, addr, 4, 4>;
                /**
                   Microcontroller clock
              output
                */
                using mco = core::register_t<core::rw_regp, addr, 24, 3>;
                /**
                   Microcontroller Clock Output
              Prescaler
                */
                using mcopre = core::register_t<core::rw_regp, addr, 28, 3>;
                /**
                   PLL Multiplication Factor
                */
                using pllmul = core::register_t<core::rw_regp, addr, 18, 4>;
                /**
                   PLL clock not divided for
              MCO
                */
                using pllnodiv = core::register_t<core::rw_regp, addr, 31, 1>;
                /**
                   PLL input clock source
                */
                using pllsrc = core::register_t<core::rw_regp, addr, 15, 2>;
                /**
                   HSE divider for PLL entry
                */
                using pllxtpre = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   APB Low speed prescaler
              (APB1)
                */
                using ppre = core::register_t<core::rw_regp, addr, 8, 3>;
                /**
                   System clock Switch
                */
                using sw = core::register_t<core::rw_regp, addr, 0, 2>;
                /**
                   System Clock Switch Status
                */
                using sws = core::register_t<core::rw_regp, addr, 2, 2>;
            };

            /**
               Clock interrupt register (RCC_CIR)
            */
            struct cir
            {
                static constexpr unsigned addr = base_addr + 0x8;

                /**
                   Clock security system interrupt
              clear
                */
                using cssc = core::register_t<core::rw_regp, addr, 23, 1>;
                /**
                   Clock Security System Interrupt
              flag
                */
                using cssf = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   HSE Ready Interrupt Clear
                */
                using hserdyc = core::register_t<core::rw_regp, addr, 19, 1>;
                /**
                   HSE Ready Interrupt flag
                */
                using hserdyf = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   HSE Ready Interrupt Enable
                */
                using hserdyie = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   HSI 14 MHz Ready Interrupt
              Clear
                */
                using hsi14rdyc = core::register_t<core::rw_regp, addr, 21, 1>;
                /**
                   HSI14 ready interrupt
              enable
                */
                using hsi14rdye = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   HSI14 ready interrupt flag
                */
                using hsi14rdyf = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   HSI48 Ready Interrupt
              Clear
                */
                using hsi48rdyc = core::register_t<core::rw_regp, addr, 22, 1>;
                /**
                   HSI48 ready interrupt flag
                */
                using hsi48rdyf = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   HSI48 ready interrupt
              enable
                */
                using hsi48rdyie = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   HSI Ready Interrupt Clear
                */
                using hsirdyc = core::register_t<core::rw_regp, addr, 18, 1>;
                /**
                   HSI Ready Interrupt flag
                */
                using hsirdyf = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   HSI Ready Interrupt Enable
                */
                using hsirdyie = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   LSE Ready Interrupt Clear
                */
                using lserdyc = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   LSE Ready Interrupt flag
                */
                using lserdyf = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   LSE Ready Interrupt Enable
                */
                using lserdyie = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   LSI Ready Interrupt Clear
                */
                using lsirdyc = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   LSI Ready Interrupt flag
                */
                using lsirdyf = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   LSI Ready Interrupt Enable
                */
                using lsirdyie = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   PLL Ready Interrupt Clear
                */
                using pllrdyc = core::register_t<core::rw_regp, addr, 20, 1>;
                /**
                   PLL Ready Interrupt flag
                */
                using pllrdyf = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   PLL Ready Interrupt Enable
                */
                using pllrdyie = core::register_t<core::rw_regp, addr, 12, 1>;
                
                using all = core::register_t<core::rw_regp, addr, 0, 32>;
            };

            /**
               APB2 peripheral reset register (RCC_APB2RSTR)
            */
            struct apb2rstr
            {
                static constexpr unsigned addr = base_addr + 0xC;

                /**
                   ADC interface reset
                */
                using adcrst = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   Debug MCU reset
                */
                using dbgmcurst = core::register_t<core::rw_regp, addr, 22, 1>;
                /**
                   SPI 1 reset
                */
                using spi1rst = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   SYSCFG and COMP reset
                */
                using syscfgrst = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   TIM15 timer reset
                */
                using tim15rst = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   TIM16 timer reset
                */
                using tim16rst = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   TIM17 timer reset
                */
                using tim17rst = core::register_t<core::rw_regp, addr, 18, 1>;
                /**
                   TIM1 timer reset
                */
                using tim1rst = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   USART1 reset
                */
                using usart1rst = core::register_t<core::rw_regp, addr, 14, 1>;
            };

            /**
               APB1 peripheral reset register
          (RCC_APB1RSTR)
            */
            struct apb1rstr
            {
                static constexpr unsigned addr = base_addr + 0x10;

                /**
                   I2C1 reset
                */
                using i2c1rst = core::register_t<core::rw_regp, addr, 21, 1>;
                /**
                   I2C2 reset
                */
                using i2c2rst = core::register_t<core::rw_regp, addr, 22, 1>;
                /**
                   Power interface reset
                */
                using pwrrst = core::register_t<core::rw_regp, addr, 28, 1>;
                /**
                   SPI2 reset
                */
                using spi2rst = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Timer 14 reset
                */
                using tim14rst = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Timer 3 reset
                */
                using tim3rst = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Timer 6 reset
                */
                using tim6rst = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   USART 2 reset
                */
                using usart2rst = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   Window watchdog reset
                */
                using wwdgrst = core::register_t<core::rw_regp, addr, 11, 1>;
            };

            /**
               AHB Peripheral Clock enable register
          (RCC_AHBENR)
            */
            struct ahbenr
            {
                static constexpr unsigned addr = base_addr + 0x14;

                /**
                   CRC clock enable
                */
                using crcen = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   DMA1 clock enable
                */
                using dmaen = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   FLITF clock enable
                */
                using flitfen = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   I/O port clock enable
                */
                template<int port>
                using iopen = core::register_t<core::rw_regp, addr, 17+port, 1>;
                /**
                   SRAM interface clock enable
                */
                using sramen = core::register_t<core::rw_regp, addr, 2, 1>;
            };

            /**
               APB2 peripheral clock enable register (RCC_APB2ENR)
            */
            struct apb2enr
            {
                static constexpr unsigned addr = base_addr + 0x18;

                /**
                   ADC 1 interface clock
              enable
                */
                using adcen = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   MCU debug module clock
              enable
                */
                using dbgmcuen = core::register_t<core::rw_regp, addr, 22, 1>;
                /**
                   SPI 1 clock enable
                */
                using spi1en = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   SYSCFG clock enable
                */
                using syscfgen = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   TIM15 timer clock enable
                */
                using tim15en = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   TIM16 timer clock enable
                */
                using tim16en = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   TIM17 timer clock enable
                */
                using tim17en = core::register_t<core::rw_regp, addr, 18, 1>;
                /**
                   TIM1 Timer clock enable
                */
                using tim1en = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   USART1 clock enable
                */
                using usart1en = core::register_t<core::rw_regp, addr, 14, 1>;
            };

            /**
               APB1 peripheral clock enable register
          (RCC_APB1ENR)
            */
            struct apb1enr
            {
                static constexpr unsigned addr = base_addr + 0x1C;

                /**
                   I2C 1 clock enable
                */
                using i2c1en = core::register_t<core::rw_regp, addr, 21, 1>;
                /**
                   I2C 2 clock enable
                */
                using i2c2en = core::register_t<core::rw_regp, addr, 22, 1>;
                /**
                   Power interface clock
              enable
                */
                using pwren = core::register_t<core::rw_regp, addr, 28, 1>;
                /**
                   SPI 2 clock enable
                */
                using spi2en = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Timer 14 clock enable
                */
                using tim14en = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Timer 3 clock enable
                */
                using tim3en = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Timer 6 clock enable
                */
                using tim6en = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   USART 2 clock enable
                */
                using usart2en = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   Window watchdog clock
              enable
                */
                using wwdgen = core::register_t<core::rw_regp, addr, 11, 1>;
            };

            /**
               Backup domain control register
          (RCC_BDCR)
            */
            struct bdcr
            {
                static constexpr unsigned addr = base_addr + 0x20;

                /**
                   Backup domain software
              reset
                */
                using bdrst = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   External Low Speed oscillator
              bypass
                */
                using lsebyp = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   LSE oscillator drive
              capability
                */
                using lsedrv = core::register_t<core::rw_regp, addr, 3, 2>;
                /**
                   External Low Speed oscillator
              enable
                */
                using lseon = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   External Low Speed oscillator
              ready
                */
                using lserdy = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   RTC clock enable
                */
                using rtcen = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   RTC clock source selection
                */
                using rtcsel = core::register_t<core::rw_regp, addr, 8, 2>;
            };

            /**
               Control/status register
          (RCC_CSR)
            */
            struct csr
            {
                static constexpr unsigned addr = base_addr + 0x24;

                /**
                   Independent watchdog reset
              flag
                */
                using iwdgrstf = core::register_t<core::rw_regp, addr, 29, 1>;
                /**
                   Low-power reset flag
                */
                using lpwrrstf = core::register_t<core::rw_regp, addr, 31, 1>;
                /**
                   Internal low speed oscillator
              enable
                */
                using lsion = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Internal low speed oscillator
              ready
                */
                using lsirdy = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Option byte loader reset
              flag
                */
                using oblrstf = core::register_t<core::rw_regp, addr, 25, 1>;
                /**
                   PIN reset flag
                */
                using pinrstf = core::register_t<core::rw_regp, addr, 26, 1>;
                /**
                   POR/PDR reset flag
                */
                using porrstf = core::register_t<core::rw_regp, addr, 27, 1>;
                /**
                   Remove reset flag
                */
                using rmvf = core::register_t<core::rw_regp, addr, 24, 1>;
                /**
                   Software reset flag
                */
                using sftrstf = core::register_t<core::rw_regp, addr, 28, 1>;
                /**
                   Window watchdog reset flag
                */
                using wwdgrstf = core::register_t<core::rw_regp, addr, 30, 1>;
            };

            /**
               AHB peripheral reset register
            */
            struct ahbrstr
            {
                static constexpr unsigned addr = base_addr + 0x28;

                /**
                   I/O port reset
                */
                template<int port>
                using ioprst = core::register_t<core::rw_regp, addr, 17+port, 1>;
            };

            /**
               Clock configuration register 2
            */
            struct cfgr2
            {
                static constexpr unsigned addr = base_addr + 0x2C;

                /**
                   PREDIV division factor
                */
                using prediv = core::register_t<core::rw_regp, addr, 0, 4>;
            };

            /**
               Clock configuration register 3
            */
            struct cfgr3
            {
                static constexpr unsigned addr = base_addr + 0x30;

                /**
                   ADC clock source selection
                */
                using adcsw = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   I2C1 clock source
              selection
                */
                using i2c1sw = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   USART1 clock source
              selection
                */
                using usart1sw = core::register_t<core::rw_regp, addr, 0, 2>;
                /**
                   USART2 clock source
              selection
                */
                using usart2sw = core::register_t<core::rw_regp, addr, 16, 2>;
            };

            /**
               Clock control register 2
            */
            struct cr2
            {
                static constexpr unsigned addr = base_addr + 0x34;

                /**
                   HSI14 clock calibration
                */
                using hsi14cal = core::register_t<core::rw_regp, addr, 8, 8>;
                /**
                   HSI14 clock request from ADC
              disable
                */
                using hsi14dis = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   HSI14 clock enable
                */
                using hsi14on = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   HR14 clock ready flag
                */
                using hsi14rdy = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   HSI14 clock trimming
                */
                using hsi14trim = core::register_t<core::rw_regp, addr, 3, 5>;
                /**
                   HSI48 factory clock
              calibration
                */
                using hsi48cal = core::register_t<core::rw_regp, addr, 24, 1>;
                /**
                   HSI48 clock enable
                */
                using hsi48on = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   HSI48 clock ready flag
                */
                using hsi48rdy = core::register_t<core::rw_regp, addr, 17, 1>;
            };

        };

    }

    namespace rcc
    {
    }
}
#endif
