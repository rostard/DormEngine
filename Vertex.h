//
// Created by rostard on 14.12.17.
//

#ifndef ENGINE_VERTEX_H
#define ENGINE_VERTEX_H

#include <glm/glm.hpp>
#include "math/Vector2f.h"
#include "math/Vector3f.h"

class Vertex {
public:
    Vertex(const Vector3f &position, const Vector2f &texCoord = Vector2f(0.0f, 0.0f), const Vector3f& normal = Vector3f(0.0f, 1.0f, 0.0f));

    const Vector3f &getPosition() const;
    void setPosition(const Vector3f &position);

    const Vector2f &getTexCoord() const;
    void setTexCoord(const Vector2f &texCoord);

    const Vector3f &getNormal() const;
    void setNormal(const Vector3f &normal);

private:
    Vector3f position;
    Vector2f texCoord;
    Vector3f normal;

};


#endif //ENGINE_VERTEX_H
