/*
 * File: i2c.hpp
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
        struct i2c_base_addr;

        template <>
        struct i2c_base_addr<0>
        {
           static constexpr unsigned value = 0x40005400;
        };

        template <>
        struct i2c_base_addr<1>
        {
           static constexpr unsigned value = 0x40005800;
        };

        /**
           Inter-integrated circuit
        */
        template <int which>
        struct i2c
        {
            static constexpr unsigned base_addr = i2c_base_addr<which>::value;

            /**
               Control register 1
            */
            struct cr1
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   Address match interrupt enable (slave
              only)
                */
                using addrie = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   SMBUS alert enable
                */
                using alerten = core::register_t<core::rw_regp, addr, 22, 1>;
                /**
                   Analog noise filter OFF
                */
                using anfoff = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Digital noise filter
                */
                using dnf = core::register_t<core::rw_regp, addr, 8, 4>;
                /**
                   Error interrupts enable
                */
                using errie = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   General call enable
                */
                using gcen = core::register_t<core::rw_regp, addr, 19, 1>;
                /**
                   Not acknowledge received interrupt
              enable
                */
                using nackie = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Clock stretching disable
                */
                using nostretch = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   Peripheral enable
                */
                using pe = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   PEC enable
                */
                using pecen = core::register_t<core::rw_regp, addr, 23, 1>;
                /**
                   DMA reception requests
              enable
                */
                using rxdmaen = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   RX Interrupt enable
                */
                using rxie = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Slave byte control
                */
                using sbc = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   SMBus Device Default address
              enable
                */
                using smbden = core::register_t<core::rw_regp, addr, 21, 1>;
                /**
                   SMBus Host address enable
                */
                using smbhen = core::register_t<core::rw_regp, addr, 20, 1>;
                /**
                   STOP detection Interrupt
              enable
                */
                using stopie = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Software reset
                */
                using swrst = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Transfer Complete interrupt
              enable
                */
                using tcie = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   DMA transmission requests
              enable
                */
                using txdmaen = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   TX Interrupt enable
                */
                using txie = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Wakeup from STOP enable
                */
                using wupen = core::register_t<core::rw_regp, addr, 18, 1>;
            };

            /**
               Control register 2
            */
            struct cr2
            {
                static constexpr unsigned addr = base_addr + 0x4;

                /**
                   10-bit addressing mode (master
              mode)
                */
                using add10 = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Automatic end mode (master
              mode)
                */
                using autoend = core::register_t<core::rw_regp, addr, 25, 1>;
                /**
                   10-bit address header only read
              direction (master receiver mode)
                */
                using head10r = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   NACK generation (slave
              mode)
                */
                using nack = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Number of bytes
                */
                using nbytes = core::register_t<core::rw_regp, addr, 16, 8>;
                /**
                   Packet error checking byte
                */
                using pecbyte = core::register_t<core::rw_regp, addr, 26, 1>;
                /**
                   Transfer direction (master
              mode)
                */
                using rd_wrn = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   NBYTES reload mode
                */
                using reload = core::register_t<core::rw_regp, addr, 24, 1>;
                /**
                   Slave address bit 0 (master
              mode)
                */
                using sadd0 = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Slave address bit 7:1 (master
              mode)
                */
                using sadd1 = core::register_t<core::rw_regp, addr, 1, 7>;
                /**
                   Slave address bit 9:8 (master
              mode)
                */
                using sadd8 = core::register_t<core::rw_regp, addr, 8, 2>;
                /**
                   Start generation
                */
                using start = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Stop generation (master
              mode)
                */
                using stop = core::register_t<core::rw_regp, addr, 14, 1>;
            };

            /**
               Own address register 1
            */
            struct oar1
            {
                static constexpr unsigned addr = base_addr + 0x8;

                /**
                   Own Address 1 enable
                */
                using oa1en = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Own Address 1 10-bit mode
                */
                using oa1mode = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Interface address
                */
                using oa1_0 = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Interface address
                */
                using oa1_1 = core::register_t<core::rw_regp, addr, 1, 7>;
                /**
                   Interface address
                */
                using oa1_8 = core::register_t<core::rw_regp, addr, 8, 2>;
            };

            /**
               Own address register 2
            */
            struct oar2
            {
                static constexpr unsigned addr = base_addr + 0xC;

                /**
                   Interface address
                */
                using oa2 = core::register_t<core::rw_regp, addr, 1, 7>;
                /**
                   Own Address 2 enable
                */
                using oa2en = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Own Address 2 masks
                */
                using oa2msk = core::register_t<core::rw_regp, addr, 8, 3>;
            };

            /**
               Timing register
            */
            struct timingr
            {
                static constexpr unsigned addr = base_addr + 0x10;

                /**
                   Timing prescaler
                */
                using presc = core::register_t<core::rw_regp, addr, 28, 4>;
                /**
                   Data setup time
                */
                using scldel = core::register_t<core::rw_regp, addr, 20, 4>;
                /**
                   SCL high period (master
              mode)
                */
                using sclh = core::register_t<core::rw_regp, addr, 8, 8>;
                /**
                   SCL low period (master
              mode)
                */
                using scll = core::register_t<core::rw_regp, addr, 0, 8>;
                /**
                   Data hold time
                */
                using sdadel = core::register_t<core::rw_regp, addr, 16, 4>;
            };

            /**
               Status register 1
            */
            struct timeoutr
            {
                static constexpr unsigned addr = base_addr + 0x14;

                /**
                   Extended clock timeout
              enable
                */
                using texten = core::register_t<core::rw_regp, addr, 31, 1>;
                /**
                   Idle clock timeout
              detection
                */
                using tidle = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Bus timeout A
                */
                using timeouta = core::register_t<core::rw_regp, addr, 0, 12>;
                /**
                   Bus timeout B
                */
                using timeoutb = core::register_t<core::rw_regp, addr, 16, 12>;
                /**
                   Clock timeout enable
                */
                using timouten = core::register_t<core::rw_regp, addr, 15, 1>;
            };

            /**
               Interrupt and Status register
            */
            struct isr
            {
                static constexpr unsigned addr = base_addr + 0x18;

                /**
                   Address match code (Slave
              mode)
                */
                using addcode = core::register_t<core::rw_regp, addr, 17, 7>;
                /**
                   Address matched (slave
              mode)
                */
                using addr = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   SMBus alert
                */
                using alert = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Arbitration lost
                */
                using arlo = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   Bus error
                */
                using berr = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Bus busy
                */
                using busy = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Transfer direction (Slave
              mode)
                */
                using dir = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   Not acknowledge received
              flag
                */
                using nackf = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Overrun/Underrun (slave
              mode)
                */
                using ovr = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   PEC Error in reception
                */
                using pecerr = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Receive data register not empty
              (receivers)
                */
                using rxne = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Stop detection flag
                */
                using stopf = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Transfer Complete (master
              mode)
                */
                using tc = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Transfer Complete Reload
                */
                using tcr = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Timeout or t_low detection
              flag
                */
                using timeout = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Transmit data register empty
              (transmitters)
                */
                using txe = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Transmit interrupt status
              (transmitters)
                */
                using txis = core::register_t<core::rw_regp, addr, 1, 1>;
            };

            /**
               Interrupt clear register
            */
            struct icr
            {
                static constexpr unsigned addr = base_addr + 0x1C;

                /**
                   Address Matched flag clear
                */
                using addrcf = core::register_t<core::wo_regp, addr, 3, 1>;
                /**
                   Alert flag clear
                */
                using alertcf = core::register_t<core::wo_regp, addr, 13, 1>;
                /**
                   Arbitration lost flag
              clear
                */
                using arlocf = core::register_t<core::wo_regp, addr, 9, 1>;
                /**
                   Bus error flag clear
                */
                using berrcf = core::register_t<core::wo_regp, addr, 8, 1>;
                /**
                   Not Acknowledge flag clear
                */
                using nackcf = core::register_t<core::wo_regp, addr, 4, 1>;
                /**
                   Overrun/Underrun flag
              clear
                */
                using ovrcf = core::register_t<core::wo_regp, addr, 10, 1>;
                /**
                   PEC Error flag clear
                */
                using peccf = core::register_t<core::wo_regp, addr, 11, 1>;
                /**
                   Stop detection flag clear
                */
                using stopcf = core::register_t<core::wo_regp, addr, 5, 1>;
                /**
                   Timeout detection flag
              clear
                */
                using timoutcf = core::register_t<core::wo_regp, addr, 12, 1>;
            };

            /**
               PEC register
            */
            struct pecr
            {
                static constexpr unsigned addr = base_addr + 0x20;

                /**
                   Packet error checking
              register
                */
                using pec = core::register_t<core::ro_regp, addr, 0, 8>;
            };

            /**
               Receive data register
            */
            struct rxdr
            {
                static constexpr unsigned addr = base_addr + 0x24;

                /**
                   8-bit receive data
                */
                using rxdata = core::register_t<core::ro_regp, addr, 0, 8>;
            };

            /**
               Transmit data register
            */
            struct txdr
            {
                static constexpr unsigned addr = base_addr + 0x28;

                /**
                   8-bit transmit data
                */
                using txdata = core::register_t<core::rw_regp, addr, 0, 8>;
            };

        };

    }

    namespace i2c
    {
        enum{
            I2C1,
            I2C2,
        };
    }
}
#endif
