/*
 * File: spi.hpp
 * Project: stm32f0
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */


#pragma once

#ifdef stm32f0xx

#include "core/register.h"

namespace peripheral
{
    namespace regs
    {
        template <int which>
        struct spi_base_addr;

        template <>
        struct spi_base_addr<0>
        {
           static constexpr unsigned value = 0x40013000;
        };

        template <>
        struct spi_base_addr<1>
        {
           static constexpr unsigned value = 0x40003800;
        };

        /**
           Serial peripheral interface
        */
        template <int which>
        struct spi
        {
            static constexpr unsigned base_addr = spi_base_addr<which>::value;

            /**
               control register 1
            */
            struct cr1
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   Bidirectional data mode
              enable
                */
                using bidimode = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Output enable in bidirectional
              mode
                */
                using bidioe = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Baud rate control
                */
                using br = core::register_t<core::rw_regp, addr, 3, 3>;
                /**
                   Clock phase
                */
                using cpha = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Clock polarity
                */
                using cpol = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Hardware CRC calculation
              enable
                */
                using crcen = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   CRC transfer next
                */
                using crcnext = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Data frame format
                */
                using dff = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Frame format
                */
                using lsbfirst = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Master selection
                */
                using mstr = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Receive only
                */
                using rxonly = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   SPI enable
                */
                using spe = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Internal slave select
                */
                using ssi = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Software slave management
                */
                using ssm = core::register_t<core::rw_regp, addr, 9, 1>;
            };

            /**
               control register 2
            */
            struct cr2
            {
                static constexpr unsigned addr = base_addr + 0x4;

                /**
                   Data size
                */
                using ds = core::register_t<core::rw_regp, addr, 8, 4>;
                /**
                   Error interrupt enable
                */
                using errie = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Frame format
                */
                using frf = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   FIFO reception threshold
                */
                using frxth = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Last DMA transfer for
              reception
                */
                using ldma_rx = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Last DMA transfer for
              transmission
                */
                using ldma_tx = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   NSS pulse management
                */
                using nssp = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Rx buffer DMA enable
                */
                using rxdmaen = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   RX buffer not empty interrupt
              enable
                */
                using rxneie = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   SS output enable
                */
                using ssoe = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Tx buffer DMA enable
                */
                using txdmaen = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Tx buffer empty interrupt
              enable
                */
                using txeie = core::register_t<core::rw_regp, addr, 7, 1>;
            };

            /**
               status register
            */
            struct sr
            {
                static constexpr unsigned addr = base_addr + 0x8;

                /**
                   Busy flag
                */
                using bsy = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Channel side
                */
                using chside = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   CRC error flag
                */
                using crcerr = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   FIFO reception level
                */
                using frlvl = core::register_t<core::rw_regp, addr, 9, 2>;
                /**
                   FIFO transmission level
                */
                using ftlvl = core::register_t<core::rw_regp, addr, 11, 2>;
                /**
                   Mode fault
                */
                using modf = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Overrun flag
                */
                using ovr = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Receive buffer not empty
                */
                using rxne = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   TI frame format error
                */
                using tifrfe = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Transmit buffer empty
                */
                using txe = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Underrun flag
                */
                using udr = core::register_t<core::rw_regp, addr, 3, 1>;
            };

            /**
               data register
            */
            static constexpr unsigned dr_addr = base_addr + 0xC;

            using dr = core::register_t<core::rw_regp, dr_addr, 0, 16>;
            /**
               CRC polynomial register
            */
            struct crcpr
            {
                static constexpr unsigned addr = base_addr + 0x10;

                /**
                   CRC polynomial register
                */
                using crcpoly = core::register_t<core::rw_regp, addr, 0, 16>;
            };

            /**
               RX CRC register
            */
            struct rxcrcr
            {
                static constexpr unsigned addr = base_addr + 0x14;

                /**
                   Rx CRC register
                */
                using rxcrc = core::register_t<core::ro_regp, addr, 0, 16>;
            };

            /**
               TX CRC register
            */
            struct txcrcr
            {
                static constexpr unsigned addr = base_addr + 0x18;

                /**
                   Tx CRC register
                */
                using txcrc = core::register_t<core::ro_regp, addr, 0, 16>;
            };

            /**
               I2S configuration register
            */
            struct i2scfgr
            {
                static constexpr unsigned addr = base_addr + 0x1C;

                /**
                   Channel length (number of bits per audio
              channel)
                */
                using chlen = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Steady state clock
              polarity
                */
                using ckpol = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Data length to be
              transferred
                */
                using datlen = core::register_t<core::rw_regp, addr, 1, 2>;
                /**
                   I2S configuration mode
                */
                using i2scfg = core::register_t<core::rw_regp, addr, 8, 2>;
                /**
                   I2S Enable
                */
                using i2se = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   I2S mode selection
                */
                using i2smod = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   I2S standard selection
                */
                using i2sstd = core::register_t<core::rw_regp, addr, 4, 2>;
                /**
                   PCM frame synchronization
                */
                using pcmsync = core::register_t<core::rw_regp, addr, 7, 1>;
            };

            /**
               I2S prescaler register
            */
            struct i2spr
            {
                static constexpr unsigned addr = base_addr + 0x20;

                /**
                   I2S Linear prescaler
                */
                using i2sdiv = core::register_t<core::rw_regp, addr, 0, 8>;
                /**
                   Master clock output enable
                */
                using mckoe = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   Odd factor for the
              prescaler
                */
                using odd = core::register_t<core::rw_regp, addr, 8, 1>;
            };

        };

    }

    namespace spi
    {
        enum{
            SPI1,
            SPI2,
        };
    }
}
#endif
