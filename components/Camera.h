//
// Created by rostard on 20.12.17.
//

#ifndef DORMENGINE_CAMERA_H
#define DORMENGINE_CAMERA_H

#include "../math/Matrix4f.h"
#include "../math/Vector3f.h"
#include "GameComponent.h"
#include "../Input.h"

class Camera : public GameComponent {
public:
    Camera();

    Camera(float fov, float aspect, float zNear, float zFar);

    Camera(const Matrix4f& matrix);

    void move(Vector3f direction, float amt);

    void rotateY(float angle);

    void rotateX(float angle);

    Matrix4f getViewProjection() const;

    void addToEngine(CoreEngine *engine);

    void processInput(const Input &input, float d_time);

    void setProjection(const Matrix4f &projection);

private:
    Matrix4f projection;


    const static Vector3f yAxis;
};


#endif //DORMENGINE_CAMERA_H
