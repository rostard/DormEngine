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
    Transform(){
        translation = glm::vec3(0.0, 0.0, 0.0);
        rotation = glm::vec3(0.0, 0.0, 0.0);
    }

    const glm::vec3 &getTranslation() const {
        return translation;
    }

    void setTranslation(const glm::vec3 &translation) {
        Transform::translation = translation;
    }

    void setTranslation(float x, float y, float z) {
        Transform::translation = glm::vec3(x, y, z);
    }

    Matrix4f getTransformation(){
        Matrix4f translationMatrix;
        Matrix4f rotationMatrix;
        translationMatrix = translationMatrix.initTranslation(getTranslation().x, getTranslation().y, getTranslation().z);
        rotationMatrix = rotationMatrix.initRotation(getRotation().x, getRotation().y, getRotation().z);

        return translationMatrix * rotationMatrix;
    }

    const glm::vec3 &getRotation() const {
        return rotation;
    }

    void setRotation(const glm::vec3 &rotation) {
        Transform::rotation = rotation;
    }

    void setRotation(float x, float y, float z) {
        Transform::rotation = glm::vec3(x, y, z);
    }

private:
    glm::vec3 translation;
    glm::vec3 rotation;
};


#endif //DORMENGINE_TRANSFORM_H
