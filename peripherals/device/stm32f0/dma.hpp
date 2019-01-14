/*
 * File: dma.hpp
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
        template <int which>
        struct dma_channel_base_addr;

        template <>
        struct dma_channel_base_addr<0>
        {
           static constexpr unsigned value = address::AHB + 0x8;
        };
        template <>
        struct dma_channel_base_addr<1>
        {
           static constexpr unsigned value = address::AHB + 0x1C;
        };
        template <>
        struct dma_channel_base_addr<2>
        {
           static constexpr unsigned value = address::AHB + 0x30;
        };
        template <>
        struct dma_channel_base_addr<3>
        {
           static constexpr unsigned value = address::AHB + 0x44;
        };
        template <>
        struct dma_channel_base_addr<4>
        {
           static constexpr unsigned value = address::AHB + 0x58;
        };
        template <>
        struct dma_channel_base_addr<5>
        {
           static constexpr unsigned value = address::AHB + 0x6C;
        };
        template <>
        struct dma_channel_base_addr<6>
        {
           static constexpr unsigned value = address::AHB + 0x80;
        };
        
        template <int which>
        struct dma_base_addr;

        template <>
        struct dma_base_addr<0>
        {
           static constexpr unsigned value = address::AHB + 0x0;
        };
        /**
           DMA controller
        */
        template<int which>
        struct dma
        {
            static constexpr unsigned base_addr = dma_base_addr<which>::value;

            /**
               DMA interrupt status register (DMA_ISR)
            */
            struct isr
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   Channel y Global interrupt flag
                */
                template<int y>
                using gif = core::register_t<core::ro_regp, addr, y*4, 1>;
                
                /**
                   Channel y Half Transfer Complete flag
                */
                template<int y>
                using htif = core::register_t<core::ro_regp, addr, y*4+2, 1>;
                /**
                   Channel y Transfer Complete              flag
                */
                template<int y>
                using tcif = core::register_t<core::ro_regp, addr, y*4+1, 1>;
                
                /**
                   Channel y Transfer Error              flag
                */
                template<int y>
                using teif = core::register_t<core::ro_regp, addr, y*4+3, 1>;
                
            };

            /**
               DMA interrupt flag clear register
          (DMA_IFCR)
            */
            struct ifcr
            {
                static constexpr unsigned addr = base_addr + 0x4;

                /**
                   Channel 1 Global interrupt clear
                */
                template<int y>
                using cgif = core::register_t<core::wo_regp, addr, y*4, 1>;

                /**
                   Channel 1 Half Transfer clear
                */
                template<int y>
                using chtif = core::register_t<core::wo_regp, addr, y*4+2, 1>;
                
                /**
                   Channel 1 Transfer Complete clear
                */
                template<int y>
                using ctcif = core::register_t<core::wo_regp, addr, y*4+1, 1>;

                /**
                   Channel 1 Transfer Error clear
                */
                template<int y>
                using cteif = core::register_t<core::wo_regp, addr, y*4+3, 1>;
            };

            /**
               DMA channel configuration register(DMA_CCR)
            */
            template<int channel>
            struct ccr
            {
                static constexpr unsigned addr = dma_channel_base_addr<channel>::value;

                /**
                   Circular mode
                */
                using circ = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Data transfer direction
                */
                using dir = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Channel enable
                */
                using en = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Half Transfer interrupt
              enable
                */
                using htie = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Memory to memory mode
                */
                using mem2mem = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Memory increment mode
                */
                using minc = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Memory size
                */
                using msize = core::register_t<core::rw_regp, addr, 10, 2>;
                /**
                   Peripheral increment mode
                */
                using pinc = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Channel Priority level
                */
                using pl = core::register_t<core::rw_regp, addr, 12, 2>;
                /**
                   Peripheral size
                */
                using psize = core::register_t<core::rw_regp, addr, 8, 2>;
                /**
                   Transfer complete interrupt
              enable
                */
                using tcie = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Transfer error interrupt
              enable
                */
                using teie = core::register_t<core::rw_regp, addr, 3, 1>;
            };

            /**
               DMA channel y number of data register
            */
            template<int channel>
            struct cndtr
            {
                static constexpr unsigned addr = dma_channel_base_addr<channel>::value + 0x4;

                /**
                   Number of data to transfer
                */
                using ndt = core::register_t<core::rw_regp, addr, 0, 16>;
            };

            /**
               DMA channel 1 peripheral address  register
            */
            template<int channel>
            struct cpar
            {
                static constexpr unsigned addr = dma_channel_base_addr<channel>::value + 0x8;

                /**
                   Peripheral address
                */
                using pa = core::register_t<core::rw_regp, addr, 0, 32>;
            };

            /**
               DMA channel y memory address register
            */
            template<int channel>
            struct cmar
            {
                static constexpr unsigned addr = dma_channel_base_addr<channel>::value + 0xC;

                /**
                   Memory address
                */
                using ma = core::register_t<core::rw_regp, addr, 0, 32>;
            };

        };

    }

    namespace dma
    {
        enum{
            DMA1
        };
        enum {
            DMA_CH_1,
            DMA_CH_2,
            DMA_CH_3,
            DMA_CH_4,
            DMA_CH_5,
            DMA_CH_6,
            DMA_CH_7
        };
    }
}
#endif
