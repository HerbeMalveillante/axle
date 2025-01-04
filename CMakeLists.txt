cmake_minimum_required(VERSION 3.15)
project(Axle)

set(CMAKE_CXX_STANDARD 17)

# Add Raylib as a subdirectory
add_subdirectory(raylib)

# Create a static library from the source files
add_library(axle STATIC
    src/hello.cpp
)

# Specify the include directoriy for the axle library
target_include_directories(axle PUBLIC ${CMAKE_SOURCE_DIR}/axle/include)

# Link the library with Raylib
target_link_libraries(axle PRIVATE raylib)
