//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_GAMECOMPONENT_H
#define DORMENGINE_GAMECOMPONENT_H


class Transform;
class Shader;
class RenderingEngine;
class GameObject;

class GameComponent {
public:
    virtual void input(float d_time) {}
    virtual void render(Shader& shader, RenderingEngine* renderingEngine){}
    virtual void update(float d_time){}
    virtual void addToRenderingEngine(RenderingEngine& renderingEngine){}

    void setParent(GameObject *parent);

    GameObject *getParent() const;

    Transform& getTransform() const;
private:
    GameObject* parent;

};


#endif //DORMENGINE_GAMECOMPONENT_H
