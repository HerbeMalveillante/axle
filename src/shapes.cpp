#include "shapes.h"
#include "vector2.h"
#include "color.h"
#include "raylib.h"

namespace Axle
{
    Shape::Shape()
    {
        this->color = Color(ColorPreset::COLOR_WHITE);
        this->position = Math::Vector2();
    }

    Rectangle::Rectangle(int x, int y, int width, int height)
    {
        this->position = Math::Vector2(x, y);
        this->width = width;
        this->height = height;
    }

    Rectangle::Rectangle(Math::Vector2 position, int width, int height)
    {
        this->position = position;
        this->width = width;
        this->height = height;
    }

    Rectangle::Rectangle(Math::Vector2 topLeft, Math::Vector2 bottomRight)
    {
        // Check if the top left is actually the top left
        if (topLeft.x > bottomRight.x)
        {
            int temp = topLeft.x;
            topLeft.x = bottomRight.x;
            bottomRight.x = temp;
        }

        if (topLeft.y > bottomRight.y)
        {
            int temp = topLeft.y;
            topLeft.y = bottomRight.y;
            bottomRight.y = temp;
        }

        // The position is the center of the rectangle
        this->position = topLeft + (bottomRight - topLeft) / 2;
        this->width = bottomRight.x - topLeft.x;
        this->height = bottomRight.y - topLeft.y;
    }

    void Rectangle::Draw() const
    {
        // Do nothing for now
    }
}
