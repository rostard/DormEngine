//
// Created by rostard on 18.12.17.
//

#include "MyGame.h"
#include "resource_management/ResourceManager.h"

void MyGame::init() {
    Game::init();
    shader =  ResourceManager::loadShader("simple_shader", "SimpleVertex.vs", "SimpleFragment.fs");
    shader->bind();

    texture = ResourceManager::loadTexture("test", "test.png");
    texture->bind();

    shader->setInt("tex", 0);

    mesh = new Mesh();
    transform = new Transform();
    std::vector<Vertex> vertices;
    vertices.emplace_back(glm::vec3(-0.5, -0.5, 1.0), glm::vec2(0.0, 0.0));
    vertices.emplace_back(glm::vec3(-0.5,  0.5, 1.0), glm::vec2(0.0, 1.0));
    vertices.emplace_back(glm::vec3( 0.5, 0.5, 1.0), glm::vec2(1.0, 1.0));
    vertices.emplace_back(glm::vec3( 0.5, -0.5, 1.0), glm::vec2(1.0, 0.0));
    std::vector<unsigned int> indices;
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);

    indices.push_back(0);
    indices.push_back(2);
    indices.push_back(3);

    mesh->addVertices(vertices, indices);

}

void MyGame::render() {
    Game::render();
    shader->setMat4("transform", transform->getProjectedTransformation());
    mesh->render();
}

void MyGame::update(float d_time) {
    static float allTime = 0;
    allTime += d_time;
    Game::update(d_time);

    transform->setRotation(0,0,allTime * 10.0f);
    transform->setTranslation(sin(allTime),0,0);
    transform->setScale(sin(allTime)*2, sin(allTime)*2, 1);

}
