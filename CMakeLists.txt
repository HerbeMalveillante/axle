cmake_minimum_required(VERSION 3.15)  # Minimum version of CMake required
project(Axle)  # Name of the project

set(CMAKE_CXX_STANDARD 11)  # Set the C++ standard



# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
