/*
 * File: exception.hpp
 * Project: stm32c11
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */

#pragma once

#ifdef STM32F0

namespace exception {
  extern "C" {
    void NMI();
    void HardFault();
    void MemManage();
    void BusFault();
    void UsageFault();
    void SVCall();
    void DebugMon();
    void PendSV();
    void SysTick();
  }
}  // namespace exception

#endif