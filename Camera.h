//
// Created by rostard on 20.12.17.
//

#ifndef DORMENGINE_CAMERA_H
#define DORMENGINE_CAMERA_H


#include <glm/vec3.hpp>
#include "Vector3f.h"
#include "Input.h"

class Camera {
public:
    Camera(const Vector3f &pos, const Vector3f &forward, const Vector3f &up);

    Camera();

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

    void input(float d_time);
private:
    Vector3f pos;
    Vector3f forward;
    Vector3f up;

    const static Vector3f yAxis;
};


#endif //DORMENGINE_CAMERA_H
