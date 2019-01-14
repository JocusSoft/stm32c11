/*
 * File: usart.hpp
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
        struct usart_base_addr;

        template <>
        struct usart_base_addr<0>
        {
           static constexpr unsigned value = 0x40013800;
        };

        template <>
        struct usart_base_addr<1>
        {
           static constexpr unsigned value = 0x40004400;
        };

        /**
           Universal synchronous asynchronous receiver
      transmitter
        */
        template <int which>
        struct usart
        {
            static constexpr unsigned base_addr = usart_base_addr<which>::value;

            /**
               Control register 1
            */
            struct cr1
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   Character match interrupt
              enable
                */
                using cmie = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Driver Enable assertion
              time
                */
                using deat = core::register_t<core::rw_regp, addr, 21, 5>;
                /**
                   Driver Enable deassertion
              time
                */
                using dedt = core::register_t<core::rw_regp, addr, 16, 5>;
                /**
                   End of Block interrupt
              enable
                */
                using eobie = core::register_t<core::rw_regp, addr, 27, 1>;
                /**
                   IDLE interrupt enable
                */
                using idleie = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Word length
                */
                using m = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Word length
                */
                using m1 = core::register_t<core::rw_regp, addr, 28, 1>;
                /**
                   Mute mode enable
                */
                using mme = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Oversampling mode
                */
                using over8 = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Parity control enable
                */
                using pce = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   PE interrupt enable
                */
                using peie = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Parity selection
                */
                using ps = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   Receiver enable
                */
                using re = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Receiver timeout interrupt
              enable
                */
                using rtoie = core::register_t<core::rw_regp, addr, 26, 1>;
                /**
                   RXNE interrupt enable
                */
                using rxneie = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Transmission complete interrupt
              enable
                */
                using tcie = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Transmitter enable
                */
                using te = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   interrupt enable
                */
                using txeie = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   USART enable
                */
                using ue = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   USART enable in Stop mode
                */
                using uesm = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Receiver wakeup method
                */
                using wake = core::register_t<core::rw_regp, addr, 11, 1>;
            };

            /**
               Control register 2
            */
            struct cr2
            {
                static constexpr unsigned addr = base_addr + 0x4;

                /**
                   Auto baud rate enable
                */
                using abren = core::register_t<core::rw_regp, addr, 20, 1>;
                /**
                   Auto baud rate mode
                */
                using abrmod = core::register_t<core::rw_regp, addr, 21, 2>;
                /**
                   Address of the USART node
                */
                using add0 = core::register_t<core::rw_regp, addr, 24, 4>;
                /**
                   Address of the USART node
                */
                using add4 = core::register_t<core::rw_regp, addr, 28, 4>;
                /**
                   7-bit Address Detection/4-bit Address
              Detection
                */
                using addm7 = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Clock enable
                */
                using clken = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Clock phase
                */
                using cpha = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   Clock polarity
                */
                using cpol = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Binary data inversion
                */
                using datainv = core::register_t<core::rw_regp, addr, 18, 1>;
                /**
                   Last bit clock pulse
                */
                using lbcl = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   LIN break detection interrupt
              enable
                */
                using lbdie = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   LIN break detection length
                */
                using lbdl = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   LIN mode enable
                */
                using linen = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Most significant bit first
                */
                using msbfirst = core::register_t<core::rw_regp, addr, 19, 1>;
                /**
                   Receiver timeout enable
                */
                using rtoen = core::register_t<core::rw_regp, addr, 23, 1>;
                /**
                   RX pin active level
              inversion
                */
                using rxinv = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   STOP bits
                */
                using stop = core::register_t<core::rw_regp, addr, 12, 2>;
                /**
                   Swap TX/RX pins
                */
                using swap = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   TX pin active level
              inversion
                */
                using txinv = core::register_t<core::rw_regp, addr, 17, 1>;
            };

            /**
               Control register 3
            */
            struct cr3
            {
                static constexpr unsigned addr = base_addr + 0x8;

                /**
                   CTS enable
                */
                using ctse = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   CTS interrupt enable
                */
                using ctsie = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   DMA Disable on Reception
              Error
                */
                using ddre = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Driver enable mode
                */
                using dem = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Driver enable polarity
              selection
                */
                using dep = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   DMA enable receiver
                */
                using dmar = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   DMA enable transmitter
                */
                using dmat = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Error interrupt enable
                */
                using eie = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Half-duplex selection
                */
                using hdsel = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   IrDA mode enable
                */
                using iren = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   IrDA low-power
                */
                using irlp = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Smartcard NACK enable
                */
                using nack = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   One sample bit method
              enable
                */
                using onebit = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Overrun Disable
                */
                using ovrdis = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   RTS enable
                */
                using rtse = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Smartcard auto-retry count
                */
                using scarcnt = core::register_t<core::rw_regp, addr, 17, 3>;
                /**
                   Smartcard mode enable
                */
                using scen = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Wakeup from Stop mode interrupt
              enable
                */
                using wufie = core::register_t<core::rw_regp, addr, 22, 1>;
                /**
                   Wakeup from Stop mode interrupt flag
              selection
                */
                using wus = core::register_t<core::rw_regp, addr, 20, 2>;
            };

            /**
               Baud rate register
            */
            struct brr
            {
                static constexpr unsigned addr = base_addr + 0xC;

                /**
                   fraction of USARTDIV
                */
                using div_fraction = core::register_t<core::rw_regp, addr, 0, 4>;
                /**
                   mantissa of USARTDIV
                */
                using div_mantissa = core::register_t<core::rw_regp, addr, 4, 12>;
            };

            /**
               Guard time and prescaler
          register
            */
            struct gtpr
            {
                static constexpr unsigned addr = base_addr + 0x10;

                /**
                   Guard time value
                */
                using gt = core::register_t<core::rw_regp, addr, 8, 8>;
                /**
                   Prescaler value
                */
                using psc = core::register_t<core::rw_regp, addr, 0, 8>;
            };

            /**
               Receiver timeout register
            */
            struct rtor
            {
                static constexpr unsigned addr = base_addr + 0x14;

                /**
                   Block Length
                */
                using blen = core::register_t<core::rw_regp, addr, 24, 8>;
                /**
                   Receiver timeout value
                */
                using rto = core::register_t<core::rw_regp, addr, 0, 24>;
            };

            /**
               Request register
            */
            struct rqr
            {
                static constexpr unsigned addr = base_addr + 0x18;

                /**
                   Auto baud rate request
                */
                using abrrq = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Mute mode request
                */
                using mmrq = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Receive data flush request
                */
                using rxfrq = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Send break request
                */
                using sbkrq = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Transmit data flush
              request
                */
                using txfrq = core::register_t<core::rw_regp, addr, 4, 1>;
            };

            /**
               Interrupt & status
          register
            */
            struct isr
            {
                static constexpr unsigned addr = base_addr + 0x1C;

                /**
                   Auto baud rate error
                */
                using abre = core::register_t<core::ro_regp, addr, 14, 1>;
                /**
                   Auto baud rate flag
                */
                using abrf = core::register_t<core::ro_regp, addr, 15, 1>;
                /**
                   Busy flag
                */
                using busy = core::register_t<core::ro_regp, addr, 16, 1>;
                /**
                   character match flag
                */
                using cmf = core::register_t<core::ro_regp, addr, 17, 1>;
                /**
                   CTS flag
                */
                using cts = core::register_t<core::ro_regp, addr, 10, 1>;
                /**
                   CTS interrupt flag
                */
                using ctsif = core::register_t<core::ro_regp, addr, 9, 1>;
                /**
                   End of block flag
                */
                using eobf = core::register_t<core::ro_regp, addr, 12, 1>;
                /**
                   Framing error
                */
                using fe = core::register_t<core::ro_regp, addr, 1, 1>;
                /**
                   Idle line detected
                */
                using idle = core::register_t<core::ro_regp, addr, 4, 1>;
                /**
                   LIN break detection flag
                */
                using lbdf = core::register_t<core::ro_regp, addr, 8, 1>;
                /**
                   Noise detected flag
                */
                using nf = core::register_t<core::ro_regp, addr, 2, 1>;
                /**
                   Overrun error
                */
                using ore = core::register_t<core::ro_regp, addr, 3, 1>;
                /**
                   Parity error
                */
                using pe = core::register_t<core::ro_regp, addr, 0, 1>;
                /**
                   Receive enable acknowledge
              flag
                */
                using reack = core::register_t<core::ro_regp, addr, 22, 1>;
                /**
                   Receiver timeout
                */
                using rtof = core::register_t<core::ro_regp, addr, 11, 1>;
                /**
                   Receiver wakeup from Mute
              mode
                */
                using rwu = core::register_t<core::ro_regp, addr, 19, 1>;
                /**
                   Read data register not
              empty
                */
                using rxne = core::register_t<core::ro_regp, addr, 5, 1>;
                /**
                   Send break flag
                */
                using sbkf = core::register_t<core::ro_regp, addr, 18, 1>;
                /**
                   Transmission complete
                */
                using tc = core::register_t<core::ro_regp, addr, 6, 1>;
                /**
                   Transmit enable acknowledge
              flag
                */
                using teack = core::register_t<core::ro_regp, addr, 21, 1>;
                /**
                   Transmit data register
              empty
                */
                using txe = core::register_t<core::ro_regp, addr, 7, 1>;
                /**
                   Wakeup from Stop mode flag
                */
                using wuf = core::register_t<core::ro_regp, addr, 20, 1>;
            };

            /**
               Interrupt flag clear register
            */
            struct icr
            {
                static constexpr unsigned addr = base_addr + 0x20;

                /**
                   Character match clear flag
                */
                using cmcf = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   CTS clear flag
                */
                using ctscf = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   End of timeout clear flag
                */
                using eobcf = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Framing error clear flag
                */
                using fecf = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Idle line detected clear
              flag
                */
                using idlecf = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   LIN break detection clear
              flag
                */
                using lbdcf = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Noise detected clear flag
                */
                using ncf = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Overrun error clear flag
                */
                using orecf = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Parity error clear flag
                */
                using pecf = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Receiver timeout clear
              flag
                */
                using rtocf = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Transmission complete clear
              flag
                */
                using tccf = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Wakeup from Stop mode clear
              flag
                */
                using wucf = core::register_t<core::rw_regp, addr, 20, 1>;
            };

            /**
               Receive data register
            */
            static constexpr unsigned rdr_addr = base_addr + 0x24;

            using rdr = core::register_t<core::ro_regp, rdr_addr, 0, 9>;
            /**
               Transmit data register
            */
            static constexpr unsigned tdr_addr = base_addr + 0x28;

            using tdr = core::register_t<core::rw_regp, tdr_addr, 0, 9>;
        };

    }

    namespace usart
    {
        enum{
            USART1,
            USART2,
        };
    }
}
#endif
