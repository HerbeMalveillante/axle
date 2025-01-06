#ifndef AXLE_SHAPES_H
#define AXLE_SHAPES_H

#include "vector2.h"
#include "color.h"

namespace Axle
{
    class Shape
    {
    protected:
        Shape();

    private:
    public:
        Axle::Color color;
        Axle::Math::Vector2 position;
        virtual void Draw() const = 0;

        virtual ~Shape() = default; // Virtual destructor for proper cleanup
    };

    class Rectangle : public Shape
    {
    private:
        int width;
        int height;

    public:
        Rectangle(int x, int y, int width, int height);
        Rectangle(Axle::Math::Vector2 position, int width, int height);
        Rectangle(Axle::Math::Vector2 topLeft, Axle::Math::Vector2 bottomRight);
        void Draw() const override;
    };
}

#endif // AXLE_SHAPES_H
