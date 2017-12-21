//
// Created by rostard on 20.12.17.
//

#include "Vector3f.h"
#include "Quaternion.h"

Vector3f::Vector3f(): x(0.0f), y(0.0f), z(0.0f) {}
Vector3f::Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}

float Vector3f::length() const{
    return std::sqrt(x*x + y*y + z*z);
}

Vector3f Vector3f::normalized() const{
    return {x / this->length(), y / this->length(), z / this->length()};
}

float Vector3f::dot(Vector3f r) {
    return x * r.x + y * r.y + z * r.z;
}

Vector3f Vector3f::cross(const Vector3f &r) const{
    float x = this->y * r.z - this->z * r.y;
    float y = this->z * r.x - this->x * r.z;
    float z = this->x * r.y - this->y * r.x;

    return Vector3f(x, y, z);
}

float Vector3f::getX() const {
    return x;
}

void Vector3f::setX(float x) {
    Vector3f::x = x;
}

float Vector3f::getY() const {
    return y;
}

void Vector3f::setY(float y) {
    Vector3f::y = y;
}

float Vector3f::getZ() const {
    return z;
}

void Vector3f::setZ(float z) {
    Vector3f::z = z;
}

Vector3f Vector3f::operator+(const Vector3f &r) {
    return Vector3f(x + r.x, y + r.y, z + r.z);
}

Vector3f Vector3f::operator+(float val) {
    return Vector3f(x + val, y + val, z + val);
}

Vector3f Vector3f::operator-(const Vector3f &r) {
    return Vector3f(x - r.x, y - r.y, z - r.z);
}

Vector3f Vector3f::operator-(float val) {
    return Vector3f(x - val, y - val, z - val);
}

Vector3f Vector3f::operator*(float val) {
    return Vector3f(x * val, y * val, z * val);
}

Vector3f Vector3f::operator/(float val) {
    return Vector3f(x / val, y / val, z / val);
}

Vector3f Vector3f::rotate(const Vector3f &axis, float angle) {
    double sinHalfAngle = std::sin(angle * (180.0 * M_PI) / 2.0);
    double cosHalfAngle = std::cos(angle * (180.0 * M_PI) / 2.0);

    double rX = axis.getX() * sinHalfAngle;
    double rY = axis.getY() * sinHalfAngle;
    double rZ = axis.getZ() * sinHalfAngle;
    double rW = cosHalfAngle;

    Quaternion rotation(rX, rY, rZ, rW);
    Quaternion conjugate = rotation.conjugate();

    Quaternion w = (rotation * *this) * conjugate;

    x = w.getX();
    y = w.getY();
    z = w.getZ();

    return *this;


}

void Vector3f::operator+=(const Vector3f &r) {
    x += r.x;
    y += r.y;
    z += r.z;
}

