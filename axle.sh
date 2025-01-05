#!/bin/bash

# Name : build.sh
# Author : HerbeMalveillante
# Created : 04/01/2025
# Description : Axle toolchain, to build and install the library and required components.

# Add a config variable that dictates if the axle/raylib folder should be removed when cleaning
set -e

SHOULD_REMOVE_RAYLIB=false

clean () {
    echo "Cleaning up..."

    # Removing the raylib folder
    if [ -d "axle/raylib" ]; then
        if [ "$SHOULD_REMOVE_RAYLIB" = true ]; then
            rm -rf axle/raylib
        fi
    fi

    # Removing the CMakelists.txt file
    if [ -f "CMakeLists.txt" ]; then
        rm CMakeLists.txt
    fi

    # Removing the build folder
    if [ -d "build" ]; then
        rm -rf build
    fi

    echo "Done."
}

init () {
    clean
    echo "Installing Axle..."

    # Clone raylib if it doesn't exist
    if [ ! -d "axle/raylib" ]; then
        echo "Downloading raylib..."
        git clone https://github.com/raysan5/raylib.git axle/raylib
    fi

    # Remove useless files and folders from the raylib folder to reduce the size of the project
    rm -rf axle/raylib/.git
    rm -rf axle/raylib/.github
    rm -rf axle/raylib/examples
    rm -rf axle/raylib/logo
    rm -rf axle/raylib/parser
    rm -rf axle/raylib/projects
    rm -rf axle/raylib/.gitignore
    rm -rf axle/raylib/BINDINGS.md
    rm -rf axle/raylib/build.zig
    rm -rf axle/raylib/build.zig.zon
    rm -rf axle/raylib/CHANGELOG
    rm -rf axle/raylib/CONTRIBUTING.md
    rm -rf axle/raylib/CONVENTIONS.md
    rm -rf axle/raylib/FAQ.md
    rm -rf axle/raylib/HISTORY.md
    rm -rf axle/raylib/ROADMAP.md

    # Note : for some reason, removing the README.md file causes the project to not compile.


    # Copying the CMakeLists.template.txt file to the root folder, as CMakeLists.txt
    cp axle/CMakeLists.template.txt CMakeLists.txt
    echo "Done."
}


build () {
    echo "Building Your Project..."

    # Create a build folder if it doesn't exist
    if [ ! -d "build" ]; then
        mkdir build
    fi

    cd build
    cmake .. -Wno-dev
    cmake --build .
    cd ..
}


run () {
    build
    echo "Running Your Project..."
    ./build/axle_app
}

docs () {
    build
    echo "Generating Documentation..."
    doxygen -q axle/Doxyfile
}

# Check if the folder the command was launched in is the root folder.
# To do this, we can check
# - If the active folder is NOT named "axle"
# - If the active folder contains a "axle" directory
# This is to avoid axle's CMakelists.txt file to be removed by the clean command.
if [ "$(basename "$(pwd)")" == "axle" ] || [ ! -d "axle" ]; then
    echo "Please run this script from the root folder."
    exit 1
fi



# Check for a "axle.sh" script in the root folder.
# If it doesn't exist, create the shortcut script.
if [ ! -f "axle.sh" ]; then
    # Create a bash script in the root folder, used as a shortcut to this script.
    # This shortcut should forward all arguments to this script.
    echo "#!/bin/bash" > axle.sh
    echo "bash axle/axle.sh \$@" >> axle.sh
    chmod +x axle.sh

    echo "Shortcut script created. You can now use './axle.sh' to run this script."
fi



# Check for a "clean" argument.
if [ "$1" == "clean" ]; then
    clean
    exit 0
fi

# Check for a "install" argument.
if [ "$1" == "init" ]; then
    init
    exit 0
fi

# Check for a "build" argument.
if [ "$1" == "build" ]; then
    build
    exit 0
fi

# Check for a "run" argument.
if [ "$1" == "run" ]; then
    run
    exit 0
fi

# Check for a "docs" argument.
if [ "$1" == "docs" ]; then
    docs
    exit 0
fi

# Check for a "help" argument.
if [ "$1" == "help" ]; then
    RED='\033[0;31m'
    YLW='\033[1;33m'
    NC='\033[0m'

    echo ""
    echo "| ======================================================================================= |"
    echo -e "|                                  ${YLW}Axle Toolchain script${NC}                                  |"
    echo -e "| ${RED}Author${NC}  : HerbeMalveillante                                                             |"
    echo -e "| ${RED}Version${NC} : 0.1.0                                                                         |"
    echo -e "| ${RED}Site${NC}    : https://github.com/herbemalveillante/axle                                     |"
    echo "| ======================================================================================= |"
    echo "|                                                                                         |"
    echo -e "| ${RED}NOTE${NC} :                                                                                  |"
    echo "|  - Using this script for the first time will create                                     |"
    echo "|    a shortcut script in the root directory.                                             |"
    echo -e "|  - This script should ${RED}NOT${NC} be used from anywhere else                                    |"
    echo "|    than the root directory of the project.                                              |"
    echo "|                                                                                         |"
    echo "| --------------------------------------------------------------------------------------- |"
    echo "|                                                                                         |"
    echo -e "| ${RED}USAGE${NC} : ./axle.sh [build|clean|docs|help|init|run]                                      |"
    echo -e "|   ${YLW}build${NC} : Build the project without running it.                                         |"
    echo -e "|   ${YLW}clean${NC} : Clean the build folder to remove the compiled files and CMake cache.          |"
    echo -e "|   ${YLW}docs${NC}  : Generate Axle documentation using Doxygen.                                    |"
    echo -e "|   ${YLW}help${NC}  : Display this help message.                                                    |"
    echo -e "|   ${YLW}init${NC}  : Install Raylib and configure the project for building.                        |"
    echo -e "|   ${YLW}run${NC}   : Build and run the project.                                                    |"
    echo "|                                                                                         |"
    echo "| ======================================================================================= |"
    echo ""

    exit 0
fi

# Display the help message if the argument is invalid.
echo "Usage : ./axle.sh [build|clean|docs|help|init|run]"
echo "Use the 'help' argument for more information."
