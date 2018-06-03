/*
 * File: pin.hpp
 * Project: peripherals
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */

#pragma once

#include <inttypes.h>
#include "device_select.hpp"

#ifndef INLINE
#define INLINE __attribute__((__always_inline__)) inline
#endif

namespace gpio
{
        enum pin_mode
        {
            INPUT=0,
            OUTPUT,
            ALTERNATE,
            ANALOG
        };
        enum pin_otype
        {
            PUSH_PULL=0,
            OPEN_DRAIN
        };
        
        enum pin_pull_push
        {
            DISABLED = 0,
            PULLUP,
            PULLDOWN
        };
        
        enum pin_speed
        {
            LOW,
            MEDIUM,
            HIGH
        };
        
        template<int port, int pin_no>
        struct pin
        {
            INLINE static void write(bool state)
            {
                state ? set():clr();
            }
            INLINE static void set()
            {
                peripheral::regs::gpio<port>::bsrr::template bs<pin_no>::set();
            }
            
            INLINE static void clr()
            {
                peripheral::regs::gpio<port>::bsrr::template br<pin_no>::set();
            }
            
            INLINE static uint8_t read()
            {
                return peripheral::regs::gpio<port>::idr::template pin<pin_no>::read();
            }
            
            INLINE static void mode(pin_mode pmode,pin_speed speed=LOW, pin_otype type=PUSH_PULL )
            {
                peripheral::regs::gpio<port>::moder::template pin<pin_no>::write(pmode);
                peripheral::regs::gpio<port>::otyper::template pin<pin_no>::write(type);
                peripheral::regs::gpio<port>::ospeedr::template pin<pin_no>::write(speed);
            }
            
            INLINE static void set_pull(pin_pull_push pullmode)
            {
                switch(pullmode)
                {
                    case DISABLED:
                        peripheral::regs::gpio<port>::pupdr::template pin<pin_no>::write(0);
                        break;
                    case PULLUP:
                        peripheral::regs::gpio<port>::pupdr::template pin<pin_no>::write(1);
                        break;
                    case PULLDOWN:
                        peripheral::regs::gpio<port>::pupdr::template pin<pin_no>::write(2);
                        break;
                }
                
            }
            
            
        };
}

