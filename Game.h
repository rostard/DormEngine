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


    GameObject* getRoot(){
        return root;
    }

protected:
    GameObject* root;
};


#endif //DORMENGINE_GAME_H
