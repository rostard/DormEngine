//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_GAMEOBJECT_H
#define DORMENGINE_GAMEOBJECT_H

#include <vector>

#include "Transform.h"
#include "Input.h"

class GameComponent;
class Shader;
class RenderingEngine;
class CoreEngine;

class GameObject {
public:

    void addChild(GameObject* child);

    void addComponent(GameComponent *component);

    void processInputAll(const Input &input, float d_time);
    void processInput(const Input &input, float d_time);

    void updateAll(float d_time);
    void update(float d_time);

    void renderAll(Shader &shader, RenderingEngine *renderingEngine);
    void render(Shader &shader, RenderingEngine *renderingEngine);

    void setEngine(CoreEngine* engine);
    Transform* getTransform();
private:
    std::vector<GameObject*> children;
    std::vector<GameComponent*> components;

    CoreEngine* engine;
    Transform transform;
};


#endif //DORMENGINE_GAMEOBJECT_H
