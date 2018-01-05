//
// Created by rostard on 14.12.17.
//

#include "Vertex.h"
#include "math/Vector2f.h"


Vertex::Vertex(const Vector3f &position, const Vector2f &texCoord, const Vector3f &normal, const Vector3f &tangent)
        : position(position), texCoord(texCoord), normal(normal), tangent(tangent) {}

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

const Vector3f &Vertex::getTangent() const {
    return tangent;
}

void Vertex::setTangent(const Vector3f &tangent) {
    Vertex::tangent = tangent;
}

