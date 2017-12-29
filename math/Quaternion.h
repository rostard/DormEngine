//
// Created by rostard on 20.12.17.
//

#ifndef DORMENGINE_QUATERNION_H
#define DORMENGINE_QUATERNION_H

#include "Vector3f.h"
#include "Matrix4f.h"

class Quaternion {
public:
    Quaternion();

    Quaternion(float x, float y, float z, float w);

    Quaternion(const Vector3f &axis, float angle);

    float length() const;

    Quaternion normalized();

    Quaternion conjugate() const;

    Matrix4f toRotationMatrix() const;

    Vector3f getForward() const;

    Vector3f getBack() const;

    Vector3f getUp() const;

    Vector3f getDown() const;

    Vector3f getLeft() const;

    Vector3f getRight() const;

    Quaternion operator*(const Quaternion& r) const;

    Quaternion operator*(const Vector3f& r) const;

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getZ() const;

    void setZ(float z);

    float getW() const;

    void setW(float w);

    bool operator==(const Quaternion& r) const;
    bool operator!=(const Quaternion& r) const;
private:
    float x;
    float y;
    float z;
    float w;
};


#endif //DORMENGINE_QUATERNION_H
