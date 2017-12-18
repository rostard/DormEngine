//
// Created by rostard on 18.12.17.
//

#ifndef DORMENGINE_TRANSFORM_H
#define DORMENGINE_TRANSFORM_H


#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include "Matrix4f.h"

class Transform {
public:
    Transform();

    Matrix4f getTransformation();

    Matrix4f getProjectedTransformation();

    const glm::vec3 &getTranslation() const;

    void setTranslation(const glm::vec3 &translation);

    void setTranslation(float x, float y, float z);

    const glm::vec3 &getRotation() const;

    void setRotation(const glm::vec3 &rotation);

    void setRotation(float x, float y, float z);

    const glm::vec3 &getScale() const;

    void setScale(const glm::vec3 &scale);

    void setScale(float x, float y, float z);

    static void setProjection(float fov, float width, float height, float zNear, float zFar);

private:
    glm::vec3 translation;
    glm::vec3 rotation;
    glm::vec3 scale;

    static float zNear;
    static float zFar;
    static float fov;
    static float width;
    static float height;
};


#endif //DORMENGINE_TRANSFORM_H
