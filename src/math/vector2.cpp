#include "vector2.h"

namespace Axle::Math
{

    Vector2::Vector2()
    {
        this->x = 0;
        this->y = 0;
    }

    Vector2::Vector2(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    // Operator overload for addition
    Vector2 Vector2::operator+(const Vector2 &other) const
    {
        return Vector2(this->x + other.x, this->y + other.y);
    }

    // Operator overload for subtraction
    Vector2 Vector2::operator-(const Vector2 &other) const
    {
        return Vector2(this->x - other.x, this->y - other.y);
    }

    // Operator overload for scalar multiplication
    Vector2 Vector2::operator*(double scalar) const
    {
        return Vector2(this->x * scalar, this->y * scalar);
    }

    // Operator overload for scalar division
    Vector2 Vector2::operator/(double scalar) const
    {
        return Vector2(this->x / scalar, this->y / scalar);
    }

    // Operator overload for addition assignment
    Vector2 &Vector2::operator+=(const Vector2 &other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    // Operator overload for subtraction assignment
    Vector2 &Vector2::operator-=(const Vector2 &other)
    {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    // Operator overload for scalar multiplication assignment
    Vector2 &Vector2::operator*=(double scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    // Operator overload for scalar division assignment
    Vector2 &Vector2::operator/=(double scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        return *this;
    }

    // Operator overload for equality
    bool Vector2::operator==(const Vector2 &other) const
    {
        return this->x == other.x && this->y == other.y;
    }

    // Operator overload for inequality
    bool Vector2::operator!=(const Vector2 &other) const
    {
        return !(*this == other);
    }

    // Operator overload for unary minus
    Vector2 Vector2::operator-() const
    {
        return Vector2(-this->x, -this->y);
    }
}
