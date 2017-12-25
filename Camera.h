//
// Created by rostard on 20.12.17.
//

#ifndef DORMENGINE_CAMERA_H
#define DORMENGINE_CAMERA_H

#include "Matrix4f.h"
#include "Vector3f.h"

class Camera {
public:
    Camera();

    Camera(float fov, float aspect, float zNear, float zFar);

    const Vector3f &getPos() const;

    void setPos(const Vector3f &pos);

    const Vector3f &getForward() const;

    void setForward(const Vector3f &forward);

    const Vector3f &getUp() const;

    void setUp(const Vector3f &up);

    void move(Vector3f direction, float amt);

    void rotateY(float angle);

    void rotateX(float angle);

    Vector3f getLeft();

    Vector3f getRight();

    Matrix4f getViewProjection() const;

    void input(float d_time);
private:
    Matrix4f projection;

    Vector3f pos;
    Vector3f forward;
    Vector3f up;

    const static Vector3f yAxis;
};


#endif //DORMENGINE_CAMERA_H
