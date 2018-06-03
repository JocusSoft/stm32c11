/*
 * File: exception.cpp
 * Project: stm32c11
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */
#include <stdint.h>
#include "exception.hpp"

extern char __StackTop;

typedef uint32_t u32;
typedef void (* pvf)();

extern "C" void resetHandler();

namespace exception {
  __attribute__ ((section(".exception_vector")))
    pvf exceptionVector[] = {
    pvf(&__StackTop),  // 0x0000
    resetHandler,// 0x0004
    NMI,// 0x0008
    HardFault,// 0x000C
    MemManage,// 0x0010
    BusFault,// 0x0014
    UsageFault,// 0x0018
    0,// 0x001C
    0,// 0x0020
    0,// 0x0024
    0,// 0x0028
    SVCall,// 0x002C
    DebugMon,// 0x0030
    0,// 0x0034
    PendSV,// 0x0038
    SysTick,// 0x003C
  };  // exceptionVector
}  // namespace exception

extern "C" void defaultExceptionHandler()
{
  while (true) {
  }
}

// Core exceptions
#pragma weak NMI        = defaultExceptionHandler
#pragma weak HardFault  = defaultExceptionHandler
#pragma weak MemManage  = defaultExceptionHandler
#pragma weak BusFault   = defaultExceptionHandler
#pragma weak UsageFault = defaultExceptionHandler
#pragma weak SVCall     = defaultExceptionHandler
#pragma weak DebugMon   = defaultExceptionHandler
#pragma weak PendSV     = defaultExceptionHandler
#pragma weak SysTick    = defaultExceptionHandler
