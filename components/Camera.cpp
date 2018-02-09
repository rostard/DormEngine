//
// Created by rostard on 20.12.17.
//

#include <GLFW/glfw3.h>
#include "Camera.h"
#include "../math/Vector3f.h"
#include "../Input.h"
#include "../RenderingEngine.h"
#include "../Transform.h"
#include "../CoreEngine.h"

const Vector3f Camera::yAxis = Vector3f(0.0f, 1.0f, 0.0f);



void Camera::move(Vector3f direction, float amt) {
    getTransform().setPos(getTransform().getPos() + direction * amt);
}

Camera::Camera() {}

void Camera::rotateY(float angle) {
    getTransform().rotate(yAxis, angle);
}

void Camera::rotateX(float angle) {
    getTransform().rotate(getTransform().getRot().getRight(), angle);
}
//
void Camera::processInput(const Input &input, float d_time) {
//    float movAmt = d_time * 10.0f;
//    float rotAmt = d_time;
//
//    if(Input::getKey(GLFW_KEY_W))
//        move(getTransform().getRot().getForward(), movAmt);
//    if(Input::getKey(GLFW_KEY_S))
//        move(getTransform().getRot().getBack(), movAmt);
//    if(Input::getKey(GLFW_KEY_D))
//        move(getTransform().getRot().getRight(), movAmt);
//    if(Input::getKey(GLFW_KEY_A))
//        move(getTransform().getRot().getLeft(), movAmt);
//
//
//    if(Input::getKey(GLFW_KEY_UP))
//        rotateX(-rotAmt);
//    if(Input::getKey(GLFW_KEY_DOWN))
//        rotateX(rotAmt);
//    if(Input::getKey(GLFW_KEY_RIGHT))
//        rotateY(rotAmt);
//    if(Input::getKey(GLFW_KEY_LEFT))
//        rotateY(-rotAmt);
}

Camera::Camera(float fov, float aspect, float zNear, float zFar) {
    projection = projection.initPerspective(fov, aspect, zNear, zFar);
}

Matrix4f Camera::getViewProjection() const {
    Matrix4f cameraRotation = getTransform().getTransformedRot().conjugate().toRotationMatrix();
    Matrix4f cameraPosition ;

    cameraPosition.initTranslation(-getTransform().getTransformedPos().getX(), -getTransform().getTransformedPos().getY(), -getTransform().getTransformedPos().getZ());

    return projection * cameraRotation * cameraPosition;
}

void Camera::addToEngine(CoreEngine *engine) {
    engine->getRenderingEngine()->addCamera(this);
}

Camera::Camera(const Matrix4f &matrix) {
    projection = matrix;
}

void Camera::setProjection(const Matrix4f &projection) {
    Camera::projection = projection;
}
