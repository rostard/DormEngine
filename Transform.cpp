//
// Created by rostard on 18.12.17.
//

#include "Transform.h"

Transform::Transform() :  pos(0.0f, 0.0f, 0.0f), rot(0.0f, 0.0f, 0.0f, 1.0f), scale(1.0f, 1.0f, 1.0f), parent(nullptr){parentMatrix.initIdentity();}

Matrix4f Transform::getTransformation(){
    Matrix4f translationMatrix;
    Matrix4f rotationMatrix;
    Matrix4f scaleMatrix;

    translationMatrix = translationMatrix.initTranslation(getPos().getX(), getPos().getY(), getPos().getZ());
    rotationMatrix = rot.toRotationMatrix();//rotationMatrix.initRotation(getRotation().getX(), getRotation().getY(), getRotation().getZ());
    scaleMatrix = scaleMatrix.initScale(getScale().getX(), getScale().getY(), getScale().getZ());

    return getParentMatrix() * translationMatrix * rotationMatrix * scaleMatrix;
}

Matrix4f Transform::getProjectedTransformation(const Camera& camera){
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

void Transform::setParent(Transform *transform) {
    parent = transform;
    parentMatrix = parent->getTransformation();
}

bool Transform::hasChanged(){
    bool ret  = pos != oldPos || rot != oldRot || scale != oldScale || (parent && parent->hasChanged());


    return ret;
}

Matrix4f Transform::getParentMatrix() {
    if(parent && hasChanged()){
        parentMatrix = parent->getTransformation();
    }

    return parentMatrix;
}

Vector3f Transform::getTransformedPos(){
    return getParentMatrix().transform(pos);
}

Quaternion Transform::getTransformedRot() {
    Quaternion parentRotation(0, 0, 0, 1);
    if(parent){
        parentRotation = parent->getTransformedRot();
    }

    return parentRotation * rot;
}

void Transform::update() {
    oldPos = pos;
    oldRot = rot;
    oldScale = scale;
}

void Transform::rotate(const Vector3f &axis, float angle) {
    rot = (Quaternion(axis, angle) * rot).normalized();
}

