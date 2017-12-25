//
// Created by rostard on 14.12.17.
//

#include "GameObject.h"
#include "components/GameComponent.h"

void GameObject::addChild(GameObject *child) {
    children.push_back(child);
}

void GameObject::addComponent(GameComponent *component) {
    components.push_back(component);
    component->setParent(this);
}

void GameObject::input(float d_time) {
    for(auto component : components){
        component->input(d_time);
    }

    for(auto child : children){
        child->input(d_time);
    }
}

void GameObject::update(float d_time) {
    for(auto component : components){
        component->update(d_time);
    }

    for(auto child : children){
        child->update(d_time);
    }
}

void GameObject::render(Shader &shader) {
    for(auto component : components){
        component->render(shader);
    }

    for(auto child : children){
        child->render(shader);
    }
}

Transform *GameObject::getTransform() {
    return &transform;
}

void GameObject::addToRenderingEngine(RenderingEngine& engine) {
    for(auto component : components){
        component->addToRenderingEngine(engine);
    }
    for(auto child : children){
        child->addToRenderingEngine(engine);
    }
}
