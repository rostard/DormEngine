//
// Created by rostard on 20.12.17.
//

#ifndef DORMENGINE_QUATERNION_H
#define DORMENGINE_QUATERNION_H

#include "Vector3f.h"
#include "Matrix4f.h"

class Quaternion {
public:
    Quaternion(float x, float y, float z, float w);


    float length() const{
        return std::sqrt(x*x +y*y + z*z + w*w);
    }

    Quaternion normalized(){
        float length = this->length();

        float x = this->x / length;
        float y = this->y / length;
        float z = this->z / length;
        float w = this->w / length;

        return Quaternion(x, y, z, w);
    }

    Quaternion conjugate() const{
        return Quaternion(-x, -y, -z, w);
    }

    Matrix4f toRotationMatrix() const{
        return Matrix4f().initRotation(getForward(), getUp(), getRight());
    }


    Vector3f getForward() const{
        return Vector3f(0.0f, 0.0f, 1.0f).rotate(*this);
    }

    Vector3f getBack(){
        return Vector3f(0.0f, 0.0f, -1.0f).rotate(*this);
    }

    Vector3f getUp() const{
        return Vector3f(0.0f, 1.0f, 0.0f).rotate(*this);
    }

    Vector3f getDown() const{
        return Vector3f(0.0f, -1.0f, 0.0f).rotate(*this);
    }

    Vector3f getLeft() const{
        return Vector3f(-1.0f, 0.0f, 0.0f).rotate(*this);
    }

    Vector3f getRight() const{
        return Vector3f(1.0f, 0.0f, 0.0f).rotate(*this);
    }

    Quaternion operator*(const Quaternion& r) const{
        float x = this->x * r.w + this->w * r.x + this->y * r.z - this->z * r.y;
        float y = this->y * r.w + this->w * r.y + this->z * r.x - this->x * r.z;
        float z = this->z * r.w + this->w * r.z + this->x * r.y - this->y * r.x;
        float w = this->w * r.w - this->x * r.x - this->y * r.y - this->z * r.z;

        return Quaternion(x, y, z, w);
    }

    Quaternion operator*(const Vector3f& r) const{
        float w = -this->x * r.getX() - this->y * r.getY() - this->z * r.getZ();
        float x = this->w * r.getX() + this->y * r.getZ()  - this->z * r.getY();
        float y = this->w * r.getY() + this->z * r.getX() - this->x * r.getZ();
        float z = this->w * r.getZ() + this->x * r.getY() - this->y * r.getX();

        return Quaternion(x, y, z, w);
    }

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getZ() const;

    void setZ(float z);

    float getW() const;

    void setW(float w);

private:
    float x;
    float y;
    float z;
    float w;
};


#endif //DORMENGINE_QUATERNION_H
