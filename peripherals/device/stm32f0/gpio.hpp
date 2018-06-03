/*
 * File: gpio.hpp
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
        template <int which>
        struct gpio_base_addr;

        template <>
        struct gpio_base_addr<0>
        {
           static constexpr unsigned value = address::AHB2 + 0x0;
        };

        template <>
        struct gpio_base_addr<1>
        {
           static constexpr unsigned value = address::AHB2 + 0x0400;
        };

        template <>
        struct gpio_base_addr<2>
        {
           static constexpr unsigned value = address::AHB2 + 0x0800;
        };

        template <>
        struct gpio_base_addr<3>
        {
           static constexpr unsigned value = address::AHB2 + 0x0C00;
        };

        template <>
        struct gpio_base_addr<4>
        {
           static constexpr unsigned value = address::AHB2 + 0x1400;
        };

        /**
           General-purpose I/Os
        */
        template <int which>
        struct gpio
        {
            static constexpr unsigned base_addr = gpio_base_addr<which>::value;

            /**
               GPIO port mode register
            */
            struct moder
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   Port x configuration bits (y = 0..15)
                */
                template<int y>
                using pin = core::register_t<core::rw_regp, addr, y*2, 2>;                
            };

            /**
               GPIO port output type register
            */
            struct otyper
            {
                static constexpr unsigned addr = base_addr + 0x4;

                /**
                   Port x configuration bits (y = 0..15)
                */
                template<int y>
                using pin = core::register_t<core::rw_regp, addr, y, 1>;
            };

            /**
               GPIO port output speed register
            */
            struct ospeedr
            {
                static constexpr unsigned addr = base_addr + 0x8;

                /**
                   Port x configuration bits (y = 0..15)
                */
                template<int y>
                using pin = core::register_t<core::rw_regp, addr, y*2, 2>;
                
            };

            /**
               GPIO port pull-up/pull-down  register
            */
            struct pupdr
            {
                static constexpr unsigned addr = base_addr + 0xC;

                /**
                   Port x configuration bits (y = 0..15)
                */
                template<int y>
                using pin = core::register_t<core::rw_regp, addr, y*2, 2>;
                
            };

            /**
               GPIO port input data register
            */
            struct idr
            {
                static constexpr unsigned addr = base_addr + 0x10;

                /**
                   Port input data (y = 0..15)
                */
                template<int y>
                using pin = core::register_t<core::ro_regp, addr, y, 1>;
            };

            /**
               GPIO port output data register
            */
            struct odr
            {
                static constexpr unsigned addr = base_addr + 0x14;

                /**
                   Port output data (y = 0..15)
                */
                template<int y>
                using pin = core::register_t<core::rw_regp, addr, y, 1>;
            };

            /**
               GPIO port bit set/reset
          register
            */
            struct bsrr
            {
                static constexpr unsigned addr = base_addr + 0x18;

                /**
                   Port x set bit y (y=0..15)
                */
                template<int y>
                using br = core::register_t<core::wo_regp, addr, 16+y, 1>;
              
                /**
                   Port x set bit y (y=0..15)
                */
                template<int y>
                using bs = core::register_t<core::wo_regp, addr, 0+y, 1>;
            };

            /**
               GPIO port configuration lock register
            */
            struct lckr
            {
                static constexpr unsigned addr = base_addr + 0x1C;

                /**
                   Port x lock bit y (y=0..15)
                */
                template<int y>
                using pin = core::register_t<core::rw_regp, addr, 0+y, 1>;
                
                using lckk = core::register_t<core::rw_regp, addr, 16, 1>;
            };

            /**
               GPIO alternate function low
          register
            */
            struct afrl
            {
                static constexpr unsigned addr = base_addr + 0x20;

                /**
                   Alternate function selection for port x
              bit y (y = 0..7)
                */
                using afrl0 = core::register_t<core::rw_regp, addr, 0, 4>;
                /**
                   Alternate function selection for port x
              bit y (y = 0..7)
                */
                using afrl1 = core::register_t<core::rw_regp, addr, 4, 4>;
                /**
                   Alternate function selection for port x
              bit y (y = 0..7)
                */
                using afrl2 = core::register_t<core::rw_regp, addr, 8, 4>;
                /**
                   Alternate function selection for port x
              bit y (y = 0..7)
                */
                using afrl3 = core::register_t<core::rw_regp, addr, 12, 4>;
                /**
                   Alternate function selection for port x
              bit y (y = 0..7)
                */
                using afrl4 = core::register_t<core::rw_regp, addr, 16, 4>;
                /**
                   Alternate function selection for port x
              bit y (y = 0..7)
                */
                using afrl5 = core::register_t<core::rw_regp, addr, 20, 4>;
                /**
                   Alternate function selection for port x
              bit y (y = 0..7)
                */
                using afrl6 = core::register_t<core::rw_regp, addr, 24, 4>;
                /**
                   Alternate function selection for port x
              bit y (y = 0..7)
                */
                using afrl7 = core::register_t<core::rw_regp, addr, 28, 4>;
            };

            /**
               GPIO alternate function high
          register
            */
            struct afrh
            {
                static constexpr unsigned addr = base_addr + 0x24;

                /**
                   Alternate function selection for port x
              bit y (y = 8..15)
                */
                using afrh10 = core::register_t<core::rw_regp, addr, 8, 4>;
                /**
                   Alternate function selection for port x
              bit y (y = 8..15)
                */
                using afrh11 = core::register_t<core::rw_regp, addr, 12, 4>;
                /**
                   Alternate function selection for port x
              bit y (y = 8..15)
                */
                using afrh12 = core::register_t<core::rw_regp, addr, 16, 4>;
                /**
                   Alternate function selection for port x
              bit y (y = 8..15)
                */
                using afrh13 = core::register_t<core::rw_regp, addr, 20, 4>;
                /**
                   Alternate function selection for port x
              bit y (y = 8..15)
                */
                using afrh14 = core::register_t<core::rw_regp, addr, 24, 4>;
                /**
                   Alternate function selection for port x
              bit y (y = 8..15)
                */
                using afrh15 = core::register_t<core::rw_regp, addr, 28, 4>;
                /**
                   Alternate function selection for port x
              bit y (y = 8..15)
                */
                using afrh8 = core::register_t<core::rw_regp, addr, 0, 4>;
                /**
                   Alternate function selection for port x
              bit y (y = 8..15)
                */
                using afrh9 = core::register_t<core::rw_regp, addr, 4, 4>;
            };

            /**
               Port bit reset register
            */
            struct brr
            {
                static constexpr unsigned addr = base_addr + 0x28;

                /**
                   Port x Reset bit y
                */
                template<int y>
                using pin = core::register_t<core::wo_regp, addr, y, 1>;
            };

        };

    }

    namespace gpio
    {
        enum {
            GPIOA,
            GPIOB,
            GPIOC,
            GPIOD,
            GPIOF,
        };
    }
}
#endif
