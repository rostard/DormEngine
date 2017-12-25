//
// Created by rostard on 18.12.17.
//

#ifndef DORMENGINE_TRANSFORM_H
#define DORMENGINE_TRANSFORM_H


#include "Matrix4f.h"
#include "Camera.h"
#include "Quaternion.h"

class Transform {
public:
    Transform();

    Matrix4f getTransformation() const;

    Matrix4f getProjectedTransformation(const Camera& camera) const;

    const Vector3f &getPos() const;

    void setPos(const Vector3f &translation);

    void setPos(float x, float y, float z);

    const Quaternion &getRot() const;

    void setRot(const Quaternion &rotation);

    void setRot(float x, float y, float z, float w);

    const Vector3f &getScale() const;

    void setScale(const Vector3f &scale);

    void setScale(float x, float y, float z);


private:

    Vector3f pos;
    Quaternion rot;
    Vector3f scale;

};


#endif //DORMENGINE_TRANSFORM_H
