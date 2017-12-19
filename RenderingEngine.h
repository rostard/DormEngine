//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_RENDERINGENGINE_H
#define DORMENGINE_RENDERINGENGINE_H


#include "GameObject.h"
#include "Shader.h"

class RenderingEngine {
public:
    RenderingEngine();

    void render(GameObject object, Shader shader){
        clearScreen();

        shader.bind();
        object.render(shader);
    }

    void clearScreen();
};


#endif //DORMENGINE_RENDERINGENGINE_H
