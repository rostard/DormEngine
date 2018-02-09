//
// Created by rostard on 09.02.18.
//

#include "FreeLook.h"
#include "../Transform.h"
#include "../utility/Log.h"

FreeLook::FreeLook(const Vector2f &windowCenter, float sensitivity, int unlockMouseKey) : windowCenter(windowCenter), sensitivity(sensitivity), unlockMouseKey(unlockMouseKey), mouseLocked(
        false) {

}

void FreeLook::processInput(const Input &input, float delta) {
    if(input.getKey(unlockMouseKey)){
        input.setCursor(true);
        mouseLocked = false;
    }
    if(mouseLocked){
        Vector2f deltaPos = input.getMousePosition() - windowCenter;
        
        bool rotX = deltaPos.getX() != 0;
        bool rotY = deltaPos.getY() != 0;

        if(rotX){
            getTransform().rotate(Vector3f(0, 1, 0), deltaPos.getX() * sensitivity * M_PI / 180);
        }
        if(rotY){
            getTransform().rotate(getTransform().getRot().getRight(), deltaPos.getY() * sensitivity * M_PI / 180);
        }
        if(rotX || rotY){
            input.setMousePos(windowCenter);
        }
    }
    if(input.getMouseDown(GLFW_MOUSE_BUTTON_LEFT)){
        input.setCursor(false);
        input.setMousePos(windowCenter);
        mouseLocked = true;
    }

}



