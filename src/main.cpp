#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Raylib in MyLibrary");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello from MyLibrary with Raylib!", 190, 200, 20, DARKGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
