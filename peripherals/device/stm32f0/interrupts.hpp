/*
 * File: interrupts.hpp
 * Project: stm32f0
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */


#pragma once

#ifdef stm32f0xx

namespace interrupt {
  extern "C" {
     void   WWDG_IRQn                   ();
     void   PVD_VDDIO2_IRQn             ();
     void   RTC_IRQn                    ();
     void   FLASH_IRQn                  ();
     void   RCC_CRS_IRQn                ();
     void   EXTI0_1_IRQn                ();
     void   EXTI2_3_IRQn                ();
     void   EXTI4_15_IRQn               ();
     void   TSC_IRQn                    ();
     void   DMA1_Ch1_IRQn               ();
     void   DMA1_Ch2_3_DMA2_Ch1_2_IRQn  ();
     void   DMA1_Ch4_7_DMA2_Ch3_5_IRQn  ();
     void   ADC1_COMP_IRQn               ();
     void   TIM1_BRK_UP_TRG_COM_IRQn    ();
     void   TIM1_CC_IRQn                ();
     void   TIM2_IRQn                   ();
     void   TIM3_IRQn                   ();
     void   TIM6_DAC_IRQn               ();
     void   TIM7_IRQn                   ();
     void   TIM14_IRQn                  ();
     void   TIM15_IRQn                  ();
     void   TIM16_IRQn                  ();
     void   TIM17_IRQn                  ();
     void   I2C1_IRQn                   ();
     void   I2C2_IRQn                   ();
     void   SPI1_IRQn                   ();
     void   SPI2_IRQn                   ();
     void   USART1_IRQn                 ();
     void   USART2_IRQn                 ();
     void   USART3_8_IRQn               ();
     void   CEC_CAN_IRQn                ();
  }
}
#endif
