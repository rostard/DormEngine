//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_GAMEOBJECT_H
#define DORMENGINE_GAMEOBJECT_H

#include <vector>
#include "GameComponent.h"
#include "Transform.h"
#include "Shader.h"

class GameObject {
public:

    void addChild(GameObject* child){
        children.push_back(child);
    }

    void addComponent(GameComponent *component){
        components.push_back(component);
    }

    void input(){
        for(auto component : components){
            component->input(transform);
        }

        for(auto child : children){
            child->input();
        }
    }

    void update(){
        for(auto component : components){
            component->update(transform);
        }

        for(auto child : children){
            child->update();
        }
    }

    void render(Shader shader){
        for(auto component : components){
            component->render(transform, shader);
        }

        for(auto child : children){
            child->render(shader);
        }
    }

    Transform* getTransform(){
        return &transform;
    }
private:
    std::vector<GameObject*> children;
    std::vector<GameComponent*> components;

    Transform transform;
};


#endif //DORMENGINE_GAMEOBJECT_H
