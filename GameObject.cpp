//
// Created by rostard on 14.12.17.
//

#include "GameObject.h"
#include "Input.h"

void GameObject::addChild(GameObject *child) {
    children.push_back(child);
    child->setEngine(engine);
    child->getTransform()->setParent(&transform);
}

GameObject * GameObject::addComponent(GameComponent *component) {
    components.push_back(component);
    component->setParent(this);
    return this;
}

void GameObject::processInputAll(const Input &input, float d_time) {
    for (auto component : components) {
        component->processInput(input, d_time);
    }

    for (auto child : children) {
        child->processInputAll(input, d_time);
    }
}

void GameObject::processInput(const Input &input, float d_time) {
    for (auto component : components) {
        component->processInput(input, d_time);
    }
}

void GameObject::updateAll(float d_time) {
    for (auto component : components) {
        component->update(d_time);
    }

    for (auto child : children) {
        child->updateAll(d_time);
    }
}

void GameObject::update(float d_time) {
    for (auto component : components) {
        component->update(d_time);
    }
}

void GameObject::renderAll(Shader &shader, RenderingEngine *renderingEngine) {
    for (auto component : components) {
        component->render(shader, renderingEngine);
    }

    for (auto child : children) {
        child->renderAll(shader, renderingEngine);
    }
    transform.update();
}

void GameObject::render(Shader &shader, RenderingEngine *renderingEngine) {
    for (auto component : components) {
        component->render(shader, renderingEngine);
    }
    transform.update();
}

Transform *GameObject::getTransform() {
    return &transform;
}

void GameObject::setEngine(CoreEngine *engine) {
    if(!this->engine || engine != this->engine){
        this->engine = engine;

        for (auto component : components){
            component->addToEngine(engine);
        }

        for (auto child : children){
            child->setEngine(engine);
        }
    }

}
