/*
 * File: syscfg.hpp
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
           System configuration controller
        */
        struct syscfg
        {
            static constexpr unsigned base_addr = 0x40010000;

            /**
               configuration register 1
            */
            struct cfgr1
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   ADC DMA remapping bit
                */
                using adc_dma_rmp = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   I2C1 DMA request remapping
              bit
                */
                using i2c1_dma_rmp = core::register_t<core::rw_regp, addr, 27, 1>;
                /**
                   FM+ driving capability activation for
              I2C1
                */
                using i2c1_fm_plus = core::register_t<core::rw_regp, addr, 20, 1>;
                /**
                   FM+ driving capability activation for
              I2C2
                */
                using i2c2_fm_plus = core::register_t<core::rw_regp, addr, 21, 1>;
                /**
                   Fast Mode Plus (FM plus) driving
              capability activation bits.
                */
                using i2c_pb6_fm = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   Fast Mode Plus (FM+) driving capability
              activation bits.
                */
                using i2c_pb7_fm = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   Fast Mode Plus (FM+) driving capability
              activation bits.
                */
                using i2c_pb8_fm = core::register_t<core::rw_regp, addr, 18, 1>;
                /**
                   Fast Mode Plus (FM+) driving capability
              activation bits.
                */
                using i2c_pb9_fm = core::register_t<core::rw_regp, addr, 19, 1>;
                /**
                   Memory mapping selection
              bits
                */
                using mem_mode = core::register_t<core::rw_regp, addr, 0, 2>;
                /**
                   SPI2 DMA request remapping
              bit
                */
                using spi2_dma_rmp = core::register_t<core::rw_regp, addr, 24, 1>;
                /**
                   TIM16 DMA request remapping
              bit
                */
                using tim16_dma_rmp = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   TIM17 DMA request remapping
              bit
                */
                using tim17_dma_rmp = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   TIM1 DMA request remapping
              bit
                */
                using tim1_dma_rmp = core::register_t<core::rw_regp, addr, 28, 1>;
                /**
                   TIM2 DMA request remapping
              bit
                */
                using tim2_dma_rmp = core::register_t<core::rw_regp, addr, 29, 1>;
                /**
                   TIM3 DMA request remapping
              bit
                */
                using tim3_dma_rmp = core::register_t<core::rw_regp, addr, 30, 1>;
                /**
                   USART1_RX DMA request remapping
              bit
                */
                using usart1_rx_dma_rmp = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   USART1_TX DMA remapping
              bit
                */
                using usart1_tx_dma_rmp = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   USART2 DMA request remapping
              bit
                */
                using usart2_dma_rmp = core::register_t<core::rw_regp, addr, 25, 1>;
                /**
                   USART3 DMA request remapping
              bit
                */
                using usart3_dma_rmp = core::register_t<core::rw_regp, addr, 26, 1>;
            };

            /**
               external interrupt configuration register
          1
            */
            struct exticr1
            {
                static constexpr unsigned addr = base_addr + 0x8;

                /**
                   EXTI 0 configuration bits
                */
                using exti0 = core::register_t<core::rw_regp, addr, 0, 4>;
                /**
                   EXTI 1 configuration bits
                */
                using exti1 = core::register_t<core::rw_regp, addr, 4, 4>;
                /**
                   EXTI 2 configuration bits
                */
                using exti2 = core::register_t<core::rw_regp, addr, 8, 4>;
                /**
                   EXTI 3 configuration bits
                */
                using exti3 = core::register_t<core::rw_regp, addr, 12, 4>;
            };

            /**
               external interrupt configuration register
          2
            */
            struct exticr2
            {
                static constexpr unsigned addr = base_addr + 0xC;

                /**
                   EXTI 4 configuration bits
                */
                using exti4 = core::register_t<core::rw_regp, addr, 0, 4>;
                /**
                   EXTI 5 configuration bits
                */
                using exti5 = core::register_t<core::rw_regp, addr, 4, 4>;
                /**
                   EXTI 6 configuration bits
                */
                using exti6 = core::register_t<core::rw_regp, addr, 8, 4>;
                /**
                   EXTI 7 configuration bits
                */
                using exti7 = core::register_t<core::rw_regp, addr, 12, 4>;
            };

            /**
               external interrupt configuration register
          3
            */
            struct exticr3
            {
                static constexpr unsigned addr = base_addr + 0x10;

                /**
                   EXTI 10 configuration bits
                */
                using exti10 = core::register_t<core::rw_regp, addr, 8, 4>;
                /**
                   EXTI 11 configuration bits
                */
                using exti11 = core::register_t<core::rw_regp, addr, 12, 4>;
                /**
                   EXTI 8 configuration bits
                */
                using exti8 = core::register_t<core::rw_regp, addr, 0, 4>;
                /**
                   EXTI 9 configuration bits
                */
                using exti9 = core::register_t<core::rw_regp, addr, 4, 4>;
            };

            /**
               external interrupt configuration register
          4
            */
            struct exticr4
            {
                static constexpr unsigned addr = base_addr + 0x14;

                /**
                   EXTI 12 configuration bits
                */
                using exti12 = core::register_t<core::rw_regp, addr, 0, 4>;
                /**
                   EXTI 13 configuration bits
                */
                using exti13 = core::register_t<core::rw_regp, addr, 4, 4>;
                /**
                   EXTI 14 configuration bits
                */
                using exti14 = core::register_t<core::rw_regp, addr, 8, 4>;
                /**
                   EXTI 15 configuration bits
                */
                using exti15 = core::register_t<core::rw_regp, addr, 12, 4>;
            };

            /**
               configuration register 2
            */
            struct cfgr2
            {
                static constexpr unsigned addr = base_addr + 0x18;

                /**
                   Cortex-M0 LOCKUP bit enable
              bit
                */
                using locup_lock = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   PVD lock enable bit
                */
                using pvd_lock = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   SRAM parity lock bit
                */
                using sram_parity_lock = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   SRAM parity flag
                */
                using sram_pef = core::register_t<core::rw_regp, addr, 8, 1>;
            };

        };

    }

    namespace syscfg
    {
    }
}
#endif
