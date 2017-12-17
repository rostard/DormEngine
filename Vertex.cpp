//
// Created by rostard on 14.12.17.
//

#include "Vertex.h"

Vertex::Vertex(const glm::vec3 &position) : position(position) {}

const glm::vec3 &Vertex::getPosition() const {
    return position;
}

void Vertex::setPosition(const glm::vec3 &position) {
    Vertex::position = position;
}
