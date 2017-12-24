//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_GAMEOBJECT_H
#define DORMENGINE_GAMEOBJECT_H

#include <vector>
#include "GameComponent.h"

class GameComponent;
class Shader;

class GameObject {
public:

    void addChild(GameObject* child);

    void addComponent(GameComponent *component);

    void input(float d_time);

    void update(float d_time);

    void render(Shader &shader);

    Transform* getTransform();
private:
    std::vector<GameObject*> children;
    std::vector<GameComponent*> components;

    Transform transform;
};


#endif //DORMENGINE_GAMEOBJECT_H
