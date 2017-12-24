//
// Created by rostard on 14.12.17.
//

#include "Vertex.h"
#include "Vector2f.h"


Vertex::Vertex(const Vector3f &position, const Vector2f &texCoord, const Vector3f &normal) : position(position), texCoord(texCoord), normal(normal) {}

const Vector3f &Vertex::getPosition() const {
    return position;
}

void Vertex::setPosition(const Vector3f &position) {
    Vertex::position = position;
}


const Vector2f &Vertex::getTexCoord() const {
    return texCoord;
}

void Vertex::setTexCoord(const Vector2f &texCoord) {
    Vertex::texCoord = texCoord;
}

const Vector3f &Vertex::getNormal() const {
    return normal;
}

void Vertex::setNormal(const Vector3f &normal) {
    Vertex::normal = normal;
}

