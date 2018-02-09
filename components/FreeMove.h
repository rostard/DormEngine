//
// Created by rostard on 05.02.18.
//

#ifndef DORMENGINE_FREEMOVE_H
#define DORMENGINE_FREEMOVE_H


#include <GLFW/glfw3.h>
#include "GameComponent.h"

class Vector3f;

class FreeMove : public GameComponent{
public:
    FreeMove(float speed = 10, unsigned int forwardKey = GLFW_KEY_W, unsigned int backKey = GLFW_KEY_S, unsigned int leftKey = GLFW_KEY_A, unsigned int rightKey = GLFW_KEY_D);

    void processInput(const Input &input, float d_time) override;

private:
    void move(const Vector3f &direction, float amount);

    float speed;
    unsigned int forwardKey;
    unsigned int backKey;
    unsigned int leftKey;
    unsigned int rightKey;
};


#endif //DORMENGINE_FREEMOVE_H
