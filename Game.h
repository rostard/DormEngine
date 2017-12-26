//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_GAME_H
#define DORMENGINE_GAME_H


#include "GameObject.h"

class Game {
public:

    virtual void input(float d_time);

    virtual void update(float d_time);

    virtual void init();

    void render(RenderingEngine* renderingEngine);

    void addObject(GameObject* gameObject);


private:
    GameObject* getRoot();
    GameObject* root;
};


#endif //DORMENGINE_GAME_H
