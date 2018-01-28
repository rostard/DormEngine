//
// Created by rostard on 20.12.17.
//

#include <cmath>
#include "Quaternion.h"


Quaternion::Quaternion() : x(0), y(0), z(0), w(1) {}

Quaternion::Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Quaternion::Quaternion(const Vector3f &axis, float angle) {
    Vector3f normalizedAxis = axis.normalized();

    auto sinHalfAngle = static_cast<float>(std::sin(angle / 2.0));
    auto cosHalfAngle = static_cast<float>(std::cos(angle / 2.0));

    x = normalizedAxis.getX() * sinHalfAngle;
    y = normalizedAxis.getY() * sinHalfAngle;
    z = normalizedAxis.getZ() * sinHalfAngle;
    w = cosHalfAngle;
}


float Quaternion::length() const {
    return std::sqrt(x*x +y*y + z*z + w*w);
}

Quaternion Quaternion::normalized() {
    float length = this->length();

    float x = this->x / length;
    float y = this->y / length;
    float z = this->z / length;
    float w = this->w / length;

    return Quaternion(x, y, z, w);
}

Quaternion Quaternion::conjugate() const {
    return Quaternion(-x, -y, -z, w);
}

Matrix4f Quaternion::toRotationMatrix() const {
    Vector3f forward(2.0f * (x * z - w * y), 2.0f * (y * z + w * x), 1.0f - 2.0f * (x * x + y * y));
    Vector3f up(2.0f * (x * y + w * z), 1.0f - 2.0f * (x * x + z * z), 2.0f * (y * z - w * x));
    Vector3f right(1.0f - 2.0f * (y * y + z * z), 2.0f * (x * y - w * z), 2.0f * (x * z + w * y));

    return Matrix4f().initRotation(forward, up, right);
}

Vector3f Quaternion::getForward() const {
    return Vector3f(0.0f, 0.0f, 1.0f).rotate(*this);
}

Vector3f Quaternion::getBack() const{
    return Vector3f(0.0f, 0.0f, -1.0f).rotate(*this);
}

Vector3f Quaternion::getUp() const {
    return Vector3f(0.0f, 1.0f, 0.0f).rotate(*this);
}

Vector3f Quaternion::getDown() const {
    return Vector3f(0.0f, -1.0f, 0.0f).rotate(*this);
}

Vector3f Quaternion::getLeft() const {
    return Vector3f(-1.0f, 0.0f, 0.0f).rotate(*this);
}

Vector3f Quaternion::getRight() const {
    return Vector3f(1.0f, 0.0f, 0.0f).rotate(*this);
}

float Quaternion::getX() const {
    return x;
}

void Quaternion::setX(float x) {
    Quaternion::x = x;
}

float Quaternion::getY() const {
    return y;
}

void Quaternion::setY(float y) {
    Quaternion::y = y;
}

float Quaternion::getZ() const {
    return z;
}

void Quaternion::setZ(float z) {
    Quaternion::z = z;
}

float Quaternion::getW() const {
    return w;
}

void Quaternion::setW(float w) {
    Quaternion::w = w;
}

Quaternion Quaternion::operator*(const Quaternion &r) const {
    float x = this->x * r.w + this->w * r.x + this->y * r.z - this->z * r.y;
    float y = this->y * r.w + this->w * r.y + this->z * r.x - this->x * r.z;
    float z = this->z * r.w + this->w * r.z + this->x * r.y - this->y * r.x;
    float w = this->w * r.w - this->x * r.x - this->y * r.y - this->z * r.z;

    return Quaternion(x, y, z, w);
}

Quaternion Quaternion::operator*(const Vector3f &r) const {
    float w = -this->x * r.getX() - this->y * r.getY() - this->z * r.getZ();
    float x = this->w * r.getX() + this->y * r.getZ()  - this->z * r.getY();
    float y = this->w * r.getY() + this->z * r.getX() - this->x * r.getZ();
    float z = this->w * r.getZ() + this->x * r.getY() - this->y * r.getX();

    return Quaternion(x, y, z, w);
}

bool Quaternion::operator==(const Quaternion &r) const{
    return x == r.x && y == r.y && z == r.z && w == r.w;
}

bool Quaternion::operator!=(const Quaternion &r) const{
    return x != r.x || y != r.y || z != r.z || w != r.w;
}




