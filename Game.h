//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_GAME_H
#define DORMENGINE_GAME_H


class Game {
public:
    virtual void input(float d_time);

    virtual void update(float d_time);

    virtual void init();

    virtual void render();
};


#endif //DORMENGINE_GAME_H
