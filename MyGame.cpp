//
// Created by rostard on 18.12.17.
//

#include "MyGame.h"
#include "resource_management/ResourceManager.h"
#include "components/MeshRenderer.h"
#include "Input.h"
#include "components/DirectionalLight.h"
#include "components/PointLight.h"

void MyGame::init() {

    root =  new GameObject();

    Game::init();
//    camera = new Camera();

    plane = new GameObject();
    root->addChild(plane);


    texture = ResourceManager::loadTexture("rock", "test.png");
    texture->bind();
    mesh = ResourceManager::loadMesh("rock", "plane/plane.obj");

    Material material;
    plane->addComponent(new MeshRenderer(*mesh, material));

    GameObject* dirLightObject = new GameObject();
    DirectionalLight* dirLight = new DirectionalLight(Vector3f(1.0f, 0.0f, 0.0f), 0.5f, Vector3f(-1.0f, -1.0f, -1.0f));
    DirectionalLight* dirLight2 = new DirectionalLight(Vector3f(0.0f, 0.0f, 1.0f), 0.5f, Vector3f(1.0f, -1.0f, 1.0f));
    dirLightObject->addComponent(dirLight);
    dirLightObject->addComponent(dirLight2);
    root->addChild(dirLightObject);
//
    pointLightObject = new GameObject();
    PointLight* pointLight = new PointLight(Vector3f(0.0f, 1.0f, 0.0f), 1.0f, Vector3f(0, 0, 1));
//    PointLight* pointLight2 = new PointLight(Vector3f(1.0f, 0.0f, 0.0f), 2.0f);
    pointLightObject->addComponent(pointLight);
//    pointLightObject->addComponent(pointLight2);
    root->addChild(pointLightObject);

}


void MyGame::input(float d_time) {
    Game::input(d_time);
    Input::update();
}

void MyGame::update(float d_time) {
    static float allTime = 0;
    allTime += d_time;
    Game::update(d_time);
    pointLightObject->getTransform()->setTranslation(sin(allTime) * 10.0f, 0.0f, cos(allTime) * 10.0f);
//    plane->getTransform()->setRotation(allTime * 2.0f,allTime * 20.0f,allTime * 10.0f);
//    plane->getTransform()->setTranslation(sin(allTime),0,5.0f);
//    plane->getTransform()->setScale(sin(allTime)*2, sin(allTime)*2, 1);
}
