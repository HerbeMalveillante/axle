#!/bin/bash

# Name : build.sh
# Author : HerbeMalveillante
# Created : 04/01/2025
# Description : Axle toolchain, to build and install the library and required components.


clean () {
    echo "Cleaning up..."
    rm -rf build
    rm -rf external/axle/raylib
    echo "Done."
}

install () {
    echo "Installing Axle..."

    # Create a build folder if it doesn't exist.
    if [ ! -d "build" ]; then
        mkdir build
    fi

    # Create a lib folder if it doesn't exist.
    if [ ! -d "lib" ]; then
        mkdir lib
    fi

    # Download raylib in the external folder.
    if [ ! -d "external/axle/raylib" ]; then
        git clone https://github.com/raysan5/raylib.git external/axle/raylib

        # Remove unused files.
        rm -rf external/axle/raylib/.git
        rm -rf external/axle/raylib/.github
        rm -rf external/axle/raylib/examples
        rm -rf external/axle/raylib/logo
        rm -rf external/axle/raylib/parser
        rm -rf external/axle/raylib/projects
        rm -rf external/axle/raylib/.gitignore
        rm -rf external/axle/raylib/BINDINGS.md
        rm -rf external/axle/raylib/build.zig
        rm -rf external/axle/raylib/build.zig.zon
        rm -rf external/axle/raylib/CHANGELOG
        rm -rf external/axle/raylib/CONTRIBUTING.md
        rm -rf external/axle/raylib/CONVENTIONS.md
        rm -rf external/axle/raylib/FAQ.md
        rm -rf external/axle/raylib/HISTORY.md
        rm -rf external/axle/raylib/raylib.pc.in
        rm -rf external/axle/raylib/README.md
        rm -rf external/axle/raylib/ROADMAP.md
    fi
}

build () {
    echo "Building Axle..."
    cd external/axle/build
    cmake ..
    exit 0
}

run () {
    echo "Running Axle..."
}

# Check for a "axle.sh" script in the root folder.
# If it doesn't exist, create the shortcut script.
if [ ! -f "axle.sh" ]; then
    # Create a bash script in the root folder, used as a shortcut to this script.
    # This shortcut should forward all arguments to this script.
    echo "#!/bin/bash" > axle.sh
    echo "bash external/axle/axle.sh \$@" >> axle.sh
    chmod +x axle.sh

    echo "Shortcut script created. You can now use './axle.sh' to run this script."
fi

# Display the help message if no argument is provided.
if [ "$1" == "" ]; then
    echo "Usage : ./axle.sh [clean|install|build|run]"
    exit 0
fi

# Check for a "clean" argument.
if [ "$1" == "clean" ]; then
    clean
    exit 0
fi

# Check for a "install" argument.
if [ "$1" == "install" ]; then
    install
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
