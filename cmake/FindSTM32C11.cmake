IF(STM32_CHIP_TYPE OR STM32_CHIP)
    IF(NOT STM32_CHIP_TYPE)
        STM32_GET_CHIP_TYPE(${STM32_CHIP} STM32_CHIP_TYPE)
        IF(NOT STM32_CHIP_TYPE)
            MESSAGE(FATAL_ERROR "Unknown chip: ${STM32_CHIP}. Try to use STM32_CHIP_TYPE directly.")
        ENDIF()
        MESSAGE(STATUS "${STM32_CHIP} is ${STM32_CHIP_TYPE} device")
    ENDIF()
    STRING(TOLOWER ${STM32_CHIP_TYPE} STM32_CHIP_TYPE_LOWER)
ENDIF()

SET(STM32C11_COMMON_HEADERS
    exception.hpp
)

SET(STM32C11_COMMON_SOURCES
    startup.cpp
    exception.cpp
)

FIND_PATH(STM32C11_COMMON_INCLUDE_DIR ${STM32C11_COMMON_HEADERS}
    HINTS ${STM32_CMAKE_DIR}/..
    CMAKE_FIND_ROOT_PATH_BOTH
)

SET(STM32C11_INCLUDE_DIRS
    ${STM32C11_COMMON_INCLUDE_DIR}
    ${STM32C11_COMMON_INCLUDE_DIR}/core
    ${STM32C11_COMMON_INCLUDE_DIR}/peripherals
)

FOREACH(SRC ${STM32C11_COMMON_SOURCES})
    SET(SRC_FILE SRC_FILE-NOTFOUND)
    FIND_FILE(SRC_FILE ${SRC}
        HINTS ${STM32_CMAKE_DIR}/../
        CMAKE_FIND_ROOT_PATH_BOTH
    )
    LIST(APPEND STM32C11_SOURCES ${SRC_FILE})
ENDFOREACH()

message(STATUS "stm32c11 include " ${STM32C11_INCLUDE_DIRS})
message(STATUS "stm32c11 sources " ${STM32C11_SOURCES})

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(STM32C11 DEFAULT_MSG STM32C11_INCLUDE_DIRS STM32C11_SOURCES)