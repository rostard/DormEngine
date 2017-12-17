//
// Created by rostard on 14.12.17.
//

#ifndef ENGINE_VERTEX_H
#define ENGINE_VERTEX_H

#include <glm/glm.hpp>

class Vertex {
public:
    Vertex(const glm::vec3 &position);

    Vertex(const glm::vec3 &position, const glm::vec2 &texCoord);

    const glm::vec3 &getPosition() const;
    void setPosition(const glm::vec3 &position);

    const glm::vec2 &getTexCoord() const;
    void setTexCoord(const glm::vec2 &texCoord);

private:
    glm::vec3 position;
    glm::vec2 texCoord;

};


#endif //ENGINE_VERTEX_H
