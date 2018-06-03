/*
 * File: crc.hpp
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
           cyclic redundancy check calculation
      unit
        */
        struct crc
        {
            static constexpr unsigned base_addr = 0x40023000;

            /**
               Data register
            */
            static constexpr unsigned dr_addr = base_addr + 0x0;

            using dr = core::register_t<core::rw_regp, dr_addr, 0, 32>;
            /**
               Independent data register
            */
            static constexpr unsigned idr_addr = base_addr + 0x4;

            using idr = core::register_t<core::rw_regp, idr_addr, 0, 8>;
            /**
               Control register
            */
            struct cr
            {
                static constexpr unsigned addr = base_addr + 0x8;

                /**
                   reset bit
                */
                using reset = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Reverse input data
                */
                using rev_in = core::register_t<core::rw_regp, addr, 5, 2>;
                /**
                   Reverse output data
                */
                using rev_out = core::register_t<core::rw_regp, addr, 7, 1>;
            };

            /**
               Initial CRC value
            */
            static constexpr unsigned init_addr = base_addr + 0xC;

            using init = core::register_t<core::rw_regp, init_addr, 0, 32>;
        };

    }

    namespace crc
    {
    }
}
#endif
