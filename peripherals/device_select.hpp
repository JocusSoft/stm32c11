/*
 * File: device_select.hpp
 * Project: peripherals
 * File Created: Wednesday, 14th June 2017 10:16:14 pm
 * Copyright 2017 - 2018 Denis Mitrofanov (dmitrophanov@gmail.com)
 * Licensed under the Apache License, Version 2.0
 */


#pragma once

#ifdef STM32F0

#include "device/stm32f0/adc.hpp"
#include "device/stm32f0/base.hpp"
#include "device/stm32f0/core0plus.hpp"
#ifdef USE_DMA
#include "device/stm32f0/dma.hpp"
#endif
#include "device/stm32f0/exti.hpp"
#include "device/stm32f0/exception.hpp"
#include "device/stm32f0/interrupts.hpp"
#include "device/stm32f0/flash.hpp"
#include "device/stm32f0/gpio.hpp"
#include "device/stm32f0/nvic.hpp"
#include "device/stm32f0/rcc.hpp"
#include "device/stm32f0/tim.hpp"

#endif

