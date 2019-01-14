/*
 * File: wwdg.hpp
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
           Window watchdog
        */
        struct wwdg
        {
            static constexpr unsigned base_addr = 0x40002C00;

            /**
               Control register
            */
            struct cr
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   7-bit counter
                */
                using t = core::register_t<core::rw_regp, addr, 0, 7>;
                /**
                   Activation bit
                */
                using wdga = core::register_t<core::rw_regp, addr, 7, 1>;
            };

            /**
               Configuration register
            */
            struct cfr
            {
                static constexpr unsigned addr = base_addr + 0x4;

                /**
                   Early wakeup interrupt
                */
                using ewi = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   7-bit window value
                */
                using w = core::register_t<core::rw_regp, addr, 0, 7>;
                /**
                   Timer base
                */
                using wdgtb = core::register_t<core::rw_regp, addr, 7, 2>;
            };

            /**
               Status register
            */
            struct sr
            {
                static constexpr unsigned addr = base_addr + 0x8;

                /**
                   Early wakeup interrupt
              flag
                */
                using ewif = core::register_t<core::rw_regp, addr, 0, 1>;
            };

        };

    }

    namespace wwdg
    {
    }
}
#endif
