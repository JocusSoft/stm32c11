/*
 * File: systick.hpp
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

namespace systick
{
    volatile static unsigned int _counter;

    INLINE static void init()
    {
        _counter=0;
        peripheral::regs::systick::rvr::reload::write(48000000/10000);
        peripheral::regs::systick::cvr::current::write(0);
        peripheral::regs::systick::csr::clksource::set();
        peripheral::regs::systick::csr::tickint::set();
        peripheral::regs::systick::csr::enable::set();
    }
    
    INLINE static void delay_ms(unsigned int millisec)
    {
        unsigned int val;

        val = _counter+millisec*10;
        while(_counter<val){};
    }
    
    INLINE static void delay_us(unsigned int micro)
    {
        unsigned int val;

        val = _counter+micro;
        while(_counter<val){};
    }
    
    extern "C" {
      void __attribute__ ((interrupt("IRQ"))) SysTick(void) {
        _counter++;
      }
    }
}

