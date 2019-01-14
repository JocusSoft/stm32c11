/*
 * File: exti.hpp
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
           External interrupt/event
      controller
        */
        struct exti
        {
            static constexpr unsigned base_addr = 0x40010400;

            /**
               Interrupt mask register
          (EXTI_IMR)
            */
            struct imr
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   Interrupt Mask on line 0
                */
                using mr0 = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Interrupt Mask on line 1
                */
                using mr1 = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Interrupt Mask on line 10
                */
                using mr10 = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Interrupt Mask on line 11
                */
                using mr11 = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Interrupt Mask on line 12
                */
                using mr12 = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Interrupt Mask on line 13
                */
                using mr13 = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Interrupt Mask on line 14
                */
                using mr14 = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Interrupt Mask on line 15
                */
                using mr15 = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Interrupt Mask on line 16
                */
                using mr16 = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   Interrupt Mask on line 17
                */
                using mr17 = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   Interrupt Mask on line 18
                */
                using mr18 = core::register_t<core::rw_regp, addr, 18, 1>;
                /**
                   Interrupt Mask on line 19
                */
                using mr19 = core::register_t<core::rw_regp, addr, 19, 1>;
                /**
                   Interrupt Mask on line 2
                */
                using mr2 = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Interrupt Mask on line 20
                */
                using mr20 = core::register_t<core::rw_regp, addr, 20, 1>;
                /**
                   Interrupt Mask on line 21
                */
                using mr21 = core::register_t<core::rw_regp, addr, 21, 1>;
                /**
                   Interrupt Mask on line 22
                */
                using mr22 = core::register_t<core::rw_regp, addr, 22, 1>;
                /**
                   Interrupt Mask on line 23
                */
                using mr23 = core::register_t<core::rw_regp, addr, 23, 1>;
                /**
                   Interrupt Mask on line 24
                */
                using mr24 = core::register_t<core::rw_regp, addr, 24, 1>;
                /**
                   Interrupt Mask on line 25
                */
                using mr25 = core::register_t<core::rw_regp, addr, 25, 1>;
                /**
                   Interrupt Mask on line 26
                */
                using mr26 = core::register_t<core::rw_regp, addr, 26, 1>;
                /**
                   Interrupt Mask on line 27
                */
                using mr27 = core::register_t<core::rw_regp, addr, 27, 1>;
                /**
                   Interrupt Mask on line 3
                */
                using mr3 = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Interrupt Mask on line 4
                */
                using mr4 = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Interrupt Mask on line 5
                */
                using mr5 = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Interrupt Mask on line 6
                */
                using mr6 = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Interrupt Mask on line 7
                */
                using mr7 = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Interrupt Mask on line 8
                */
                using mr8 = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Interrupt Mask on line 9
                */
                using mr9 = core::register_t<core::rw_regp, addr, 9, 1>;
            };

            /**
               Event mask register (EXTI_EMR)
            */
            struct emr
            {
                static constexpr unsigned addr = base_addr + 0x4;

                /**
                   Event Mask on line 0
                */
                using mr0 = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Event Mask on line 1
                */
                using mr1 = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Event Mask on line 10
                */
                using mr10 = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Event Mask on line 11
                */
                using mr11 = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Event Mask on line 12
                */
                using mr12 = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Event Mask on line 13
                */
                using mr13 = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Event Mask on line 14
                */
                using mr14 = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Event Mask on line 15
                */
                using mr15 = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Event Mask on line 16
                */
                using mr16 = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   Event Mask on line 17
                */
                using mr17 = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   Event Mask on line 18
                */
                using mr18 = core::register_t<core::rw_regp, addr, 18, 1>;
                /**
                   Event Mask on line 19
                */
                using mr19 = core::register_t<core::rw_regp, addr, 19, 1>;
                /**
                   Event Mask on line 2
                */
                using mr2 = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Event Mask on line 20
                */
                using mr20 = core::register_t<core::rw_regp, addr, 20, 1>;
                /**
                   Event Mask on line 21
                */
                using mr21 = core::register_t<core::rw_regp, addr, 21, 1>;
                /**
                   Event Mask on line 22
                */
                using mr22 = core::register_t<core::rw_regp, addr, 22, 1>;
                /**
                   Event Mask on line 23
                */
                using mr23 = core::register_t<core::rw_regp, addr, 23, 1>;
                /**
                   Event Mask on line 24
                */
                using mr24 = core::register_t<core::rw_regp, addr, 24, 1>;
                /**
                   Event Mask on line 25
                */
                using mr25 = core::register_t<core::rw_regp, addr, 25, 1>;
                /**
                   Event Mask on line 26
                */
                using mr26 = core::register_t<core::rw_regp, addr, 26, 1>;
                /**
                   Event Mask on line 27
                */
                using mr27 = core::register_t<core::rw_regp, addr, 27, 1>;
                /**
                   Event Mask on line 3
                */
                using mr3 = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Event Mask on line 4
                */
                using mr4 = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Event Mask on line 5
                */
                using mr5 = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Event Mask on line 6
                */
                using mr6 = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Event Mask on line 7
                */
                using mr7 = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Event Mask on line 8
                */
                using mr8 = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Event Mask on line 9
                */
                using mr9 = core::register_t<core::rw_regp, addr, 9, 1>;
            };

            /**
               Rising Trigger selection register
          (EXTI_RTSR)
            */
            struct rtsr
            {
                static constexpr unsigned addr = base_addr + 0x8;

                /**
                   Rising trigger event configuration of
              line 0
                */
                using tr0 = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Rising trigger event configuration of
              line 1
                */
                using tr1 = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Rising trigger event configuration of
              line 10
                */
                using tr10 = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Rising trigger event configuration of
              line 11
                */
                using tr11 = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Rising trigger event configuration of
              line 12
                */
                using tr12 = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Rising trigger event configuration of
              line 13
                */
                using tr13 = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Rising trigger event configuration of
              line 14
                */
                using tr14 = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Rising trigger event configuration of
              line 15
                */
                using tr15 = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Rising trigger event configuration of
              line 16
                */
                using tr16 = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   Rising trigger event configuration of
              line 17
                */
                using tr17 = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   Rising trigger event configuration of
              line 19
                */
                using tr19 = core::register_t<core::rw_regp, addr, 19, 1>;
                /**
                   Rising trigger event configuration of
              line 2
                */
                using tr2 = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Rising trigger event configuration of
              line 3
                */
                using tr3 = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Rising trigger event configuration of
              line 4
                */
                using tr4 = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Rising trigger event configuration of
              line 5
                */
                using tr5 = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Rising trigger event configuration of
              line 6
                */
                using tr6 = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Rising trigger event configuration of
              line 7
                */
                using tr7 = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Rising trigger event configuration of
              line 8
                */
                using tr8 = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Rising trigger event configuration of
              line 9
                */
                using tr9 = core::register_t<core::rw_regp, addr, 9, 1>;
            };

            /**
               Falling Trigger selection register
          (EXTI_FTSR)
            */
            struct ftsr
            {
                static constexpr unsigned addr = base_addr + 0xC;

                /**
                   Falling trigger event configuration of
              line 0
                */
                using tr0 = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Falling trigger event configuration of
              line 1
                */
                using tr1 = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Falling trigger event configuration of
              line 10
                */
                using tr10 = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Falling trigger event configuration of
              line 11
                */
                using tr11 = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Falling trigger event configuration of
              line 12
                */
                using tr12 = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Falling trigger event configuration of
              line 13
                */
                using tr13 = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Falling trigger event configuration of
              line 14
                */
                using tr14 = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Falling trigger event configuration of
              line 15
                */
                using tr15 = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Falling trigger event configuration of
              line 16
                */
                using tr16 = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   Falling trigger event configuration of
              line 17
                */
                using tr17 = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   Falling trigger event configuration of
              line 19
                */
                using tr19 = core::register_t<core::rw_regp, addr, 19, 1>;
                /**
                   Falling trigger event configuration of
              line 2
                */
                using tr2 = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Falling trigger event configuration of
              line 3
                */
                using tr3 = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Falling trigger event configuration of
              line 4
                */
                using tr4 = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Falling trigger event configuration of
              line 5
                */
                using tr5 = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Falling trigger event configuration of
              line 6
                */
                using tr6 = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Falling trigger event configuration of
              line 7
                */
                using tr7 = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Falling trigger event configuration of
              line 8
                */
                using tr8 = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Falling trigger event configuration of
              line 9
                */
                using tr9 = core::register_t<core::rw_regp, addr, 9, 1>;
            };

            /**
               Software interrupt event register
          (EXTI_SWIER)
            */
            struct swier
            {
                static constexpr unsigned addr = base_addr + 0x10;

                /**
                   Software Interrupt on line
              0
                */
                using swier0 = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Software Interrupt on line
              1
                */
                using swier1 = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Software Interrupt on line
              10
                */
                using swier10 = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Software Interrupt on line
              11
                */
                using swier11 = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Software Interrupt on line
              12
                */
                using swier12 = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Software Interrupt on line
              13
                */
                using swier13 = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Software Interrupt on line
              14
                */
                using swier14 = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Software Interrupt on line
              15
                */
                using swier15 = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Software Interrupt on line
              16
                */
                using swier16 = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   Software Interrupt on line
              17
                */
                using swier17 = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   Software Interrupt on line
              19
                */
                using swier19 = core::register_t<core::rw_regp, addr, 19, 1>;
                /**
                   Software Interrupt on line
              2
                */
                using swier2 = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Software Interrupt on line
              3
                */
                using swier3 = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Software Interrupt on line
              4
                */
                using swier4 = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Software Interrupt on line
              5
                */
                using swier5 = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Software Interrupt on line
              6
                */
                using swier6 = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Software Interrupt on line
              7
                */
                using swier7 = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Software Interrupt on line
              8
                */
                using swier8 = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Software Interrupt on line
              9
                */
                using swier9 = core::register_t<core::rw_regp, addr, 9, 1>;
            };

            /**
               Pending register (EXTI_PR)
            */
            struct pr
            {
                static constexpr unsigned addr = base_addr + 0x14;

                /**
                   Pending bit 0
                */
                using pr0 = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Pending bit 1
                */
                using pr1 = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Pending bit 10
                */
                using pr10 = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Pending bit 11
                */
                using pr11 = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Pending bit 12
                */
                using pr12 = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Pending bit 13
                */
                using pr13 = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Pending bit 14
                */
                using pr14 = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Pending bit 15
                */
                using pr15 = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Pending bit 16
                */
                using pr16 = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   Pending bit 17
                */
                using pr17 = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   Pending bit 19
                */
                using pr19 = core::register_t<core::rw_regp, addr, 19, 1>;
                /**
                   Pending bit 2
                */
                using pr2 = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Pending bit 3
                */
                using pr3 = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Pending bit 4
                */
                using pr4 = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Pending bit 5
                */
                using pr5 = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Pending bit 6
                */
                using pr6 = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Pending bit 7
                */
                using pr7 = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Pending bit 8
                */
                using pr8 = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Pending bit 9
                */
                using pr9 = core::register_t<core::rw_regp, addr, 9, 1>;
            };

        };

    }

    namespace exti
    {
    }
}
#endif
