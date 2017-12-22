//
// Created by rostard on 18.12.17.
//

#include "Transform.h"

Transform::Transform() {
    translation = Vector3f(0.0, 0.0, 0.0);
    rotation = Vector3f(0.0, 0.0, 0.0);
    scale = Vector3f(1.0, 1.0, 1.0);
}

Matrix4f Transform::getTransformation() const{
    Matrix4f translationMatrix;
    Matrix4f rotationMatrix;
    Matrix4f scaleMatrix;

    translationMatrix = translationMatrix.initTranslation(getTranslation().getX(), getTranslation().getY(), getTranslation().getZ());
    rotationMatrix = rotationMatrix.initRotation(getRotation().getX(), getRotation().getY(), getRotation().getZ());
    scaleMatrix = scaleMatrix.initScale(getScale().getX(), getScale().getY(), getScale().getZ());
    return translationMatrix * rotationMatrix * scaleMatrix;
}

Matrix4f Transform::getProjectedTransformation(const Camera& camera) const{
    return camera.getViewProjection() * getTransformation();
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

