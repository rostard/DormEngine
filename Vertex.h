//
// Created by rostard on 14.12.17.
//

#ifndef ENGINE_VERTEX_H
#define ENGINE_VERTEX_H

#include <glm/glm.hpp>
#include "Vector2f.h"
#include "Vector3f.h"

class Vertex {
public:
    Vertex(const Vector3f &position);

    Vertex(const Vector3f &position, const Vector2f &texCoord);

    const Vector3f &getPosition() const;
    void setPosition(const Vector3f &position);

    const Vector2f &getTexCoord() const;
    void setTexCoord(const Vector2f &texCoord);

private:
    Vector3f position;
    Vector2f texCoord;

};


#endif //ENGINE_VERTEX_H
