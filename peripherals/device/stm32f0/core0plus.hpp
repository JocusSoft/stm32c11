/*
 * File: core0plus.hpp
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
        struct systick
        {
            static constexpr unsigned base_addr = 0xE000E010;
            
            struct csr
            {
                static constexpr unsigned addr = base_addr + 0x0;
                
                using enable = core::register_t<core::rw_regp, addr, 0, 1>;
                
                using tickint = core::register_t<core::rw_regp, addr, 1, 1>;
                
                using clksource = core::register_t<core::rw_regp, addr, 2, 1>;
                
                using countflag = core::register_t<core::ro_regp, addr, 16, 1>;
            };
            
            struct rvr
            {
                static constexpr unsigned addr = base_addr + 0x4;
                
                using reload = core::register_t<core::rw_regp, addr, 0, 24>;
                
            };
            
            struct cvr
            {
                static constexpr unsigned addr = base_addr + 0x8;
                
                using current = core::register_t<core::rw_regp, addr, 0, 32>;
            };
            
            struct calib
            {
                static constexpr unsigned addr = base_addr + 0xC;
                
                using tenms = core::register_t<core::ro_regp, addr, 0, 24>;
                
                using skew = core::register_t<core::ro_regp, addr, 30, 1>;
                
                using noref = core::register_t<core::ro_regp, addr, 31, 1>;
            };
        };        
    }
}

#endif
