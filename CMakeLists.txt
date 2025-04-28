cmake_minimum_required(VERSION 3.10)
project(ptom)

# Find zlib package
find_package(ZLIB REQUIRED)

# Add executable
add_executable(ptom
    code/main.c
    code/ptom.c
)

# Link against zlib
target_link_libraries(ptom PRIVATE ZLIB::ZLIB)

# Include directories
target_include_directories(ptom PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set C standard
set_property(TARGET ptom PROPERTY C_STANDARD 11)