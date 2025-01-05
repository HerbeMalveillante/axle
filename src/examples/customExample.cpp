#include <iostream>
#include "axle.h"

namespace Axle::Examples
{
    void customExample()
    {
        Axle::Window window(800, 450, "Axle example - custom");
        window.setTargetFPS(60);

        // Print the set FPS to the console
        std::cout << "Target FPS: " << window.getTargetFPS() << std::endl;
        window.close();
    }
} // namespace Axle::Examples
