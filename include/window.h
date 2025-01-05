#ifndef AXLE_WINDOW_H
#define AXLE_WINDOW_H

#include "color.h"

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

        /**
         * @brief Setup the windows to start drawing.
         */
        void beginDrawing();

        /**
         * @brief Finish the drawing process and swap the buffers.
         */
        void endDrawing();

        /**
         * @brief Clear the window with a specific color.
         * @param r The red component of the color.
         * @param g The green component of the color.
         * @param b The blue component of the color.
         * @param a The alpha component of the color.
         */
        void clearBackground(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

        /**
         * @brief Clear the window with a specific color.
         * @param color The color to be used to clear the window.
         */
        void clearBackground(Color color);

        /**
         * @brief Draw some text on the window, using the default font
         * @param text The text to be drawn
         * @param x The x position of the text
         * @param y The y position of the text
         * @param fontSize The size of the font.
         * @param r The red component of the color.
         * @param g The green component of the color.
         * @param b The blue component of the color.
         * @param a The alpha component of the color.
         */
        void drawText(const char *text, int x, int y, int fontSize, unsigned char r, unsigned char g, unsigned char b, unsigned char a);

        /**
         * @brief Draw some text on the window, using the default font
         * @param text The text to be drawn
         * @param x The x position of the text
         * @param y The y position of the text
         * @param fontSize The size of the font.
         * @param color The color preset to be used.
         */
        void drawText(const char *text, int x, int y, int fontSize, Color color);
    };
} // namespace Axle

#endif // AXLE_WINDOW_H
