//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_GAMECOMPONENT_H
#define DORMENGINE_GAMECOMPONENT_H


#include "../Input.h"

class Transform;
class Shader;
class CoreEngine;
class RenderingEngine;
class GameObject;

class GameComponent {
public:
    virtual void processInput(const Input &input, float d_time) {}
    virtual void render(Shader& shader, RenderingEngine* renderingEngine){}
    virtual void update(float d_time){}
    virtual void addToEngine(CoreEngine* engine){}

    void setParent(GameObject *parent);

    GameObject *getParent() const;

    Transform& getTransform() const;
private:
    GameObject* parent;

};


#endif //DORMENGINE_GAMECOMPONENT_H
