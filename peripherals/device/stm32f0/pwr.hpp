/*
 * File: pwr.hpp
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
           Power control
        */
        struct pwr
        {
            static constexpr unsigned base_addr = 0x40007000;

            /**
               power control register
            */
            struct cr
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   Clear standby flag
                */
                using csbf = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Clear wakeup flag
                */
                using cwuf = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Disable backup domain write
              protection
                */
                using dbp = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Flash power down in Stop
              mode
                */
                using fpds = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   Low-power deep sleep
                */
                using lpds = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Power down deepsleep
                */
                using pdds = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   PVD level selection
                */
                using pls = core::register_t<core::rw_regp, addr, 5, 3>;
                /**
                   Power voltage detector
              enable
                */
                using pvde = core::register_t<core::rw_regp, addr, 4, 1>;
            };

            /**
               power control/status register
            */
            struct csr
            {
                static constexpr unsigned addr = base_addr + 0x4;

                /**
                   Backup regulator enable
                */
                using bre = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   Backup regulator ready
                */
                using brr = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Enable WKUP pin
                */
                using ewup = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   PVD output
                */
                using pvdo = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Standby flag
                */
                using sbf = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Wakeup flag
                */
                using wuf = core::register_t<core::rw_regp, addr, 0, 1>;
            };

        };

    }

    namespace pwr
    {
    }
}
#endif
