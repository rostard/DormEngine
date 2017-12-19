//
// Created by rostard on 18.12.17.
//

#include "MeshRenderer.h"
#include "../Shader.h"
#include "../resource_management/ResourceManager.h"

MeshRenderer::MeshRenderer(const Mesh &mesh, const Material &material) : mesh(mesh), material(material) {}

void MeshRenderer::render(Transform &transform) {
    Shader* shader = ResourceManager::getShader("simple_shader");
    shader->setMat4("transform", transform.getProjectedTransformation());
    mesh.render();
}

void MeshRenderer::input(Transform &transform) {

}

void MeshRenderer::update(Transform &transform) {

}
