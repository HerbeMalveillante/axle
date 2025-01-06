#ifndef AXLE_MATH_VECTOR2_H
#define AXLE_MATH_VECTOR2_H

namespace Axle::Math
{
    class Vector2
    {
    public:
        double x;
        double y;

        Vector2();
        Vector2(double x, double y);

        // Operator overload for addition
        Vector2 operator+(const Vector2 &other) const;
        // Operator overload for subtraction
        Vector2 operator-(const Vector2 &other) const;
        // Operator overload for scalar multiplication
        Vector2 operator*(double scalar) const;
        // Operator overload for scalar division
        Vector2 operator/(double scalar) const;

        // Operator overload for addition assignment
        Vector2 &operator+=(const Vector2 &other);
        // Operator overload for subtraction assignment
        Vector2 &operator-=(const Vector2 &other);
        // Operator overload for scalar multiplication assignment
        Vector2 &operator*=(double scalar);
        // Operator overload for scalar division assignment
        Vector2 &operator/=(double scalar);

        // Operator overload for equality
        bool operator==(const Vector2 &other) const;
        // Operator overload for inequality
        bool operator!=(const Vector2 &other) const;

        // Operator overload for unary minus
        Vector2 operator-() const;
    };
}

#endif // AXLE_MATH_VECTOR2_H
