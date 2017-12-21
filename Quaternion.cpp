//
// Created by rostard on 20.12.17.
//

#include <cmath>
#include "Quaternion.h"

Quaternion::Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}


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
