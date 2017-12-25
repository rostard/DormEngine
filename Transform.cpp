//
// Created by rostard on 18.12.17.
//

#include "Transform.h"

Transform::Transform() :  pos(0.0f, 0.0f, 0.0f), rot(0.0f, 0.0f, 0.0f, 1.0f), scale(1.0f, 1.0f, 1.0f){}

Matrix4f Transform::getTransformation() const{
    Matrix4f translationMatrix;
    Matrix4f rotationMatrix;
    Matrix4f scaleMatrix;

    translationMatrix = translationMatrix.initTranslation(getPos().getX(), getPos().getY(), getPos().getZ());
    rotationMatrix = rot.toRotationMatrix();//rotationMatrix.initRotation(getRotation().getX(), getRotation().getY(), getRotation().getZ());
    scaleMatrix = scaleMatrix.initScale(getScale().getX(), getScale().getY(), getScale().getZ());
    return translationMatrix * rotationMatrix * scaleMatrix;
}

Matrix4f Transform::getProjectedTransformation(const Camera& camera) const{
    return camera.getViewProjection() * getTransformation();
}

const Vector3f &Transform::getPos() const {
    return pos;
}

void Transform::setPos(const Vector3f &translation) {
    Transform::pos = translation;
}

void Transform::setPos(float x, float y, float z) {
    Transform::pos = Vector3f(x, y, z);
}

const Quaternion &Transform::getRot() const {
    return rot;
}

void Transform::setRot(const Quaternion &rotation) {
    Transform::rot = rotation;
}

void Transform::setRot(float x, float y, float z, float w) {
    Transform::rot = Quaternion(x, y, z, w);
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

