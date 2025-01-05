#include "axle.h"
#include <iostream>

namespace Axle::Examples
{
    void custom()
    {
        Axle::Window window(800, 450, "Axle example - custom");
        window.setTargetFPS(60);

        // Print the set FPS to the console
        std::cout << "Target FPS: " << window.getTargetFPS() << std::endl;
        window.close();
    }
}
