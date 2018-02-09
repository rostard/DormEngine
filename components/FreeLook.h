//
// Created by rostard on 09.02.18.
//

#ifndef DORMENGINE_FREELOOK_H
#define DORMENGINE_FREELOOK_H


#include <GLFW/glfw3.h>
#include "GameComponent.h"
#include "../math/Vector2f.h"

class FreeLook : public GameComponent{
public:
    FreeLook(const Vector2f& windowCenter, float sensitivity = 0.5, int unlockMouseKey = GLFW_KEY_ESCAPE);


    virtual void processInput(const Input& input, float delta);
private:
    float sensitivity;
    int unlockMouseKey;
    bool mouseLocked;
    Vector2f windowCenter;
};


#endif //DORMENGINE_FREELOOK_H
