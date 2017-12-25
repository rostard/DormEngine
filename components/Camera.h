//
// Created by rostard on 20.12.17.
//

#ifndef DORMENGINE_CAMERA_H
#define DORMENGINE_CAMERA_H

#include "../Matrix4f.h"
#include "../Vector3f.h"
#include "GameComponent.h"

class Camera : public GameComponent {
public:
    Camera();

    Camera(float fov, float aspect, float zNear, float zFar);

    void move(Vector3f direction, float amt);

    void rotateY(float angle);

    void rotateX(float angle);

    Matrix4f getViewProjection() const;

    void addToRenderingEngine(RenderingEngine& renderingEngine);

    void input(float d_time);
private:
    Matrix4f projection;


    const static Vector3f yAxis;
};


#endif //DORMENGINE_CAMERA_H
