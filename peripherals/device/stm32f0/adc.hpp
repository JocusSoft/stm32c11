/*
 * File: adc.hpp
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
        /**
           Analog-to-digital converter
        */
        struct adc
        {
            static constexpr unsigned base_addr = 0x40012400;

            /**
               interrupt and status register
            */
            struct isr
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   ADC ready
                */
                using adrdy = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Analog watchdog flag
                */
                using awd = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   End of conversion flag
                */
                using eoc = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   End of sequence flag
                */
                using eos = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   End of sampling flag
                */
                using eosmp = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   ADC overrun
                */
                using ovr = core::register_t<core::rw_regp, addr, 4, 1>;
            };

            /**
               interrupt enable register
            */
            struct ier
            {
                static constexpr unsigned addr = base_addr + 0x4;

                /**
                   ADC ready interrupt enable
                */
                using adrdyie = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Analog watchdog interrupt
              enable
                */
                using awdie = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   End of conversion interrupt
              enable
                */
                using eocie = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   End of conversion sequence interrupt
              enable
                */
                using eosie = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   End of sampling flag interrupt
              enable
                */
                using eosmpie = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Overrun interrupt enable
                */
                using ovrie = core::register_t<core::rw_regp, addr, 4, 1>;
            };

            /**
               control register
            */
            struct cr
            {
                static constexpr unsigned addr = base_addr + 0x8;

                /**
                   ADC calibration
                */
                using adcal = core::register_t<core::rw_regp, addr, 31, 1>;
                /**
                   ADC disable command
                */
                using addis = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   ADC enable command
                */
                using aden = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   ADC start conversion
              command
                */
                using adstart = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   ADC stop conversion
              command
                */
                using adstp = core::register_t<core::rw_regp, addr, 4, 1>;
            };

            /**
               configuration register 1
            */
            struct cfgr1
            {
                static constexpr unsigned addr = base_addr + 0xC;

                /**
                   Data alignment
                */
                using align = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Auto-delayed conversion
              mode
                */
                using autdly = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Auto-off mode
                */
                using autoff = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Analog watchdog channel
              selection
                */
                using awdch = core::register_t<core::rw_regp, addr, 26, 5>;
                /**
                   Analog watchdog enable
                */
                using awden = core::register_t<core::rw_regp, addr, 23, 1>;
                /**
                   Enable the watchdog on a single channel
              or on all channels
                */
                using awdsgl = core::register_t<core::rw_regp, addr, 22, 1>;
                /**
                   Single / continuous conversion
              mode
                */
                using cont = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Discontinuous mode
                */
                using discen = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   Direct memery access
              configuration
                */
                using dmacfg = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Direct memory access
              enable
                */
                using dmaen = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   External trigger enable and polarity
              selection
                */
                using exten = core::register_t<core::rw_regp, addr, 10, 2>;
                /**
                   External trigger selection
                */
                using extsel = core::register_t<core::rw_regp, addr, 6, 3>;
                /**
                   Overrun management mode
                */
                using ovrmod = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Data resolution
                */
                using res = core::register_t<core::rw_regp, addr, 3, 2>;
                /**
                   Scan sequence direction
                */
                using scandir = core::register_t<core::rw_regp, addr, 2, 1>;
            };

            /**
               configuration register 2
            */
            struct cfgr2
            {
                static constexpr unsigned addr = base_addr + 0x10;

                /**
                 Clock
                */
                using clockmd = core::register_t<core::rw_regp, addr, 30, 2>;
            };

            /**
               sampling time register
            */
            static constexpr unsigned smpr_addr = base_addr + 0x14;

            using smpr = core::register_t<core::rw_regp, smpr_addr, 0, 3>;
            /**
               watchdog threshold register
            */
            struct tr
            {
                static constexpr unsigned addr = base_addr + 0x20;

                /**
                   Analog watchdog higher
              threshold
                */
                using ht = core::register_t<core::rw_regp, addr, 16, 12>;
                /**
                   Analog watchdog lower
              threshold
                */
                using lt = core::register_t<core::rw_regp, addr, 0, 12>;
            };

            /**
               channel selection register
            */
            struct chselr
            {
                static constexpr unsigned addr = base_addr + 0x28;

                /**
                   Channel-x selection
                */
                using chsel0 = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Channel-x selection
                */
                using chsel1 = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Channel-x selection
                */
                using chsel10 = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Channel-x selection
                */
                using chsel11 = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Channel-x selection
                */
                using chsel12 = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Channel-x selection
                */
                using chsel13 = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Channel-x selection
                */
                using chsel14 = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Channel-x selection
                */
                using chsel15 = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Channel-x selection
                */
                using chsel16 = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   Channel-x selection
                */
                using chsel17 = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   Channel-x selection
                */
                using chsel18 = core::register_t<core::rw_regp, addr, 18, 1>;
                /**
                   Channel-x selection
                */
                using chsel2 = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Channel-x selection
                */
                using chsel3 = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Channel-x selection
                */
                using chsel4 = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Channel-x selection
                */
                using chsel5 = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Channel-x selection
                */
                using chsel6 = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Channel-x selection
                */
                using chsel7 = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Channel-x selection
                */
                using chsel8 = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Channel-x selection
                */
                using chsel9 = core::register_t<core::rw_regp, addr, 9, 1>;
            };

            /**
               data register
            */
            struct dr
            {
                static constexpr unsigned addr = base_addr + 0x40;

                /**
                   Converted data
                */
                using data = core::register_t<core::ro_regp, addr, 0, 16>;
            };

            /**
               common configuration register
            */
            struct ccr
            {
                static constexpr unsigned addr = base_addr + 0x308;

                /**
                   Temperature sensor enable
                */
                using tsen = core::register_t<core::rw_regp, addr, 23, 1>;
                /**
                   VBAT enable
                */
                using vbaten = core::register_t<core::rw_regp, addr, 24, 1>;
                /**
                   Temperature sensor and VREFINT
              enable
                */
                using vrefen = core::register_t<core::rw_regp, addr, 22, 1>;
            };

        };

    }

    namespace adc
    {
    }
}
#endif
