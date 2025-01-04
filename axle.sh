#!/bin/bash

# Name : build.sh
# Author : HerbeMalveillante
# Created : 04/01/2025
# Description : Axle toolchain, to build and install the library and required components.

# Check for a "clean" argument.
if [ "$1" == "clean" ]; then
    echo "Cleaning up..."
    rm -rf build
    rm -rf external
    exit 0
fi

# First, download and install raylib.
mkdir -p external/temp
# Clone raylib

git clone https://github.com/raysan5/raylib.git external/temp
