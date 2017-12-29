//
// Created by rostard on 14.12.17.
//

#include "GameObject.h"

void GameObject::addChild(GameObject *child) {
    children.push_back(child);
    child->getTransform()->setParent(&transform);
}

void GameObject::addComponent(GameComponent *component) {
    components.push_back(component);
    component->setParent(this);
}

void GameObject::input(float d_time) {
    for (auto component : components) {
        component->input(d_time);
    }

    for (auto child : children) {
        child->input(d_time);
    }
}

void GameObject::update(float d_time) {
    for (auto component : components) {
        component->update(d_time);
    }

    for (auto child : children) {
        child->update(d_time);
    }
}

void GameObject::render(Shader &shader, RenderingEngine *renderingEngine) {
    for (auto component : components) {
        component->render(shader, renderingEngine);
    }

    for (auto child : children) {
        child->render(shader, renderingEngine);
    }
    transform.update();
}

Transform *GameObject::getTransform() {
    return &transform;
}

void GameObject::addToRenderingEngine(RenderingEngine &engine) {
    for (auto component : components) {
        component->addToRenderingEngine(engine);
    }
    for (auto child : children) {
        child->addToRenderingEngine(engine);
    }
}
