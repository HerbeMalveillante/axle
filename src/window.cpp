#include "window.h"
#include "raylib.h"
#include "color.h"

namespace Axle
{

    Window::Window(int width, int height, const char *title)
    {
        InitWindow(width, height, title);
    }

    void Window::close()
    {
        CloseWindow();
    }

    bool Window::shouldClose()
    {
        return WindowShouldClose();
    }

    void Window::setTargetFPS(int fps)
    {
        targetFPS = fps;
        SetTargetFPS(fps);
    }

    int Window::getTargetFPS()
    {
        return targetFPS;
    }

    void Window::beginDrawing()
    {
        BeginDrawing();
    }

    void Window::endDrawing()
    {
        EndDrawing();
    }

    void Window::clearBackground(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        ClearBackground({r, g, b, a});
    }

    void Window::clearBackground(Color color)
    {
        ClearBackground({color.getR(),
                         color.getG(),
                         color.getB(),
                         color.getA()});
    }

    void Window::drawText(const char *text, int x, int y, int fontSize, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        DrawText(text, x, y, fontSize, {r, g, b, a});
    }

    void Window::drawText(const char *text, int x, int y, int fontSize, Color color)
    {
        DrawText(text, x, y, fontSize, {color.getR(), color.getG(), color.getB(), color.getA()});
    }

} // namespace Axle
