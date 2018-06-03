/*
 * File: main.cpp
 * Project: sample
 * File Created: Saturday, 26th August 2017 11:12:12 am
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#include "peripherals/interrupts.hpp"
#include "peripherals/nvic.hpp"
#include "peripherals/pin.hpp"
#include "peripherals/clock.hpp"
#include "peripherals/systick.hpp"

using namespace peripheral::gpio;

typedef gpio::pin<GPIOB,15> LED_1;
typedef gpio::pin<GPIOB,14> LED_2

int main()
{
    clock::gpio<GPIOB>::enable();
    
    LED_1::mode(gpio::pin_mode::OUTPUT);
    LED_2::mode(gpio::pin_mode::OUTPUT);
    
    systick::init();
    

    
    for(;;)
    {
        
        LED_1::set();
        LED_2::set();

        systick::delay_ms(500);

        LED_1::clr();
        LED_2::clr();

        systick::delay_ms(500);
    }
}



