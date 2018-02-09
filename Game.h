//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_GAME_H
#define DORMENGINE_GAME_H


#include "GameObject.h"
#include "Window.h"

class CoreEngine;

class Game {
public:

    virtual void processInput(const Input &input, float d_time);

    virtual void update(float d_time);

    virtual void init(const Window &window);

    void render(RenderingEngine* renderingEngine);

    void addObject(GameObject* gameObject);

    void setEngine(CoreEngine* engine);
private:
    GameObject* getRoot();
    GameObject* root;
};


#endif //DORMENGINE_GAME_H
