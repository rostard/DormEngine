//
// Created by rostard on 18.12.17.
//

#include "MeshRenderer.h"
#include "../Shader.h"
#include "../GameObject.h"

MeshRenderer::MeshRenderer(const Mesh &mesh, const Material &material) : mesh(mesh), material(material) {}

void MeshRenderer::render(Shader& shader, RenderingEngine* renderingEngine) {
    shader.bind();
    shader.updateUniforms(*getParent()->getTransform(), material, renderingEngine);
    mesh.render();
}

void MeshRenderer::processInput(const Input &input, float d_time) {

}

void MeshRenderer::update(float d_time) {

}
