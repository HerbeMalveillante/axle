#ifndef AXLE_SHAPES_H
#define AXLE_SHAPES_H

#include "vector2.h"
#include "color.h"

namespace Axle
{
    /**
     * @brief Base class for all shapes.
     *
     * This class is used to represent a shape that can be drawn on the screen.
     * It should not be instantiated directly, but rather be used as a base class for other shapes.
     */
    class Shape
    {
    protected:
        /**
         * @brief Construct a new Shape object
         *
         * This constructor is protected to prevent instantiation of the Shape class.
         *
         * The color is set to white and the position is set to (0, 0).
         */
        Shape();

    public:
        /**
         * @brief The color of the shape
         */
        Axle::Color color;

        /**
         * @brief The position of the center of the shape.
         */
        Axle::Math::Vector2 position;

        /**
         * @brief Draw the shape on the screen
         */
        virtual void Draw() const = 0;

        virtual ~Shape() = default; // Virtual destructor for proper cleanup
    };

    /**
     * @brief A class representing a rectangle
     */
    class Rectangle : public Shape
    {
    private:
        /**
         * @brief The width of the rectangle
         */
        int width;
        /**
         * @brief The height of the rectangle
         */
        int height;

    public:
        /**
         * @brief Construct a new Rectangle object
         *
         * @param x The x coordinate of the center of the rectangle
         * @param y The y coordinate of the center of the rectangle
         * @param width The width of the rectangle
         * @param height The height of the rectangle
         */
        Rectangle(int x, int y, int width, int height);

        /**
         * @brief Construct a new Rectangle object
         *
         * @param position The position of the center of the rectangle
         * @param width The width of the rectangle
         * @param height The height of the rectangle
         */
        Rectangle(Axle::Math::Vector2 position, int width, int height);

        /**
         * @brief Construct a new Rectangle object
         *
         * @param topLeft The top left corner of the rectangle
         * @param bottomRight The bottom right corner of the rectangle
         */
        Rectangle(Axle::Math::Vector2 topLeft, Axle::Math::Vector2 bottomRight);
        void Draw() const override;
    };
}

#endif // AXLE_SHAPES_H
