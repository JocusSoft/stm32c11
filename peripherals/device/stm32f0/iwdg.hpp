/*
 * File: iwdg.hpp
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
           Independent watchdog
        */
        struct iwdg
        {
            static constexpr unsigned base_addr = 0x40003000;

            /**
               Key register
            */
            struct kr
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   Key value
                */
                using key = core::register_t<core::wo_regp, addr, 0, 16>;
            };

            /**
               Prescaler register
            */
            static constexpr unsigned pr_addr = base_addr + 0x4;

            using pr = core::register_t<core::rw_regp, pr_addr, 0, 3>;
            /**
               Reload register
            */
            struct rlr
            {
                static constexpr unsigned addr = base_addr + 0x8;

                /**
                   Watchdog counter reload
              value
                */
                using rl = core::register_t<core::rw_regp, addr, 0, 12>;
            };

            /**
               Status register
            */
            struct sr
            {
                static constexpr unsigned addr = base_addr + 0xC;

                /**
                   Watchdog prescaler value
              update
                */
                using pvu = core::register_t<core::ro_regp, addr, 0, 1>;
                /**
                   Watchdog counter reload value
              update
                */
                using rvu = core::register_t<core::ro_regp, addr, 1, 1>;
                /**
                   Watchdog counter window value
              update
                */
                using wvu = core::register_t<core::ro_regp, addr, 2, 1>;
            };

            /**
               Window register
            */
            struct winr
            {
                static constexpr unsigned addr = base_addr + 0x10;

                /**
                   Watchdog counter window
              value
                */
                using win = core::register_t<core::rw_regp, addr, 0, 12>;
            };

        };

    }

    namespace iwdg
    {
    }
}
#endif
