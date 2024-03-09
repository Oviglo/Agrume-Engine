#include "Vector2D.hpp"

namespace Agrume {

const Vector2D Vector2D::ZERO = Vector2D();

Vector2D::Vector2D(const float x, const float y) : x(x), y(y) {

}

Vector2D::~Vector2D() {

}

inline Vector2D Vector2D::copy() const {
    return Vector2D(x, y);
}

inline bool Vector2D::operator==(const Vector2D& vector) const {
    return x == vector.x && y == vector.y;
}

inline bool Vector2D::operator!=(const Vector2D& vector) const {
    return x != vector.x || y != vector.y;
}

inline Vector2D Vector2D::operator+(const Vector2D& vector) const {
    return Vector2D(x + vector.x, y + vector.y);
}

inline Vector2D Vector2D::operator-(const Vector2D& vector) const {
    return Vector2D(x - vector.x, y - vector.y);
}

inline Vector2D Vector2D::operator*(const float& num) const {
    return Vector2D(x * num, y * num);
}

inline Vector2D Vector2D::operator*(const Vector2D& vector) const {
    return Vector2D(x * vector.x, y * vector.y);
}

inline Vector2D Vector2D::operator/(const float& num) const {
    return Vector2D(x / num, y / num);
}

inline Vector2D Vector2D::operator/(const Vector2D& vector) const {
    return Vector2D(x / vector.x, y / vector.y);
}

void Vector2D::operator+=(const Vector2D& vector) {
    x += vector.x;
    y += vector.y;
}

void Vector2D::operator-=(const Vector2D& vector) {
    x -= vector.x;
    y -= vector.y;
}

void Vector2D::operator*=(const float& num) {
    x *= num;
    y *= num;
}

void Vector2D::operator/=(const float& num) {
    x /= num;
    y /= num;
}

void Vector2D::operator=(const Vector2D& vector) {
    x = vector.x;
    y = vector.y;
}

float Vector2D::length() const {
    return sqrt(pow(x, 2.0f) + pow(y, 2.0f));
}

void Vector2D::clamp(const float& value) {
    if (length() <= value)
        return;
    normalize();
    *this *= value;
}

void Vector2D::normalize(const float& value) {
    float vecLength = length();
    if (vecLength == 0)
        return;
    
    x = x/vecLength * value;
    y = y/vecLength * value;
}

void Vector2D::invert() {
    x *= -1;
    y *= -1;
}

Vector2D Vector2D::Vector2D::polar(const float& x, const float& y)
{
    Vector2D vector = Vector2D();
    vector.x = atan2(y, x);
    vector.y = sqrt(x * x + y * y);
    return vector;
}

Vector2D Vector2D::cartesian(const float& radius, const float& angle)
{
    Vector2D vector = Vector2D();
    vector.x = radius * cos(angle);
    vector.y = radius * sin(angle);
    return vector;
}

float Vector2D::dot(const Vector2D& vector1, const Vector2D& vector2) {
    return vector1.x * vector2.x + vector1.y * vector2.y;
}

Vector2D Vector2D::rotate(const Vector2D& vector, const float& angle) {
    float cosResult = cos(angle);
    float sinResult = sin(angle);

    float newX = vector.x * cosResult - vector.y * sinResult;
    float newY = vector.x * sinResult + vector.y * cosResult;

    return Vector2D(newX, newY);
}

}