#include "axle.h"

namespace Axle::Examples
{
    void basicWindow()
    {
        Axle::Window window(800, 450, "Axle example - basic window");
        window.setTargetFPS(60);

        while (!window.shouldClose())
        {
            window.beginDrawing();
            window.clearBackground(Axle::ColorPreset::LIGHTGRAY);
            window.drawText("Congrats ! You created your first window !", 190, 200, 20, Axle::ColorPreset::BLACK);
            window.endDrawing();
        }

        window.close();
    }
} // namespace Axle::Examples
