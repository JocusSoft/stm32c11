/*
 * File: interrupts_cpp.hpp
 * Project: stm32f0
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */


#pragma once
#ifdef STM32F0

typedef void (*pvf)();


namespace interrupt {
  __attribute__ ((section(".interrupt_vector")))
  pvf interruptVector[] = {
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
}
extern "C" void defaultInterruptHandler()
{
  while (true) {
  }
}

#pragma weak   WWDG_IRQn                    = defaultInterruptHandler
#pragma weak   PVD_VDDIO2_IRQn              = defaultInterruptHandler
#pragma weak   RTC_IRQn                     = defaultInterruptHandler
#pragma weak   FLASH_IRQn                   = defaultInterruptHandler
#pragma weak   RCC_CRS_IRQn                 = defaultInterruptHandler
#pragma weak   EXTI0_1_IRQn                 = defaultInterruptHandler
#pragma weak   EXTI2_3_IRQn                 = defaultInterruptHandler
#pragma weak   EXTI4_15_IRQn                = defaultInterruptHandler
#pragma weak   TSC_IRQn                     = defaultInterruptHandler
#pragma weak   DMA1_Ch1_IRQn                = defaultInterruptHandler
#pragma weak   DMA1_Ch2_3_DMA2_Ch1_2_IRQn   = defaultInterruptHandler
#pragma weak   DMA1_Ch4_7_DMA2_Ch3_5_IRQn   = defaultInterruptHandler
#pragma weak   ADC1_COMP_IRQn               = defaultInterruptHandler
#pragma weak   TIM1_BRK_UP_TRG_COM_IRQn     = defaultInterruptHandler
#pragma weak   TIM1_CC_IRQn                 = defaultInterruptHandler
#pragma weak   TIM2_IRQn                    = defaultInterruptHandler
#pragma weak   TIM3_IRQn                    = defaultInterruptHandler
#pragma weak   TIM6_DAC_IRQn                = defaultInterruptHandler
#pragma weak   TIM7_IRQn                    = defaultInterruptHandler
#pragma weak   TIM14_IRQn                   = defaultInterruptHandler
#pragma weak   TIM15_IRQn                   = defaultInterruptHandler
#pragma weak   TIM16_IRQn                   = defaultInterruptHandler
#pragma weak   TIM17_IRQn                   = defaultInterruptHandler
#pragma weak   I2C1_IRQn                    = defaultInterruptHandler
#pragma weak   I2C2_IRQn                    = defaultInterruptHandler
#pragma weak   SPI1_IRQn                    = defaultInterruptHandler
#pragma weak   SPI2_IRQn                    = defaultInterruptHandler
#pragma weak   USART1_IRQn                  = defaultInterruptHandler
#pragma weak   USART2_IRQn                  = defaultInterruptHandler
#pragma weak   USART3_8_IRQn                = defaultInterruptHandler
#pragma weak   CEC_CAN_IRQn                 = defaultInterruptHandler
#endif
