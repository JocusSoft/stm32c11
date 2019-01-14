/*
 * File: rtc.hpp
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
           Real-time clock
        */
        struct rtc
        {
            static constexpr unsigned base_addr = 0x40002800;

            /**
               time register
            */
            struct tr
            {
                static constexpr unsigned addr = base_addr + 0x0;

                /**
                   Hour tens in BCD format
                */
                using ht = core::register_t<core::rw_regp, addr, 20, 2>;
                /**
                   Hour units in BCD format
                */
                using hu = core::register_t<core::rw_regp, addr, 16, 4>;
                /**
                   Minute tens in BCD format
                */
                using mnt = core::register_t<core::rw_regp, addr, 12, 3>;
                /**
                   Minute units in BCD format
                */
                using mnu = core::register_t<core::rw_regp, addr, 8, 4>;
                /**
                   AM/PM notation
                */
                using pm = core::register_t<core::rw_regp, addr, 22, 1>;
                /**
                   Second tens in BCD format
                */
                using st = core::register_t<core::rw_regp, addr, 4, 3>;
                /**
                   Second units in BCD format
                */
                using su = core::register_t<core::rw_regp, addr, 0, 4>;
            };

            /**
               date register
            */
            struct dr
            {
                static constexpr unsigned addr = base_addr + 0x4;

                /**
                   Date tens in BCD format
                */
                using dt = core::register_t<core::rw_regp, addr, 4, 2>;
                /**
                   Date units in BCD format
                */
                using du = core::register_t<core::rw_regp, addr, 0, 4>;
                /**
                   Month tens in BCD format
                */
                using mt = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Month units in BCD format
                */
                using mu = core::register_t<core::rw_regp, addr, 8, 4>;
                /**
                   Week day units
                */
                using wdu = core::register_t<core::rw_regp, addr, 13, 3>;
                /**
                   Year tens in BCD format
                */
                using yt = core::register_t<core::rw_regp, addr, 20, 4>;
                /**
                   Year units in BCD format
                */
                using yu = core::register_t<core::rw_regp, addr, 16, 4>;
            };

            /**
               control register
            */
            struct cr
            {
                static constexpr unsigned addr = base_addr + 0x8;

                /**
                   Add 1 hour (summer time
              change)
                */
                using add1h = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   Alarm A enable
                */
                using alrae = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Alarm A interrupt enable
                */
                using alraie = core::register_t<core::rw_regp, addr, 12, 1>;
                /**
                   Backup
                */
                using bkp = core::register_t<core::rw_regp, addr, 18, 1>;
                /**
                   Bypass the shadow
              registers
                */
                using bypshad = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Calibration output enable
                */
                using coe = core::register_t<core::rw_regp, addr, 23, 1>;
                /**
                   Calibration output
              selection
                */
                using cosel = core::register_t<core::rw_regp, addr, 19, 1>;
                /**
                   Hour format
                */
                using fmt = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Output selection
                */
                using osel = core::register_t<core::rw_regp, addr, 21, 2>;
                /**
                   Output polarity
                */
                using pol = core::register_t<core::rw_regp, addr, 20, 1>;
                /**
                   RTC_REFIN reference clock detection
              enable (50 or 60 Hz)
                */
                using refckon = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Subtract 1 hour (winter time
              change)
                */
                using sub1h = core::register_t<core::rw_regp, addr, 17, 1>;
                /**
                   timestamp enable
                */
                using tse = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Time-stamp event active
              edge
                */
                using tsedge = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Time-stamp interrupt
              enable
                */
                using tsie = core::register_t<core::rw_regp, addr, 15, 1>;
            };

            /**
               initialization and status
          register
            */
            struct isr
            {
                static constexpr unsigned addr = base_addr + 0xC;

                /**
                   Alarm A flag
                */
                using alraf = core::register_t<core::rw_regp, addr, 8, 1>;
                /**
                   Alarm A write flag
                */
                using alrawf = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Initialization mode
                */
                using init = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Initialization flag
                */
                using initf = core::register_t<core::rw_regp, addr, 6, 1>;
                /**
                   Initialization status flag
                */
                using inits = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   Recalibration pending Flag
                */
                using recalpf = core::register_t<core::rw_regp, addr, 16, 1>;
                /**
                   Registers synchronization
              flag
                */
                using rsf = core::register_t<core::rw_regp, addr, 5, 1>;
                /**
                   Shift operation pending
                */
                using shpf = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   RTC_TAMP1 detection flag
                */
                using tamp1f = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   RTC_TAMP2 detection flag
                */
                using tamp2f = core::register_t<core::rw_regp, addr, 14, 1>;
                /**
                   Time-stamp flag
                */
                using tsf = core::register_t<core::rw_regp, addr, 11, 1>;
                /**
                   Time-stamp overflow flag
                */
                using tsovf = core::register_t<core::rw_regp, addr, 12, 1>;
            };

            /**
               prescaler register
            */
            struct prer
            {
                static constexpr unsigned addr = base_addr + 0x10;

                /**
                   Asynchronous prescaler
              factor
                */
                using prediv_a = core::register_t<core::rw_regp, addr, 16, 7>;
                /**
                   Synchronous prescaler
              factor
                */
                using prediv_s = core::register_t<core::rw_regp, addr, 0, 15>;
            };

            /**
               alarm A register
            */
            struct alrmar
            {
                static constexpr unsigned addr = base_addr + 0x1C;

                /**
                   Date tens in BCD format.
                */
                using dt = core::register_t<core::rw_regp, addr, 28, 2>;
                /**
                   Date units or day in BCD
              format.
                */
                using du = core::register_t<core::rw_regp, addr, 24, 4>;
                /**
                   Hour tens in BCD format.
                */
                using ht = core::register_t<core::rw_regp, addr, 20, 2>;
                /**
                   Hour units in BCD format.
                */
                using hu = core::register_t<core::rw_regp, addr, 16, 4>;
                /**
                   Minute tens in BCD format.
                */
                using mnt = core::register_t<core::rw_regp, addr, 12, 3>;
                /**
                   Minute units in BCD
              format.
                */
                using mnu = core::register_t<core::rw_regp, addr, 8, 4>;
                /**
                   Alarm A seconds mask
                */
                using msk1 = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   Alarm A minutes mask
                */
                using msk2 = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Alarm A hours mask
                */
                using msk3 = core::register_t<core::rw_regp, addr, 23, 1>;
                /**
                   Alarm A date mask
                */
                using msk4 = core::register_t<core::rw_regp, addr, 31, 1>;
                /**
                   AM/PM notation
                */
                using pm = core::register_t<core::rw_regp, addr, 22, 1>;
                /**
                   Second tens in BCD format.
                */
                using st = core::register_t<core::rw_regp, addr, 4, 3>;
                /**
                   Second units in BCD
              format.
                */
                using su = core::register_t<core::rw_regp, addr, 0, 4>;
                /**
                   Week day selection
                */
                using wdsel = core::register_t<core::rw_regp, addr, 30, 1>;
            };

            /**
               write protection register
            */
            struct wpr
            {
                static constexpr unsigned addr = base_addr + 0x24;

                /**
                   Write protection key
                */
                using key = core::register_t<core::wo_regp, addr, 0, 8>;
            };

            /**
               sub second register
            */
            struct ssr
            {
                static constexpr unsigned addr = base_addr + 0x28;

                /**
                   Sub second value
                */
                using ss = core::register_t<core::ro_regp, addr, 0, 16>;
            };

            /**
               shift control register
            */
            struct shiftr
            {
                static constexpr unsigned addr = base_addr + 0x2C;

                /**
                   Reserved
                */
                using add1s = core::register_t<core::wo_regp, addr, 31, 1>;
                /**
                   Subtract a fraction of a
              second
                */
                using subfs = core::register_t<core::wo_regp, addr, 0, 15>;
            };

            /**
               timestamp time register
            */
            struct tstr
            {
                static constexpr unsigned addr = base_addr + 0x30;

                /**
                   Hour tens in BCD format.
                */
                using ht = core::register_t<core::ro_regp, addr, 20, 2>;
                /**
                   Hour units in BCD format.
                */
                using hu = core::register_t<core::ro_regp, addr, 16, 4>;
                /**
                   Minute tens in BCD format.
                */
                using mnt = core::register_t<core::ro_regp, addr, 12, 3>;
                /**
                   Minute units in BCD
              format.
                */
                using mnu = core::register_t<core::ro_regp, addr, 8, 4>;
                /**
                   AM/PM notation
                */
                using pm = core::register_t<core::ro_regp, addr, 22, 1>;
                /**
                   Second tens in BCD format.
                */
                using st = core::register_t<core::ro_regp, addr, 4, 3>;
                /**
                   Second units in BCD
              format.
                */
                using su = core::register_t<core::ro_regp, addr, 0, 4>;
            };

            /**
               timestamp date register
            */
            struct tsdr
            {
                static constexpr unsigned addr = base_addr + 0x34;

                /**
                   Date tens in BCD format
                */
                using dt = core::register_t<core::ro_regp, addr, 4, 2>;
                /**
                   Date units in BCD format
                */
                using du = core::register_t<core::ro_regp, addr, 0, 4>;
                /**
                   Month tens in BCD format
                */
                using mt = core::register_t<core::ro_regp, addr, 12, 1>;
                /**
                   Month units in BCD format
                */
                using mu = core::register_t<core::ro_regp, addr, 8, 4>;
                /**
                   Week day units
                */
                using wdu = core::register_t<core::ro_regp, addr, 13, 3>;
            };

            /**
               time-stamp sub second register
            */
            struct tsssr
            {
                static constexpr unsigned addr = base_addr + 0x38;

                /**
                   Sub second value
                */
                using ss = core::register_t<core::ro_regp, addr, 0, 16>;
            };

            /**
               calibration register
            */
            struct calr
            {
                static constexpr unsigned addr = base_addr + 0x3C;

                /**
                   Calibration minus
                */
                using calm = core::register_t<core::rw_regp, addr, 0, 9>;
                /**
                   Use an 8-second calibration cycle
              period
                */
                using calp = core::register_t<core::rw_regp, addr, 15, 1>;
                /**
                   Reserved
                */
                using calw16 = core::register_t<core::rw_regp, addr, 13, 1>;
                /**
                   Use a 16-second calibration cycle
              period
                */
                using calw8 = core::register_t<core::rw_regp, addr, 14, 1>;
            };

            /**
               tamper and alternate function configuration
          register
            */
            struct tafcr
            {
                static constexpr unsigned addr = base_addr + 0x40;

                /**
                   PC13 mode
                */
                using pc13mode = core::register_t<core::rw_regp, addr, 19, 1>;
                /**
                   RTC_ALARM output type/PC13
              value
                */
                using pc13value = core::register_t<core::rw_regp, addr, 18, 1>;
                /**
                   PC14 mode
                */
                using pc14mode = core::register_t<core::rw_regp, addr, 21, 1>;
                /**
                   PC14 value
                */
                using pc14value = core::register_t<core::rw_regp, addr, 20, 1>;
                /**
                   PC15 mode
                */
                using pc15mode = core::register_t<core::rw_regp, addr, 23, 1>;
                /**
                   PC15 value
                */
                using pc15value = core::register_t<core::rw_regp, addr, 22, 1>;
                /**
                   RTC_TAMP1 input detection
              enable
                */
                using tamp1e = core::register_t<core::rw_regp, addr, 0, 1>;
                /**
                   Active level for RTC_TAMP1
              input
                */
                using tamp1trg = core::register_t<core::rw_regp, addr, 1, 1>;
                /**
                   RTC_TAMP2 input detection
              enable
                */
                using tamp2e = core::register_t<core::rw_regp, addr, 3, 1>;
                /**
                   Active level for RTC_TAMP2
              input
                */
                using tamp2_trg = core::register_t<core::rw_regp, addr, 4, 1>;
                /**
                   RTC_TAMPx filter count
                */
                using tampflt = core::register_t<core::rw_regp, addr, 11, 2>;
                /**
                   Tamper sampling frequency
                */
                using tampfreq = core::register_t<core::rw_regp, addr, 8, 3>;
                /**
                   Tamper interrupt enable
                */
                using tampie = core::register_t<core::rw_regp, addr, 2, 1>;
                /**
                   Activate timestamp on tamper detection
              event
                */
                using tampts = core::register_t<core::rw_regp, addr, 7, 1>;
                /**
                   RTC_TAMPx precharge
              duration
                */
                using tamp_prch = core::register_t<core::rw_regp, addr, 13, 2>;
                /**
                   RTC_TAMPx pull-up disable
                */
                using tamp_pudis = core::register_t<core::rw_regp, addr, 15, 1>;
            };

            /**
               alarm A sub second register
            */
            struct alrmassr
            {
                static constexpr unsigned addr = base_addr + 0x44;

                /**
                   Mask the most-significant bits starting
              at this bit
                */
                using maskss = core::register_t<core::rw_regp, addr, 24, 4>;
                /**
                   Sub seconds value
                */
                using ss = core::register_t<core::rw_regp, addr, 0, 15>;
            };

            /**
               backup register
            */
            struct bkp0r
            {
                static constexpr unsigned addr = base_addr + 0x50;

                /**
                   BKP
                */
                using bkp = core::register_t<core::rw_regp, addr, 0, 32>;
            };

            /**
               backup register
            */
            struct bkp1r
            {
                static constexpr unsigned addr = base_addr + 0x54;

                /**
                   BKP
                */
                using bkp = core::register_t<core::rw_regp, addr, 0, 32>;
            };

            /**
               backup register
            */
            struct bkp2r
            {
                static constexpr unsigned addr = base_addr + 0x58;

                /**
                   BKP
                */
                using bkp = core::register_t<core::rw_regp, addr, 0, 32>;
            };

            /**
               backup register
            */
            struct bkp3r
            {
                static constexpr unsigned addr = base_addr + 0x5C;

                /**
                   BKP
                */
                using bkp = core::register_t<core::rw_regp, addr, 0, 32>;
            };

            /**
               backup register
            */
            struct bkp4r
            {
                static constexpr unsigned addr = base_addr + 0x60;

                /**
                   BKP
                */
                using bkp = core::register_t<core::rw_regp, addr, 0, 32>;
            };

        };

    }

    namespace rtc
    {
    }
}
#endif
