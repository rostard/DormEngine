//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_GAMECOMPONENT_H
#define DORMENGINE_GAMECOMPONENT_H


class GameComponent {
public:
    virtual void init() = 0;
    virtual void input() = 0;
    virtual void render() = 0;
    virtual void update() = 0;
};


#endif //DORMENGINE_GAMECOMPONENT_H
