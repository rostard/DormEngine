//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_GAMECOMPONENT_H
#define DORMENGINE_GAMECOMPONENT_H


#include "Shader.h"

class Shader;

class GameComponent {
public:
    virtual void input(const Transform &transform, float d_time) = 0;
    virtual void render(const Transform &transform, Shader& shader) = 0;
    virtual void update(const Transform &transform, float d_time) = 0;
};


#endif //DORMENGINE_GAMECOMPONENT_H
