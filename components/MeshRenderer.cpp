//
// Created by rostard on 18.12.17.
//

#include "MeshRenderer.h"
#include "../Shader.h"
#include "../GameObject.h"

MeshRenderer::MeshRenderer(const Mesh &mesh, const Material &material) : mesh(mesh), material(material) {}

void MeshRenderer::render(Shader& shader) {
    shader.bind();
    shader.updateUniforms(*getParent()->getTransform(), material);
    mesh.render();
}

void MeshRenderer::input(float d_time) {

}

void MeshRenderer::update(float d_time) {

}
