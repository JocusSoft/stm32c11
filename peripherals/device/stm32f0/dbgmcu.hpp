/*
 * File: dbgmcu.hpp
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
           Debug support
        */
        struct dbgmcu
        {
            static constexpr unsigned base_addr = 0x40015800;

            /**
               MCU Device ID Code Register
            */
            struct idcode
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   Device Identifier
                */
                using dev_id = core::register_t<core::ro_regp, addr, 0, 12>;
                /**
                   Division Identifier
                */
                using div_id = core::register_t<core::ro_regp, addr, 12, 4>;
                /**
                   Revision Identifier
                */
                using rev_id = core::register_t<core::ro_regp, addr, 16, 16>;
            };

            /**
               Debug MCU Configuration
          Register
            */
            struct cr
            {
                static constexpr unsigned addr = base_addr + 0x4;

                /**
                   Debug Standby Mode
                */
                using dbg_standby = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Debug Stop Mode
                */
                using dbg_stop = core::register_t<core::rw_regp, addr, 1, 1>;
            };

            /**
               APB Low Freeze Register
            */
            struct apblfz
            {
                static constexpr unsigned addr = base_addr + 0x8;

                /**
                   Debug Independent Wachdog stopped when
              Core is halted
                */
                using dbg_iwdg_stop = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Debug RTC stopped when Core is
              halted
                */
                using dbg_rtc_stop = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Debug Timer 14 stopped when Core is
              halted
                */
                using dbg_timer14_stop = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Debug Timer 2 stopped when Core is
              halted
                */
                using dbg_timer2_stop = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Debug Timer 3 stopped when Core is
              halted
                */
                using dbg_timer3_stop = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Debug Timer 6 stopped when Core is
              halted
                */
                using dbg_timer6_stop = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Debug Window Wachdog stopped when Core
              is halted
                */
                using dbg_wwdg_stop = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   SMBUS timeout mode stopped when Core is
              halted
                */
                using i2c1_smbus_timeout = core::register_t<core::rw_regp, addr, 21, 1>;
            };

            /**
               APB High Freeze Register
            */
            struct apbhfz
            {
                static constexpr unsigned addr = base_addr + 0xC;

                /**
                   Debug Timer 15 stopped when Core is
              halted
                */
                using dbg_timer15_sto = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   Debug Timer 16 stopped when Core is
              halted
                */
                using dbg_timer16_sto = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   Debug Timer 17 stopped when Core is
              halted
                */
                using dbg_timer17_sto = core::register_t<core::rw_regp, addr, 18, 1>;
                /**
                   Debug Timer 1 stopped when Core is
              halted
                */
                using dbg_timer1_stop = core::register_t<core::rw_regp, addr, 11, 1>;
            };

        };

    }

    namespace dbgmcu
    {
    }
}
#endif
