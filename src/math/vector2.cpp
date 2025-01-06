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

    Vector2 Vector2::operator+(const Vector2 &other) const
    {
        return Vector2(this->x + other.x, this->y + other.y);
    }

    Vector2 Vector2::operator-(const Vector2 &other) const
    {
        return Vector2(this->x - other.x, this->y - other.y);
    }

    Vector2 Vector2::operator*(double scalar) const
    {
        return Vector2(this->x * scalar, this->y * scalar);
    }

    Vector2 Vector2::operator/(double scalar) const
    {
        return Vector2(this->x / scalar, this->y / scalar);
    }

    Vector2 &Vector2::operator+=(const Vector2 &other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Vector2 &Vector2::operator-=(const Vector2 &other)
    {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    Vector2 &Vector2::operator*=(double scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    Vector2 &Vector2::operator/=(double scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        return *this;
    }

    bool Vector2::operator==(const Vector2 &other) const
    {
        return this->x == other.x && this->y == other.y;
    }

    bool Vector2::operator!=(const Vector2 &other) const
    {
        return !(*this == other);
    }

    Vector2 Vector2::operator-() const
    {
        return Vector2(-this->x, -this->y);
    }
}
