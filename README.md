# STM32 C++11 Library

STM32C11 is a replace for CMSIS library writen in pure c++11 language

  - MMR by c++ templates
  - lower size for code
  - higher speed
  - f0 series(partial) support now

### Development plan

  - Increase structure of support f0 series
  - Add f3 series

### Tested toolchains
>gcc-arm-none-eabi-5_3-2016q1
>gcc-arm-none-eabi-6-2017-q2-update
>gcc-arm-none-eabi-8-2018-q4-major

### Usage

stm32c11 requires [CMake](https://cmake.org/) >2.8 to run.

Add git repository as submodule to your projects

```sh
$ cd project
$ git submodule add https://github.com/JocusSoft/stm32c11.git
```

Create CMakeLists.txt for your project like this

```cmake
PROJECT(sample)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
FIND_PACKAGE(STM32C11 REQUIRED)
INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${STM32C11_INCLUDE_DIRS}
)

SET(PROJECT_SOURCES
    main.cpp
)

ADD_EXECUTABLE(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES} ${STM32C11_SOURCES})

STM32_SET_TARGET_PROPERTIES(${CMAKE_PROJECT_NAME})
STM32_ADD_HEX_BIN_TARGETS(${CMAKE_PROJECT_NAME})
STM32_PRINT_SIZE_OF_TARGETS(${CMAKE_PROJECT_NAME})
```
Create build directory and run cmake
```sh
$ mkdir build
$ cd build
$ cmake -DSTM32_CHIP=<chip> -DCMAKE_TOOLCHAIN_FILE=stm32c11/cmake/stm32c11.cmake -DTOOLCHAIN_PREFIX=<path to toolchain> ..
```

### CMake params

 - STM32_CHIP - chip select(aka stm32f030r8t6)
 - TOOLCHAIN_PREFIX - path to toolchain

### Sample

[STM32C11 SAMPLE](https://github.com/JocusSoft/stm32c11sample)

License
----

APACHE FOUNDATION 2.0
