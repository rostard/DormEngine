//
// Created by rostard on 18.12.17.
//

#include "MyGame.h"
#include "resource_management/ResourceManager.h"
#include "components/MeshRenderer.h"

void MyGame::init() {

    root =  new GameObject();

    Game::init();


    plane = new GameObject();
    root->addChild(plane);


    texture = ResourceManager::loadTexture("test", "test.png");
    texture->bind();
    mesh = ResourceManager::loadMesh("test", "cube/cube.obj");

    Material material;
    plane->addComponent(new MeshRenderer(*mesh, material));

}



void MyGame::update(float d_time) {
    static float allTime = 0;
    allTime += d_time;
    Game::update(d_time);

    plane->getTransform()->setRotation(allTime * 2.0f,allTime * 20.0f,allTime * 10.0f);
    plane->getTransform()->setTranslation(sin(allTime),0,5.0f);
//    plane->getTransform()->setScale(sin(allTime)*2, sin(allTime)*2, 1);
}
