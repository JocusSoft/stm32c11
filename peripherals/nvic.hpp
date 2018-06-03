/*
 * File: nvic.hpp
 * Project: peripherals
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */


#pragma once

#include <inttypes.h>

#include "peripherals/device_select.hpp"

#ifndef INLINE
#define INLINE __attribute__((__always_inline__)) inline
#endif

namespace nvic
{
    enum irqn
    {
        WWDG_IRQn                   , // 0   Window WatchDog Interrupt                                    
        PVD_VDDIO2_IRQn             , // 1   PVD & VDDIO2 Interrupts through EXTI Lines 16 and 31         
        RTC_IRQn                    , // 2   RTC Interrupt through EXTI Lines 17 19 and 20               
        FLASH_IRQn                  , // 3   FLASH global Interrupt                                       
        RCC_CRS_IRQn                , // 4   RCC & CRS global Interrupts                                  
        EXTI0_1_IRQn                , // 5   EXTI Line 0 and 1 Interrupts                                 
        EXTI2_3_IRQn                , // 6   EXTI Line 2 and 3 Interrupts                                 
        EXTI4_15_IRQn               , // 7   EXTI Line 4 to 15 Interrupts                                 
        TSC_IRQn                    , // 8   Touch Sensing Controller Interrupts                          
        DMA1_Ch1_IRQn               , // 9   DMA1 Channel 1 Interrupt                                     
        DMA1_Ch2_3_DMA2_Ch1_2_IRQn  , // 10  DMA1 Channel 2 and 3 & DMA2 Channel 1 and 2 Interrupts       
        DMA1_Ch4_7_DMA2_Ch3_5_IRQn  , // 11  DMA1 Channel 4 to 7 & DMA2 Channel 3 to 5 Interrupts         
        ADC1_COMP_IRQn               , // 12  ADC COMP1 and COMP2 Interrupts (EXTI Lines 21 and 22)      
        TIM1_BRK_UP_TRG_COM_IRQn    , // 13  TIM1 Break Update Trigger and Commutation Interrupts       
        TIM1_CC_IRQn                , // 14  TIM1 Capture Compare Interrupt                               
        TIM2_IRQn                   , // 15  TIM2 global Interrupt                                        
        TIM3_IRQn                   , // 16  TIM3 global Interrupt                                        
        TIM6_DAC_IRQn               , // 17  TIM6 global and DAC channel underrun error Interrupts        
        TIM7_IRQn                   , // 18  TIM7 global Interrupt                                        
        TIM14_IRQn                  , // 19  TIM14 global Interrupt                                       
        TIM15_IRQn                  , // 20  TIM15 global Interrupt                                       
        TIM16_IRQn                  , // 21  TIM16 global Interrupt                                       
        TIM17_IRQn                  , // 22  TIM17 global Interrupt                                       
        I2C1_IRQn                   , // 23  I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)   
        I2C2_IRQn                   , // 24  I2C2 Event Interrupt                                         
        SPI1_IRQn                   , // 25  SPI1 global Interrupt                                        
        SPI2_IRQn                   , // 26  SPI2 global Interrupt                                        
        USART1_IRQn                 , // 27  USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
        USART2_IRQn                 , // 28  USART2 global Interrupt & EXTI Line26 Interrupt (USART2 wakeup) */
        USART3_8_IRQn               , // 29  USART3 to USART8 global Interrupts                           
        CEC_CAN_IRQn                , // 30   CEC and CAN global Interrupts & EXTI Line27 Interrupt
    };
    
    template<uint8_t irq_n>
    struct irq
    {
        
        INLINE static void enable()
        {
            peripheral::regs::nvic::iser<irq_n>::setena::set();
        }
        
        INLINE static void disable()
        {
            peripheral::regs::nvic::icer<irq_n>::clrena::set();
        }
        
        INLINE static void prioritet(uint8_t prio)
        {
            peripheral::regs::nvic::ipr<irq_n>::pri::write(prio);
        }
    };
}

