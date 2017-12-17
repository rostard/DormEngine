//
// Created by rostard on 14.12.17.
//

#include <glad/glad.h>
#include "Mesh.h"

Mesh::Mesh() {
    glGenBuffers(1, &vbo);
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &ebo);
}

void Mesh::addVertices(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices) {
    size = indices.size();

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
}

void Mesh::render() {
    glBindVertexArray (vao);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);

    glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
}
