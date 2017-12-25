//
// Created by rostard on 20.12.17.
//

#include <GLFW/glfw3.h>
#include "Camera.h"
#include "../Vector3f.h"
#include "../Input.h"
#include "../RenderingEngine.h"
#include "../Transform.h"

const Vector3f Camera::yAxis = Vector3f(0.0f, 1.0f, 0.0f);



void Camera::move(Vector3f direction, float amt) {
    getTransform().setPos(getTransform().getPos() + direction * amt);
}

Camera::Camera() {}

void Camera::rotateY(float angle) {
    getTransform().setRot(Quaternion(yAxis, angle).normalized() * getTransform().getRot());
}

void Camera::rotateX(float angle) {
    getTransform().setRot(Quaternion(getTransform().getRot().getRight(), angle) * getTransform().getRot());
}

void Camera::input(float d_time) {
    float movAmt = d_time * 10.0f;
    float rotAmt = d_time;

    if(Input::isKeyPress(GLFW_KEY_W))
        move(getTransform().getRot().getForward(), movAmt);
    if(Input::isKeyPress(GLFW_KEY_S))
        move(getTransform().getRot().getBack(), movAmt);
    if(Input::isKeyPress(GLFW_KEY_D))
        move(getTransform().getRot().getRight(), movAmt);
    if(Input::isKeyPress(GLFW_KEY_A))
        move(getTransform().getRot().getLeft(), movAmt);


    if(Input::isKeyPress(GLFW_KEY_UP))
        rotateX(-rotAmt);
    if(Input::isKeyPress(GLFW_KEY_DOWN))
        rotateX(rotAmt);
    if(Input::isKeyPress(GLFW_KEY_RIGHT))
        rotateY(rotAmt);
    if(Input::isKeyPress(GLFW_KEY_LEFT))
        rotateY(-rotAmt);
}

Camera::Camera(float fov, float aspect, float zNear, float zFar) {
    projection = projection.initPerspective(fov, aspect, zNear, zFar);
}

Matrix4f Camera::getViewProjection() const {
    Matrix4f cameraRotation = getTransform().getRot().toRotationMatrix();
    Matrix4f cameraTranslation;

    cameraTranslation.initTranslation(-getTransform().getPos().getX(), -getTransform().getPos().getY(), -getTransform().getPos().getZ());

    return projection * cameraRotation * cameraTranslation;
}

void Camera::addToRenderingEngine(RenderingEngine &renderingEngine) {
    renderingEngine.addCamera(this);
}
