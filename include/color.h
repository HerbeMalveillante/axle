#ifndef AXLE_COLOR_H
#define AXLE_COLOR_H

namespace Axle
{

    /**
     * @brief This enum is used to represent a color preset that can later be used to replace a color object in many places.
     */
    enum class ColorPreset
    {
        /// 200, 200, 200, 255 (Light Gray)
        COLOR_LIGHTGRAY,
        /// 130, 130, 130, 255 (Gray)
        COLOR_GRAY,
        /// 80, 80, 80, 255 (Dark Gray)
        COLOR_DARKGRAY,
        /// 253, 249, 0, 255 (Yellow)
        COLOR_YELLOW,
        /// 255, 203, 0, 255 (Gold)
        COLOR_GOLD,
        /// 255, 161, 0, 255 (Orange)
        COLOR_ORANGE,
        /// 255, 109, 194, 255 (Pink)
        COLOR_PINK,
        /// 230, 41, 55, 255 (Red)
        COLOR_RED,
        /// 190, 33, 55, 255 (Maroon)
        COLOR_MAROON,
        /// 0, 228, 48, 255 (Green)
        COLOR_GREEN,
        /// 0, 158, 47, 255 (Lime)
        COLOR_LIME,
        /// 0, 117, 44, 255 (Dark Green)
        COLOR_DARKGREEN,
        /// 102, 191, 255, 255 (Sky Blue)
        COLOR_SKYBLUE,
        /// 0, 121, 241, 255 (Blue)
        COLOR_BLUE,
        /// 0, 82, 172, 255 (Dark Blue)
        COLOR_DARKBLUE,
        /// 200, 122, 255, 255 (Purple)
        COLOR_PURPLE,
        /// 135, 60, 190, 255 (Violet)
        COLOR_VIOLET,
        /// 112, 31, 126, 255 (Dark Purple)
        COLOR_DARKPURPLE,
        /// 211, 176, 131, 255 (Beige)
        COLOR_BEIGE,
        /// 127, 106, 79, 255 (Brown)
        COLOR_BROWN,
        /// 76, 63, 47, 255 (Dark Brown)
        COLOR_DARKBROWN,
        /// 255, 255, 255, 255 (White)
        COLOR_WHITE,
        /// 0, 0, 0, 255 (Black)
        COLOR_BLACK,
        /// 0, 0, 0, 0 (Blank / Transparent)
        COLOR_BLANK,
        /// 255, 0, 255, 255 (Magenta)
        COLOR_MAGENTA,
    };

    /**
     * @brief This class is used to represent a color in the RGBA format
     */
    class Color
    {
    private:
        unsigned char r,
            g,
            b,
            a;

    public:
        /**
         * @brief Construct a new Color object using RGBA values
         * @param r Red value (0-255)
         * @param g Green value (0-255)
         * @param b Blue value (0-255)
         * @param a Alpha value (0-255)
         */
        Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

        /**
         * @brief Construct a new Color object using RGB values
         * @param r Red value (0-255)
         * @param g Green value (0-255)
         * @param b Blue value (0-255)
         * @note The alpha value is set to 255
         */
        Color(unsigned char r, unsigned char g, unsigned char b);

        /**
         * @brief Construct a new Color object
         * @note The color is set to transparent (0, 0, 0, 0)
         */
        Color();

        /**
         * @brief Construct a new Color object using a preset
         * @param preset Color preset
         */
        Color(ColorPreset preset);

        /**
         * @brief Set the Red value of the color
         * @param r Red value (0-255)
         */
        void setR(unsigned char r);

        /**
         * @brief Set the Green value of the color
         * @param g Green value (0-255)
         */
        void setG(unsigned char g);

        /**
         * @brief Set the Blue value of the color
         * @param b Blue value (0-255)
         */
        void setB(unsigned char b);

        /**
         * @brief Set the Alpha value of the color
         * @param a Alpha value (0-255)
         */
        void setA(unsigned char a);

        /**
         * @brief Set the color of the object using RGBA values
         * @param r Red value (0-255)
         * @param g Green value (0-255)
         * @param b Blue value (0-255)
         * @param a Alpha value (0-255)
         */
        void setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

        /**
         * @brief Set the color of the object using a preset
         * @param preset Color preset
         */
        void setColor(ColorPreset preset);

        /**
         * @brief Get the Red value of the color
         * @return unsigned char Red value (0-255)
         */
        unsigned char getR() const;

        /**
         * @brief Get the Green value of the color
         * @return unsigned char Green value (0-255)
         */
        unsigned char getG() const;

        /**
         * @brief Get the Blue value of the color
         * @return unsigned char Blue value (0-255)
         */
        unsigned char getB() const;

        /**
         * @brief Get the Alpha value of the color
         * @return unsigned char Alpha value (0-255)
         */
        unsigned char getA() const;
    };
}

#endif // AXLE_COLOR_H
