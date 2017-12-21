//
// Created by rostard on 14.12.17.
//

#include "Vertex.h"
#include "Vector2f.h"

Vertex::Vertex(const Vector3f &position) : position(position), texCoord(Vector2f(0, 0)) {}

const Vector3f &Vertex::getPosition() const {
    return position;
}

void Vertex::setPosition(const Vector3f &position) {
    Vertex::position = position;
}

Vertex::Vertex(const Vector3f &position, const Vector2f &texCoord) : position(position), texCoord(texCoord){}

const Vector2f &Vertex::getTexCoord() const {
    return texCoord;
}

void Vertex::setTexCoord(const Vector2f &texCoord) {
    Vertex::texCoord = texCoord;
}
