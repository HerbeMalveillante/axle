#include "examples.h"
#include "window.h"

namespace Axle::Examples
{
    void basicWindow()
    {
        Axle::Window window(800, 450, "Axle example - basic window");
        window.setTargetFPS(60);

        while (!window.shouldClose())
        {
            window.beginDrawing();
            window.clearBackground(255, 255, 255, 255);
            window.drawText("Congrats ! You created your first window !", 190, 200, 20, 0, 0, 0, 255);
            window.endDrawing();
        }

        window.close();
    }
} // namespace Axle::Examples
