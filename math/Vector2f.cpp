//
// Created by rostard on 20.12.17.
//

#include "Vector2f.h"

Vector2f::Vector2f() : x(0.0f), y(0.0f) {}
Vector2f::Vector2f(float x, float y) : x(x), y(y) {}

float Vector2f::length() {
    return std::sqrt(x*x + y*y);
}

Vector2f Vector2f::normalized() {
    return {x / this->length(), y / this->length()};
}

float Vector2f::dot(const Vector2f& r) {
    return x * r.x + y * r.y;
}

Vector2f Vector2f::lerp(const Vector2f &dest, float lerpFactor) const {
    return (dest - *this) * lerpFactor + *this;
}

Vector2f Vector2f::rotate(const float angle) {
    double rad = angle * (M_PI / 180.0);
    double cos = std::cos(rad);
    double sin = std::sin(rad);

    return Vector2f(float(x * cos - y * sin), float(x * sin + y * cos));
}


float Vector2f::max() const {
    return x > y ? x : y;
}

float Vector2f::getX() const {
    return x;
}

void Vector2f::setX(float x) {
    Vector2f::x = x;
}

float Vector2f::getY() const {
    return y;
}

void Vector2f::setY(float y) {
    Vector2f::y = y;
}

Vector2f Vector2f::operator+(const Vector2f &r) const{
    return Vector2f(x+r.x, y+r.y);
}

Vector2f Vector2f::operator+(float val) const{
    return Vector2f(x+val, y+val);
}

Vector2f Vector2f::operator-(const Vector2f &r) const{
    return Vector2f(x-r.x, y-r.y);
}

Vector2f Vector2f::operator-(float val) const{
    return Vector2f(x-val, y-val);
}

Vector2f Vector2f::operator*(const float val) const{
    return Vector2f(x*val, y*val);
}

Vector2f Vector2f::operator/(float val) const{
    return Vector2f(x/val, y/val);
}

bool Vector2f::operator==(const Vector2f &r) const {
    return x == r.x && y == r.y;
}

