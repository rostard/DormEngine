//
// Created by rostard on 20.12.17.
//

#include <glm/geometric.hpp>
#include <GLFW/glfw3.h>
#include "Camera.h"
#include "Vector3f.h"
#include "Input.h"

const Vector3f Camera::yAxis = Vector3f(0.0f, 1.0f, 0.0f);


const Vector3f &Camera::getPos() const {
    return pos;
}

void Camera::setPos(const Vector3f &pos) {
    Camera::pos = pos;
}

const Vector3f &Camera::getForward() const {
    return forward;
}

void Camera::setForward(const Vector3f &forward) {
    Camera::forward = forward;
}

const Vector3f &Camera::getUp() const {
    return up;
}

void Camera::setUp(const Vector3f &up) {
    Camera::up = up;
}

void Camera::move(Vector3f direction, float amt) {
    pos += direction * amt;
}

Camera::Camera() {
    pos = Vector3f(0.0f, 0.0f, 0.0f);
    up = Vector3f(0.0f, 1.0f, 0.0f);
    forward = Vector3f(0.0f, 0.0f, 1.0f);
}

void Camera::rotateY(float angle) {
    Vector3f haxis = yAxis.cross(forward).normalized();

    forward = forward.rotate(yAxis, angle);
    forward = forward.normalized();

    up = forward.cross(haxis);
    up = up.normalized();
}

void Camera::rotateX(float angle) {
    Vector3f haxis = yAxis.cross(forward).normalized();
    forward = forward.rotate(haxis, angle);
    forward = forward.normalized();

    up = forward.cross(haxis);
    up = up.normalized();
}

Vector3f Camera::getLeft() {
    Vector3f left = forward.cross(up).normalized();
    return left;
}

Vector3f Camera::getRight() {
    Vector3f right = up.cross(forward).normalized();
    return right;
}

void Camera::input(float d_time) {
    float movAmt = d_time * 10.0f;
    float rotAmt = d_time;

    if(Input::isKeyPress(GLFW_KEY_W))
        move(forward, movAmt);
    if(Input::isKeyPress(GLFW_KEY_S))
        move(forward, -movAmt);
    if(Input::isKeyPress(GLFW_KEY_D))
        move(getRight(), movAmt);
    if(Input::isKeyPress(GLFW_KEY_A))
        move(getLeft(), movAmt);


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
    pos = Vector3f(0.0f, 0.0f, 0.0f);
    up = Vector3f(0.0f, 1.0f, 0.0f);
    forward = Vector3f(0.0f, 0.0f, 1.0f);
    projection = projection.initPerspective(fov, aspect, zNear, zFar);
}

Matrix4f Camera::getViewProjection() const {
    Matrix4f cameraRotation;
    Matrix4f cameraTranslation;

    cameraRotation.initRotation(forward, up);
    cameraTranslation.initTranslation(-pos.getX(), -pos.getY(), -pos.getZ());

    return projection * cameraRotation * cameraTranslation;
}
