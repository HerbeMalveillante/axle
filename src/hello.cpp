// axle/src/hello.cpp

#include <iostream>
#include "hello.h" // Include the header to define the function
#include "raylib.h"

void say_hello()
{
    SetTraceLogLevel(LOG_ERROR);
    // Raylib default window
    InitWindow(800, 600, "Hello, World!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, World!", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }
}
