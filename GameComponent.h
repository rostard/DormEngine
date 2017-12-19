//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_GAMECOMPONENT_H
#define DORMENGINE_GAMECOMPONENT_H


#include "Transform.h"
#include "Shader.h"

class GameComponent {
public:
    virtual void input(Transform &transform) = 0;
    virtual void render(Transform &transform, Shader shader) = 0;
    virtual void update(Transform &transform) = 0;
};


#endif //DORMENGINE_GAMECOMPONENT_H
