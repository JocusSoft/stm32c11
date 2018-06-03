/*
 * File: clock.hpp
 * Project: peripherals
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */


#pragma once

#include "peripherals/device_select.hpp"

#ifndef INLINE
#define INLINE __attribute__((__always_inline__)) inline
#endif

namespace clock
{
    
    template<int port>
    struct gpio
    {
        INLINE static void enable()
        {
            peripheral::regs::rcc::ahbrstr::ioprst<port>::set();
            peripheral::regs::rcc::ahbrstr::ioprst<port>::clear();
            peripheral::regs::rcc::ahbenr::iopen<port>::set();
        }
    };
    
    template<int dma_n>
    struct dma
    {
        INLINE static void enable()
        {
            peripheral::regs::rcc::ahbenr::dmaen::set();
        }
    };
}