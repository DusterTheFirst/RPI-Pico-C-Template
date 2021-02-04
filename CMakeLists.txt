cmake_minimum_required(VERSION 3.12)

# Include the glue for the pico SDK
include(pico_sdk_import.cmake)

# Setup the project
project(pico_example)

# Initialize the pico SDK
pico_sdk_init()

# Add the headers
include_directories(include)

# Get all of the c files in the src directory
file(GLOB SOURCES src/*.c) # replace .c with .cpp for a cpp project
add_executable(
    example
    ${SOURCES}
)

# Setup the compile time SDK options
pico_enable_stdio_usb(example 1)  # Enable USB Output
pico_enable_stdio_uart(example 1) # Enable UART Output

# Build the .uf2 and other files
pico_add_extra_outputs(example)

# Link with the pico SDK
target_link_libraries(example pico_stdlib)