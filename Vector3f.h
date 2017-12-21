//
// Created by rostard on 20.12.17.
//

#ifndef DORMENGINE_VECTOR3F_H
#define DORMENGINE_VECTOR3F_H


#include <cmath>

class Vector3f {
public:
    Vector3f();
    Vector3f(float x, float y, float z);

    float length() const;

    Vector3f normalized() const;

    Vector3f cross(const Vector3f& r) const;

    float dot(Vector3f r);

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getZ() const;

    void setZ(float z);


    Vector3f operator+(const Vector3f& r);
    Vector3f operator+(float val);

    Vector3f operator-(const Vector3f& r);
    Vector3f operator-(float val);

    Vector3f operator*(float val);
    Vector3f operator/(float val);

    void operator+=(const Vector3f& r);

    Vector3f rotate(const Vector3f &axis, float angle);

private:
    float x;
    float y;
    float z;
};


#endif //DORMENGINE_VECTOR3F_H