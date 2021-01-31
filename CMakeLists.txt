cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(pico_example)

pico_sdk_init()

add_executable(
    example
    example.c
)

pico_enable_stdio_usb(example 1) # Enable USB Output
pico_enable_stdio_uart(example 1) # Enable UART Output

pico_add_extra_outputs(example)

target_link_libraries(example pico_stdlib)