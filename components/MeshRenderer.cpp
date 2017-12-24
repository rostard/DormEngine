//
// Created by rostard on 18.12.17.
//

#include "MeshRenderer.h"
#include "../Shader.h"
#include "../resource_management/ResourceManager.h"

MeshRenderer::MeshRenderer(const Mesh &mesh, const Material &material) : mesh(mesh), material(material) {}

void MeshRenderer::render(const Transform &transform, Shader& shader) {
    shader.bind();
    shader.updateUniforms(transform, material);
    mesh.render();
}

void MeshRenderer::input(const Transform &transform, float d_time) {

}

void MeshRenderer::update(const Transform &transform, float d_time) {

}
