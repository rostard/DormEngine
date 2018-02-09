//
// Created by rostard on 05.02.18.
//

#include "FreeMove.h"
#include "../Transform.h"


FreeMove::FreeMove(float speed, unsigned int forwardKey, unsigned int backKey, unsigned int leftKey,
                   unsigned int rightKey) : speed(speed), forwardKey(forwardKey), backKey(backKey), leftKey(leftKey),
                                            rightKey(rightKey) {

}

void FreeMove::processInput(const Input &input, float d_time) {
    float amount = d_time * speed;
    if(input.getKey(forwardKey)){
        move(getTransform().getRot().getForward(), amount);
    }
    if(input.getKey(backKey)){
        move(getTransform().getRot().getBack(), amount);
    }
    if(input.getKey(leftKey)){
        move(getTransform().getRot().getLeft(), amount);
    }
    if(input.getKey(rightKey)){
        move(getTransform().getRot().getRight(), amount);
    }
}

void FreeMove::move(const Vector3f &direction, float amount) {
    getTransform().setPos(getTransform().getPos() + direction * amount);
}
