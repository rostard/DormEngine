//
// Created by rostard on 14.12.17.
//

#ifndef ENGINE_MESH_H
#define ENGINE_MESH_H


#include <vector>
#include "Vertex.h"

class Mesh {
public:
    Mesh();
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

    void addVertices(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

    void render();

private:
    unsigned int vbo;
    unsigned int vao;
    unsigned int ebo;
    size_t size;

};


#endif //ENGINE_MESH_H
