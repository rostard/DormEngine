//
// Created by rostard on 18.12.17.
//

#ifndef DORMENGINE_TRANSFORM_H
#define DORMENGINE_TRANSFORM_H


#include "Matrix4f.h"
#include "Camera.h"

class Transform {
public:
    Transform();

    Matrix4f getTransformation() const;

    Matrix4f getProjectedTransformation(const Camera& camera) const;

    const Vector3f &getTranslation() const;

    void setTranslation(const Vector3f &translation);

    void setTranslation(float x, float y, float z);

    const Vector3f &getRotation() const;

    void setRotation(const Vector3f &rotation);

    void setRotation(float x, float y, float z);

    const Vector3f &getScale() const;

    void setScale(const Vector3f &scale);

    void setScale(float x, float y, float z);


private:

    Vector3f translation;
    Vector3f rotation;
    Vector3f scale;

};


#endif //DORMENGINE_TRANSFORM_H
