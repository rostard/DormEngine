//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_GAMECOMPONENT_H
#define DORMENGINE_GAMECOMPONENT_H


#include "Shader.h"

class Shader;

class GameComponent {
public:
    virtual void input(Transform &transform, float d_time) = 0;
    virtual void render(Transform &transform, Shader shader) = 0;
    virtual void update(Transform &transform, float d_time) = 0;
};


#endif //DORMENGINE_GAMECOMPONENT_H
