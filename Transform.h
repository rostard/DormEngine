//
// Created by rostard on 18.12.17.
//

#ifndef DORMENGINE_TRANSFORM_H
#define DORMENGINE_TRANSFORM_H


#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include "Matrix4f.h"
#include "Vector3f.h"
#include "Camera.h"

class Transform {
public:
    Transform();

    Matrix4f getTransformation();

    Matrix4f getProjectedTransformation();

    const Vector3f &getTranslation() const;

    void setTranslation(const Vector3f &translation);

    void setTranslation(float x, float y, float z);

    const Vector3f &getRotation() const;

    void setRotation(const Vector3f &rotation);

    void setRotation(float x, float y, float z);

    const Vector3f &getScale() const;

    void setScale(const Vector3f &scale);

    void setScale(float x, float y, float z);

    Camera *getCamera() const;

    void setCamera(Camera *camera);

    static void setProjection(float fov, float width, float height, float zNear, float zFar);

private:
    Camera* camera;

    Vector3f translation;
    Vector3f rotation;
    Vector3f scale;

    static float zNear;
    static float zFar;
    static float fov;
    static float width;
    static float height;
};


#endif //DORMENGINE_TRANSFORM_H
