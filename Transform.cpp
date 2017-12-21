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
    translation = Vector3f(0.0, 0.0, 0.0);
    rotation = Vector3f(0.0, 0.0, 0.0);
    scale = Vector3f(1.0, 1.0, 1.0);

    camera = new Camera();
}

Matrix4f Transform::getTransformation() {
    Matrix4f translationMatrix;
    Matrix4f rotationMatrix;
    Matrix4f scaleMatrix;

    translationMatrix = translationMatrix.initTranslation(getTranslation().getX(), getTranslation().getY(), getTranslation().getZ());
    rotationMatrix = rotationMatrix.initRotation(getRotation().getX(), getRotation().getY(), getRotation().getZ());
    scaleMatrix = scaleMatrix.initScale(getScale().getX(), getScale().getY(), getScale().getZ());
    return translationMatrix * rotationMatrix * scaleMatrix;
}

Matrix4f Transform::getProjectedTransformation() {
    Matrix4f transformationMatrix = getTransformation();
    Matrix4f projectionMatrix;
    Matrix4f cameraRotation;
    Matrix4f cameraTranslation;

    projectionMatrix = projectionMatrix.initProjection(fov, width, height, zNear, zFar);
    cameraRotation.initCamera(camera->getForward(), camera->getUp());
    cameraTranslation.initTranslation(-camera->getPos().getX(), -camera->getPos().getY(), -camera->getPos().getZ());

    return projectionMatrix * cameraRotation * cameraTranslation * transformationMatrix;
}

const Vector3f &Transform::getTranslation() const {
    return translation;
}

void Transform::setTranslation(const Vector3f &translation) {
    Transform::translation = translation;
}

void Transform::setTranslation(float x, float y, float z) {
    Transform::translation = Vector3f(x, y, z);
}

const Vector3f &Transform::getRotation() const {
    return rotation;
}

void Transform::setRotation(const Vector3f &rotation) {
    Transform::rotation = rotation;
}

void Transform::setRotation(float x, float y, float z) {
    Transform::rotation = Vector3f(x, y, z);
}

const Vector3f &Transform::getScale() const {
    return scale;
}

void Transform::setScale(const Vector3f &scale) {
    Transform::scale = scale;
}

void Transform::setScale(float x, float y, float z) {
    Transform::scale = Vector3f(x, y, z);
}

Camera *Transform::getCamera() const {
    return camera;
}

void Transform::setCamera(Camera *camera) {

    Transform::camera = camera;
}

void Transform::setProjection(float fov, float width, float height, float zNear, float zFar) {
    Transform::fov = fov;
    Transform::width = width;
    Transform::height = height;
    Transform::zNear = zNear;
    Transform::zFar = zFar;
}

