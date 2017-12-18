//
// Created by rostard on 18.12.17.
//

#include "Transform.h"

float Transform::fov = 0.0f;
float Transform::width = 0.0f;
float Transform::height = 0.0f;
float Transform::zNear = 0.0f;
float Transform::zFar = 0.0f;

Transform::Transform() {
    translation = glm::vec3(0.0, 0.0, 0.0);
    rotation = glm::vec3(0.0, 0.0, 0.0);
    scale = glm::vec3(1.0, 1.0, 1.0);
}

Matrix4f Transform::getTransformation() {
    Matrix4f translationMatrix;
    Matrix4f rotationMatrix;
    Matrix4f scaleMatrix;

    translationMatrix = translationMatrix.initTranslation(getTranslation().x, getTranslation().y, getTranslation().z);
    rotationMatrix = rotationMatrix.initRotation(getRotation().x, getRotation().y, getRotation().z);
    scaleMatrix = scaleMatrix.initScale(getScale().x, getScale().y, getScale().z);
    return translationMatrix * rotationMatrix * scaleMatrix;
}

Matrix4f Transform::getProjectedTransformation() {
    Matrix4f transformation = getTransformation();
    Matrix4f projection;
    projection = projection.initProjection(fov, width, height, zNear, zFar);
    return projection * transformation;
}

const glm::vec3 &Transform::getTranslation() const {
    return translation;
}

void Transform::setTranslation(const glm::vec3 &translation) {
    Transform::translation = translation;
}

void Transform::setTranslation(float x, float y, float z) {
    Transform::translation = glm::vec3(x, y, z);
}

const glm::vec3 &Transform::getRotation() const {
    return rotation;
}

void Transform::setRotation(const glm::vec3 &rotation) {
    Transform::rotation = rotation;
}

void Transform::setRotation(float x, float y, float z) {
    Transform::rotation = glm::vec3(x, y, z);
}

const glm::vec3 &Transform::getScale() const {
    return scale;
}

void Transform::setScale(const glm::vec3 &scale) {
    Transform::scale = scale;
}

void Transform::setScale(float x, float y, float z) {
    Transform::scale = glm::vec3(x, y, z);
}

void Transform::setProjection(float fov, float width, float height, float zNear, float zFar) {
    Transform::fov = fov;
    Transform::width = width;
    Transform::height = height;
    Transform::zNear = zNear;
    Transform::zFar = zFar;
}
