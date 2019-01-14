/*
 * File: tim.hpp
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
        template <int which>
        struct tim_base_addr;

        template <>
        struct tim_base_addr<0>
        {
           static constexpr unsigned value = 0x40012C00;
        };

        template <>
        struct tim_base_addr<1>
        {
           static constexpr unsigned value = 0x40002000;
        };

        template <>
        struct tim_base_addr<2>
        {
           static constexpr unsigned value = 0x40014000;
        };

        template <>
        struct tim_base_addr<3>
        {
           static constexpr unsigned value = 0x40014400;
        };

        template <>
        struct tim_base_addr<4>
        {
           static constexpr unsigned value = 0x40014800;
        };

        template <>
        struct tim_base_addr<5>
        {
           static constexpr unsigned value = 0x40000400;
        };

        template <>
        struct tim_base_addr<6>
        {
           static constexpr unsigned value = 0x40001000;
        };

        /**
           Advanced-timers
        */
        template <int which>
        struct tim
        {
            static constexpr unsigned base_addr = tim_base_addr<which>::value;

            /**
               control register 1
            */
            struct cr1
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   Auto-reload preload enable
                */
                using arpe = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Counter enable
                */
                using cen = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Clock division
                */
                using ckd = core::register_t<core::rw_regp, addr, 8, 2>;
                /**
                   Center-aligned mode
              selection
                */
                using cms = core::register_t<core::rw_regp, addr, 5, 2>;
                /**
                   Direction
                */
                using dir = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   One-pulse mode
                */
                using opm = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Update disable
                */
                using udis = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Update request source
                */
                using urs = core::register_t<core::rw_regp, addr, 2, 1>;
            };

            /**
               control register 2
            */
            struct cr2
            {
                static constexpr unsigned addr = base_addr + 0x4;

                /**
                   Capture/compare DMA
              selection
                */
                using ccds = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Capture/compare preloaded
              control
                */
                using ccpc = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Capture/compare control update
              selection
                */
                using ccus = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Master mode selection
                */
                using mms = core::register_t<core::rw_regp, addr, 4, 3>;
                /**
                   Output Idle state 1
                */
                using ois1 = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Output Idle state 1
                */
                using ois1n = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   Output Idle state 2
                */
                using ois2 = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Output Idle state 2
                */
                using ois2n = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Output Idle state 3
                */
                using ois3 = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Output Idle state 3
                */
                using ois3n = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Output Idle state 4
                */
                using ois4 = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   TI1 selection
                */
                using ti1s = core::register_t<core::rw_regp, addr, 7, 1>;
            };

            /**
               slave mode control register
            */
            struct smcr
            {
                static constexpr unsigned addr = base_addr + 0x8;

                /**
                   External clock enable
                */
                using ece = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   External trigger filter
                */
                using etf = core::register_t<core::rw_regp, addr, 8, 4>;
                /**
                   External trigger polarity
                */
                using etp = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   External trigger prescaler
                */
                using etps = core::register_t<core::rw_regp, addr, 12, 2>;
                /**
                   Master/Slave mode
                */
                using msm = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Slave mode selection
                */
                using sms = core::register_t<core::rw_regp, addr, 0, 3>;
                /**
                   Trigger selection
                */
                using ts = core::register_t<core::rw_regp, addr, 4, 3>;
            };

            /**
               DMA/Interrupt enable register
            */
            struct dier
            {
                static constexpr unsigned addr = base_addr + 0xC;

                /**
                   Break interrupt enable
                */
                using bie = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Capture/Compare 1 DMA request
              enable
                */
                using cc1de = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   Capture/Compare 1 interrupt
              enable
                */
                using cc1ie = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Capture/Compare 2 DMA request
              enable
                */
                using cc2de = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Capture/Compare 2 interrupt
              enable
                */
                using cc2ie = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Capture/Compare 3 DMA request
              enable
                */
                using cc3de = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Capture/Compare 3 interrupt
              enable
                */
                using cc3ie = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Capture/Compare 4 DMA request
              enable
                */
                using cc4de = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Capture/Compare 4 interrupt
              enable
                */
                using cc4ie = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Reserved
                */
                using comde = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   COM interrupt enable
                */
                using comie = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Trigger DMA request enable
                */
                using tde = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Trigger interrupt enable
                */
                using tie = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Update DMA request enable
                */
                using ude = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Update interrupt enable
                */
                using uie = core::register_t<core::rw_regp, addr, 0, 1>;
            };

            /**
               status register
            */
            struct sr
            {
                static constexpr unsigned addr = base_addr + 0x10;

                /**
                   Break interrupt flag
                */
                using bif = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Capture/compare 1 interrupt
              flag
                */
                using cc1if = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Capture/Compare 1 overcapture
              flag
                */
                using cc1of = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   Capture/Compare 2 interrupt
              flag
                */
                using cc2if = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Capture/compare 2 overcapture
              flag
                */
                using cc2of = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Capture/Compare 3 interrupt
              flag
                */
                using cc3if = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Capture/Compare 3 overcapture
              flag
                */
                using cc3of = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Capture/Compare 4 interrupt
              flag
                */
                using cc4if = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Capture/Compare 4 overcapture
              flag
                */
                using cc4of = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   COM interrupt flag
                */
                using comif = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Trigger interrupt flag
                */
                using tif = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Update interrupt flag
                */
                using uif = core::register_t<core::rw_regp, addr, 0, 1>;
            };

            /**
               event generation register
            */
            struct egr
            {
                static constexpr unsigned addr = base_addr + 0x14;

                /**
                   Break generation
                */
                using bg = core::register_t<core::wo_regp, addr, 7, 1>;
                /**
                   Capture/compare 1
              generation
                */
                using cc1g = core::register_t<core::wo_regp, addr, 1, 1>;
                /**
                   Capture/compare 2
              generation
                */
                using cc2g = core::register_t<core::wo_regp, addr, 2, 1>;
                /**
                   Capture/compare 3
              generation
                */
                using cc3g = core::register_t<core::wo_regp, addr, 3, 1>;
                /**
                   Capture/compare 4
              generation
                */
                using cc4g = core::register_t<core::wo_regp, addr, 4, 1>;
                /**
                   Capture/Compare control update
              generation
                */
                using comg = core::register_t<core::wo_regp, addr, 5, 1>;
                /**
                   Trigger generation
                */
                using tg = core::register_t<core::wo_regp, addr, 6, 1>;
                /**
                   Update generation
                */
                using ug = core::register_t<core::wo_regp, addr, 0, 1>;
            };

            /**
               capture/compare mode register (output
          mode)
            */
            struct ccmr1_output
            {
                static constexpr unsigned addr = base_addr + 0x18;

                /**
                   Capture/Compare 1
              selection
                */
                using cc1s = core::register_t<core::rw_regp, addr, 0, 2>;
                /**
                   Capture/Compare 2
              selection
                */
                using cc2s = core::register_t<core::rw_regp, addr, 8, 2>;
                /**
                   Output Compare 1 clear
              enable
                */
                using oc1ce = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Output Compare 1 fast
              enable
                */
                using oc1fe = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Output Compare 1 mode
                */
                using oc1m = core::register_t<core::rw_regp, addr, 4, 3>;
                /**
                   Output Compare 1 preload
              enable
                */
                using oc1pe = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Output Compare 2 clear
              enable
                */
                using oc2ce = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Output Compare 2 fast
              enable
                */
                using oc2fe = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Output Compare 2 mode
                */
                using oc2m = core::register_t<core::rw_regp, addr, 12, 3>;
                /**
                   Output Compare 2 preload
              enable
                */
                using oc2pe = core::register_t<core::rw_regp, addr, 11, 1>;
            };

            /**
               capture/compare mode register 1 (input
          mode)
            */
            struct ccmr1_input
            {
                static constexpr unsigned addr = base_addr + 0x18;

                /**
                   Capture/Compare 1
              selection
                */
                using cc1s = core::register_t<core::rw_regp, addr, 0, 2>;
                /**
                   Capture/Compare 2
              selection
                */
                using cc2s = core::register_t<core::rw_regp, addr, 8, 2>;
                /**
                   Input capture 1 filter
                */
                using ic1f = core::register_t<core::rw_regp, addr, 4, 4>;
                /**
                   Input capture 1 prescaler
                */
                using ic1pcs = core::register_t<core::rw_regp, addr, 2, 2>;
                /**
                   Input capture 2 filter
                */
                using ic2f = core::register_t<core::rw_regp, addr, 12, 4>;
                /**
                   Input capture 2 prescaler
                */
                using ic2pcs = core::register_t<core::rw_regp, addr, 10, 2>;
            };

            /**
               capture/compare mode register (output
          mode)
            */
            struct ccmr2_output
            {
                static constexpr unsigned addr = base_addr + 0x1C;

                /**
                   Capture/Compare 3
              selection
                */
                using cc3s = core::register_t<core::rw_regp, addr, 0, 2>;
                /**
                   Capture/Compare 4
              selection
                */
                using cc4s = core::register_t<core::rw_regp, addr, 8, 2>;
                /**
                   Output compare 3 clear
              enable
                */
                using oc3ce = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Output compare 3 fast
              enable
                */
                using oc3fe = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Output compare 3 mode
                */
                using oc3m = core::register_t<core::rw_regp, addr, 4, 3>;
                /**
                   Output compare 3 preload
              enable
                */
                using oc3pe = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Output compare 4 clear
              enable
                */
                using oc4ce = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Output compare 4 fast
              enable
                */
                using oc4fe = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Output compare 4 mode
                */
                using oc4m = core::register_t<core::rw_regp, addr, 12, 3>;
                /**
                   Output compare 4 preload
              enable
                */
                using oc4pe = core::register_t<core::rw_regp, addr, 11, 1>;
            };

            /**
               capture/compare mode register 2 (input
          mode)
            */
            struct ccmr2_input
            {
                static constexpr unsigned addr = base_addr + 0x1C;

                /**
                   Capture/compare 3
              selection
                */
                using cc3s = core::register_t<core::rw_regp, addr, 0, 2>;
                /**
                   Capture/Compare 4
              selection
                */
                using cc4s = core::register_t<core::rw_regp, addr, 8, 2>;
                /**
                   Input capture 3 filter
                */
                using ic3f = core::register_t<core::rw_regp, addr, 4, 4>;
                /**
                   Input capture 3 prescaler
                */
                using ic3psc = core::register_t<core::rw_regp, addr, 2, 2>;
                /**
                   Input capture 4 filter
                */
                using ic4f = core::register_t<core::rw_regp, addr, 12, 4>;
                /**
                   Input capture 4 prescaler
                */
                using ic4psc = core::register_t<core::rw_regp, addr, 10, 2>;
            };

            /**
               capture/compare enable
          register
            */
            struct ccer
            {
                static constexpr unsigned addr = base_addr + 0x20;

                /**
                   Capture/Compare 1 output
              enable
                */
                using cc1e = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Capture/Compare 1 complementary output
              enable
                */
                using cc1ne = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Capture/Compare 1 output
              Polarity
                */
                using cc1np = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Capture/Compare 1 output
              Polarity
                */
                using cc1p = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   Capture/Compare 2 output
              enable
                */
                using cc2e = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Capture/Compare 2 complementary output
              enable
                */
                using cc2ne = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Capture/Compare 2 output
              Polarity
                */
                using cc2np = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Capture/Compare 2 output
              Polarity
                */
                using cc2p = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Capture/Compare 3 output
              enable
                */
                using cc3e = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Capture/Compare 3 complementary output
              enable
                */
                using cc3ne = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Capture/Compare 3 output
              Polarity
                */
                using cc3np = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Capture/Compare 3 output
              Polarity
                */
                using cc3p = core::register_t<core::rw_regp, addr, 9, 1>;
                /**
                   Capture/Compare 4 output
              enable
                */
                using cc4e = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Capture/Compare 3 output
              Polarity
                */
                using cc4p = core::register_t<core::rw_regp, addr, 13, 1>;
            };

            /**
               counter
            */
            static constexpr unsigned cnt_addr = base_addr + 0x24;

            using cnt = core::register_t<core::rw_regp, cnt_addr, 0, 16>;
            /**
               prescaler
            */
            static constexpr unsigned psc_addr = base_addr + 0x28;

            using psc = core::register_t<core::rw_regp, psc_addr, 0, 16>;
            /**
               auto-reload register
            */
            static constexpr unsigned arr_addr = base_addr + 0x2C;

            using arr = core::register_t<core::rw_regp, arr_addr, 0, 16>;
            /**
               repetition counter register
            */
            struct rcr
            {
                static constexpr unsigned addr = base_addr + 0x30;

                /**
                   Repetition counter value
                */
                using rep = core::register_t<core::rw_regp, addr, 0, 8>;
            };

            /**
               capture/compare register 1
            */
            static constexpr unsigned ccr1_addr = base_addr + 0x34;

            using ccr1 = core::register_t<core::rw_regp, ccr1_addr, 0, 16>;
            /**
               capture/compare register 2
            */
            static constexpr unsigned ccr2_addr = base_addr + 0x38;

            using ccr2 = core::register_t<core::rw_regp, ccr2_addr, 0, 16>;
            /**
               capture/compare register 3
            */
            static constexpr unsigned ccr3_addr = base_addr + 0x3C;

            using ccr3 = core::register_t<core::rw_regp, ccr3_addr, 0, 16>;
            /**
               capture/compare register 4
            */
            static constexpr unsigned ccr4_addr = base_addr + 0x40;

            using ccr4 = core::register_t<core::rw_regp, ccr4_addr, 0, 16>;
            /**
               break and dead-time register
            */
            struct bdtr
            {
                static constexpr unsigned addr = base_addr + 0x44;

                /**
                   Automatic output enable
                */
                using aoe = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Break enable
                */
                using bke = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Break polarity
                */
                using bkp = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Dead-time generator setup
                */
                using dtg = core::register_t<core::rw_regp, addr, 0, 8>;
                /**
                   Lock configuration
                */
                using lock = core::register_t<core::rw_regp, addr, 8, 2>;
                /**
                   Main output enable
                */
                using moe = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Off-state selection for Idle
              mode
                */
                using ossi = core::register_t<core::rw_regp, addr, 10, 1>;
                /**
                   Off-state selection for Run
              mode
                */
                using ossr = core::register_t<core::rw_regp, addr, 11, 1>;
            };

            /**
               DMA control register
            */
            struct dcr
            {
                static constexpr unsigned addr = base_addr + 0x48;

                /**
                   DMA base address
                */
                using dba = core::register_t<core::rw_regp, addr, 0, 5>;
                /**
                   DMA burst length
                */
                using dbl = core::register_t<core::rw_regp, addr, 8, 5>;
            };

            /**
               DMA address for full transfer
            */
            struct dmar
            {
                static constexpr unsigned addr = base_addr + 0x4C;

                /**
                   DMA register for burst
              accesses
                */
                using dmab = core::register_t<core::rw_regp, addr, 0, 16>;
            };

        };

    }

    namespace tim
    {
        enum{
            TIM1,
            TIM14,
            TIM15,
            TIM16,
            TIM17,
            TIM3,
            TIM6,
        };
    }
}
#endif
