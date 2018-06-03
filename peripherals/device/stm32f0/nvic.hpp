/*
 * File: nvic.hpp
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
           Nested Vectored Interrupt
      Controller
        */
        struct nvic
        {
            static constexpr unsigned base_addr = 0xE000E100;

            /**
               Interrupt Set Enable Register
            */
            template<int irqn>
            struct iser
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   SETENA
                */
                using setena = core::register_t<core::rw_regp, addr, irqn, 1>;
            };

            /**
               Interrupt Clear Enable
          Register
            */
            template<int irqn>
            struct icer
            {
                static constexpr unsigned addr = base_addr + 0x80;

                /**
                   CLRENA
                */
                using clrena = core::register_t<core::rw_regp, addr, irqn, 1>;
            };

            /**
               Interrupt Set-Pending Register
            */
            template<int irqn>
            struct ispr
            {
                static constexpr unsigned addr = base_addr + 0x100;

                /**
                   SETPEND
                */
                using setpend = core::register_t<core::rw_regp, addr, irqn, 1>;
            };

            /**
               Interrupt Clear-Pending
          Register
            */
            template<int irqn>
            struct icpr
            {
                static constexpr unsigned addr = base_addr + 0x180;

                /**
                   CLRPEND
                */
                using clrpend = core::register_t<core::rw_regp, addr, irqn, 1>;
            };

            /**
               Interrupt Priority Register 0
            */
            template<int irqn>
            struct ipr
            {
                static constexpr unsigned addr = base_addr + 0x300 + (static_cast<int>(irqn/4)*0x8);

                /**
                   PRI
                */
                using pri = core::register_t<core::rw_regp, addr, (irqn*8+6)-(static_cast<int>(irqn/4)*32), 2>;
            };

        };

    }

    namespace nvic
    {
    }
}
#endif
