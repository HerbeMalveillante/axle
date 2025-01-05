#ifndef AXLE_WINDOW_H
#define AXLE_WINDOW_H

namespace Axle
{
    /**
     * @brief Represents a window that can be created and managed by the engine.
     */
    class Window
    {
    private:
        int targetFPS;

    public:
        /**
         * @brief Initialize window and OpenGL context.
         * @param width The width of the window.
         * @param height The height of the window.
         * @param title The title of the window.
         */
        Window(int width, int height, const char *title);

        /**
         * @brief Close window and unload OpenGL context.
         */
        void close();

        /**
         * @brief Checks if aplication should close (KEY_ESCAPE pressed or window close icon clicked).
         */
        bool shouldClose();

        /**
         * @brief Sets the maximum frames per second that the window should render.
         */
        void setTargetFPS(int fps);

        /**
         * @brief Returns the maximum frames per second that the window should render.
         */
        int getTargetFPS();

        void beginDrawing();

        void endDrawing();

        void clearBackground(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

        void drawText(const char *text, int x, int y, int fontSize, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    };
} // namespace Axle

#endif // AXLE_WINDOW_H
