cmake_minimum_required(VERSION 3.15)
project(Axle)

set(CMAKE_CXX_STANDARD 17)
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_BUILD_TYPE Release)

# Add Raylib as a subdirectory
add_subdirectory(raylib)

file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")

# Create a static library from the source files
add_library(axle STATIC
    ${SOURCES}
)

# Specify the include directoriy for the axle library
target_include_directories(axle PUBLIC ${CMAKE_SOURCE_DIR}/axle/include)

# Link the library with Raylib
target_link_libraries(axle PRIVATE raylib)
