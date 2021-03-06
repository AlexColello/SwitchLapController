cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico_examples C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

include(./build/RF24/CMakeLists.txt)

add_executable(controller
        controller.cpp
        )

pico_set_program_name(controller "controller")
pico_set_program_version(controller "0.1")

pico_enable_stdio_uart(controller 0)
pico_enable_stdio_usb(controller 1)


# Pull in our (to be renamed) simple get you started dependencies
target_link_libraries(controller 
        pico_stdlib 
        hardware_i2c
        hardware_spi
        RF24
)

# create map/bin/hex file etc.
pico_add_extra_outputs(controller)

