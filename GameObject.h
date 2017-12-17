//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_GAMEOBJECT_H
#define DORMENGINE_GAMEOBJECT_H

#include <vector>
#include "GameComponent.h"

class GameObject {
public:

    void addChild(GameObject& child){
        children.push_back(child);
    }

    void addComponent(GameComponent *component){
        components.push_back(component);
    }

    void input(){
        for(auto component : components){
            component->input();
        }

        for(auto child : children){
            child.input();
        }
    }

    void update(){
        for(auto component : components){
            component->update();
        }

        for(auto child : children){
            child.update();
        }
    }

    void render(){
        for(auto component : components){
            component->render();
        }

        for(auto child : children){
            child.render();
        }
    }

private:
    std::vector<GameObject> children;
    std::vector<GameComponent*> components;
};


#endif //DORMENGINE_GAMEOBJECT_H
