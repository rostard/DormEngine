//
// Created by rostard on 14.12.17.
//

#include "Vertex.h"

Vertex::Vertex(const glm::vec3 &position) : position(position), texCoord(glm::vec2(0, 0)) {}

const glm::vec3 &Vertex::getPosition() const {
    return position;
}

void Vertex::setPosition(const glm::vec3 &position) {
    Vertex::position = position;
}

Vertex::Vertex(const glm::vec3 &position, const glm::vec2 &texCoord) : position(position), texCoord(texCoord){}

const glm::vec2 &Vertex::getTexCoord() const {
    return texCoord;
}

void Vertex::setTexCoord(const glm::vec2 &texCoord) {
    Vertex::texCoord = texCoord;
}
