#include "raylib.h"
#include "hello.h"

namespace axle
{
    void axleHelloWorld()
    {
        InitWindow(800, 600, "Hello From Axle");
        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hello from Axle !", 190, 200, 20, DARKGRAY);
            EndDrawing();
        }
        CloseWindow();
    }
}
