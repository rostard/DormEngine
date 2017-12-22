//
// Created by rostard on 14.12.17.
//

#include "GameObject.h"

void GameObject::addChild(GameObject *child) {
    children.push_back(child);
}

void GameObject::addComponent(GameComponent *component) {
    components.push_back(component);
}

void GameObject::input() {
    for(auto component : components){
        component->input(transform);
    }

    for(auto child : children){
        child->input();
    }
}

void GameObject::update() {
    for(auto component : components){
        component->update(transform);
    }

    for(auto child : children){
        child->update();
    }
}

void GameObject::render(Shader shader) {
    for(auto component : components){
        component->render(transform, shader);
    }

    for(auto child : children){
        child->render(shader);
    }
}

Transform *GameObject::getTransform() {
    return &transform;
}
