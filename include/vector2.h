#ifndef AXLE_MATH_VECTOR2_H
#define AXLE_MATH_VECTOR2_H

namespace Axle::Math
{
    /**
     * @brief A 2D Vector class
     */
    class Vector2
    {
    public:
        /**
         * @brief The x component of the vector
         */
        double x;
        /**
         * @brief The y component of the vector
         */
        double y;

        /**
         * @brief Construct a new Vector2 object with x and y set to 0
         */
        Vector2();

        /**
         * @brief Construct a new Vector2 object with the given x and y values
         *
         * @param x The x component of the vector
         * @param y The y component of the vector
         */
        Vector2(double x, double y);

        /**
         * @brief Operator overload for addition
         *
         * @param other The other vector to add
         * @return Vector2 The result of the addition
         */
        Vector2 operator+(const Vector2 &other) const;

        /**
         * @brief Operator overload for subtraction
         *
         * @param other The other vector to subtract
         * @return Vector2 The result of the subtraction
         */
        Vector2 operator-(const Vector2 &other) const;

        /**
         * @brief Operator overload for scalar multiplication
         *
         * @param scalar The scalar to multiply by
         * @return Vector2 The result of the multiplication
         */
        Vector2 operator*(double scalar) const;

        /**
         * @brief Operator overload for scalar division
         *
         * @param scalar The scalar to divide by
         * @return Vector2 The result of the division
         */
        Vector2 operator/(double scalar) const;

        /**
         * @brief Operator overload for addition assignment
         *
         * @param other The other vector to add
         * @return Vector2& The result of the addition
         */
        Vector2 &operator+=(const Vector2 &other);

        /**
         * @brief Operator overload for subtraction assignment
         *
         * @param other The other vector to subtract
         * @return Vector2& The result of the subtraction
         */
        Vector2 &operator-=(const Vector2 &other);

        /**
         * @brief Operator overload for scalar multiplication assignment
         *
         * @param scalar The scalar to multiply by
         * @return Vector2& The result of the multiplication
         */
        Vector2 &operator*=(double scalar);

        /**
         * @brief Operator overload for scalar division assignment
         *
         * @param scalar The scalar to divide by
         * @return Vector2& The result of the division
         */
        Vector2 &operator/=(double scalar);

        /**
         * @brief Operator overload for equality
         *
         * @param other The other vector to compare
         * @return true If the vectors are equal
         * @return false If the vectors are not equal
         */
        bool operator==(const Vector2 &other) const;

        /**
         * @brief Operator overload for inequality
         *
         * @param other The other vector to compare
         * @return true If the vectors are not equal
         * @return false If the vectors are equal
         */
        bool operator!=(const Vector2 &other) const;

        /**
         * @brief Operator overload for negation
         *
         * @return Vector2 The negated vector
         */
        Vector2 operator-() const;
    };
}

#endif // AXLE_MATH_VECTOR2_H
