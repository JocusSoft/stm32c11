/*
 * File: flash.hpp
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
           Flash
        */
        struct flash
        {
            static constexpr unsigned base_addr = 0x40022000;

            /**
               Flash access control register
            */
            struct acr
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   LATENCY
                */
                using latency = core::register_t<core::rw_regp, addr, 0, 3>;
                /**
                   PRFTBE
                */
                using prftbe = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   PRFTBS
                */
                using prftbs = core::register_t<core::rw_regp, addr, 5, 1>;
            };

            /**
               Flash key register
            */
            struct keyr
            {
                static constexpr unsigned addr = base_addr + 0x4;

                /**
                   Flash Key
                */
                using fkeyr = core::register_t<core::wo_regp, addr, 0, 32>;
            };

            /**
               Flash option key register
            */
            static constexpr unsigned optkeyr_addr = base_addr + 0x8;

            using optkeyr = core::register_t<core::wo_regp, optkeyr_addr, 0, 32>;
            /**
               Flash status register
            */
            struct sr
            {
                static constexpr unsigned addr = base_addr + 0xC;

                /**
                   Busy
                */
                using bsy = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   End of operation
                */
                using eop = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Programming error
                */
                using pgerr = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Write protection error
                */
                using wrprt = core::register_t<core::rw_regp, addr, 4, 1>;
            };

            /**
               Flash control register
            */
            struct cr
            {
                static constexpr unsigned addr = base_addr + 0x10;

                /**
                   End of operation interrupt
              enable
                */
                using eopie = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Error interrupt enable
                */
                using errie = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Force option byte loading
                */
                using force_optload = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Lock
                */
                using lock = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Mass erase
                */
                using mer = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Option byte erase
                */
                using opter = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Option byte programming
                */
                using optpg = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Option bytes write enable
                */
                using optwre = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   Page erase
                */
                using per = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Programming
                */
                using pg = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Start
                */
                using strt = core::register_t<core::rw_regp, addr, 6, 1>;
            };

            /**
               Flash address register
            */
            struct ar
            {
                static constexpr unsigned addr = base_addr + 0x14;

                /**
                   Flash address
                */
                using far = core::register_t<core::wo_regp, addr, 0, 32>;
            };

            /**
               Option byte register
            */
            struct obr
            {
                static constexpr unsigned addr = base_addr + 0x1C;

                /**
                   BOOT1
                */
                using boot1 = core::register_t<core::ro_regp, addr, 12, 1>;
                /**
                   Data0
                */
                using data0 = core::register_t<core::ro_regp, addr, 16, 8>;
                /**
                   Data1
                */
                using data1 = core::register_t<core::ro_regp, addr, 24, 8>;
                /**
                   Level 1 protection status
                */
                using level1_prot = core::register_t<core::ro_regp, addr, 1, 1>;
                /**
                   Level 2 protection status
                */
                using level2_prot = core::register_t<core::ro_regp, addr, 2, 1>;
                /**
                   Option byte error
                */
                using opterr = core::register_t<core::ro_regp, addr, 0, 1>;
                /**
                   VDDA_MONITOR
                */
                using vdda_monitor = core::register_t<core::ro_regp, addr, 13, 1>;
                /**
                   WDG_SW
                */
                using wdg_sw = core::register_t<core::ro_regp, addr, 8, 1>;
                /**
                   nRST_STDBY
                */
                using nrst_stdby = core::register_t<core::ro_regp, addr, 10, 1>;
                /**
                   nRST_STOP
                */
                using nrst_stop = core::register_t<core::ro_regp, addr, 9, 1>;
            };

            /**
               Write protection register
            */
            struct wrpr
            {
                static constexpr unsigned addr = base_addr + 0x20;

                /**
                   Write protect
                */
                using wrp = core::register_t<core::ro_regp, addr, 0, 32>;
            };

        };

    }

    namespace flash
    {
    }
}
#endif
