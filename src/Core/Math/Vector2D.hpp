#pragma once

#include <math.h>

namespace Agrume {

class Vector2D 
{
public: 

    float x;
    float y;

    Vector2D(const float x = 0, const float y = 0);
    ~Vector2D();

    Vector2D operator+(const Vector2D& vector) const;
    Vector2D operator-(const Vector2D& vector) const;
    Vector2D operator*(const float& num) const;
    Vector2D operator*(const Vector2D& vector) const;
    Vector2D operator/ (const float& num) const;
    Vector2D operator/(const Vector2D& vector) const;

    void operator+=(const Vector2D& vector);
    void operator-=(const Vector2D& vector);
    void operator*=(const float& num);
    void operator/=(const float& num);
    void operator=(const Vector2D& vector);
    bool operator==(const Vector2D& vector) const;
    bool operator!=(const Vector2D& vector) const;

    void clamp(const float& value);
    void normalize(const float& value = 1.0f);
    void invert();

    float length() const;
    Vector2D copy() const;

    static Vector2D cartesian(const float& x, const float& y);
    static Vector2D polar(const float& radius, const float& angle);
    static float dot(const Vector2D& vector1, const Vector2D& vector2);
    static Vector2D rotate(const Vector2D& vector, const float& angle);
    static const Vector2D ZERO;
};

}