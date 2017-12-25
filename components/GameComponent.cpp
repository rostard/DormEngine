//
// Created by rostard on 14.12.17.
//

#include "GameComponent.h"
#include "../GameObject.h"

void GameComponent::setParent(GameObject *parent) {
    GameComponent::parent = parent;
}

GameObject *GameComponent::getParent() const {
    return parent;
}

Transform &GameComponent::getTransform() {
    return *parent->getTransform();
}