/*
 * File: base.hpp
 * Project: stm32f0
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */


#pragma once

#ifdef stm32f0xx

namespace peripheral
{
    namespace address
    {
        static constexpr unsigned FLASH  = 0x08000000;
        static constexpr unsigned SRAM   = 0x20000000;
        static constexpr unsigned PERIPH = 0x40000000;
        static constexpr unsigned APB    = PERIPH;
        static constexpr unsigned AHB    = PERIPH + 0x00020000;
        static constexpr unsigned AHB2   = PERIPH + 0x08000000;
    }
}

#endif

