//
// Created by rostard on 14.12.17.
//

#ifndef ENGINE_VERTEX_H
#define ENGINE_VERTEX_H

#include <glm/glm.hpp>

class Vertex {
public:
    explicit Vertex(const glm::vec3 &position);

    const glm::vec3 &getPosition() const;

    void setPosition(const glm::vec3 &position);

private:
    glm::vec3 position;
};


#endif //ENGINE_VERTEX_H
