//
// Created by rostard on 18.12.17.
//

#include "MyGame.h"
#include "resource_management/ResourceManager.h"
#include "components/MeshRenderer.h"
#include "Input.h"
#include "components/DirectionalLight.h"
#include "components/PointLight.h"
#include "components/SpotLight.h"

void MyGame::init() {

    root =  new GameObject();

    Game::init();
//    camera = new Camera();

    plane = new GameObject();
    root->addChild(plane);


    texture = ResourceManager::loadTexture("test", "test.png");
    texture->bind();
    mesh = ResourceManager::loadMesh("plane", "plane/plane.obj");

    Material material;
    plane->addComponent(new MeshRenderer(*mesh, material));

//    GameObject* dirLightObject = new GameObject();
//    DirectionalLight* dirLight = new DirectionalLight(Vector3f(1.0f, 0.0f, 0.0f), 0.5f, Vector3f(-1.0f, -1.0f, -1.0f));
//    DirectionalLight* dirLight2 = new DirectionalLight(Vector3f(0.0f, 0.0f, 1.0f), 0.5f, Vector3f(1.0f, -1.0f, 1.0f));
//    dirLightObject->addComponent(dirLight);
//    dirLightObject->addComponent(dirLight2);
//    root->addChild(dirLightObject);


    Mesh * cube = ResourceManager::loadMesh("cube", "cube/cube.obj");

    pointLightObject = new GameObject();
    PointLight* pointLight = new PointLight(Vector3f(0.0f, 1.0f, 0.0f), 1.0f, Vector3f(0, 0, 1));
    pointLightObject->addComponent(pointLight);
    pointLightObject->addComponent(new MeshRenderer(*cube, material));
    pointLightObject->getTransform()->setScale(0.1f, 0.1f, 0.1f);
    root->addChild(pointLightObject);


    spotLightObject = new GameObject();
    SpotLight* spotLight = new SpotLight(Vector3f(0.0f, 1.0f, 0.0f), 1.0f, Vector3f(0, 0, 1), 0.7f);
    spotLightObject->addComponent(spotLight);
    spotLightObject->addComponent(new MeshRenderer(*cube, material));
    spotLightObject->getTransform()->setScale(0.1f, 0.1f, 0.1f);
    root->addChild(spotLightObject);

    Camera* camera = new Camera(70.0f * (M_PI / 180.0f), Window::getSize().getX() / Window::getSize().getY(), 0.01f, 1000.0f);
    root->addComponent(camera);
}


void MyGame::input(float d_time) {
    Game::input(d_time);
    Input::update();
}

void MyGame::update(float d_time) {
    static float allTime = 0;
    allTime += d_time;
    Game::update(d_time);
    pointLightObject->getTransform()->setPos(sin(allTime) * 10.0f, 0.0f, cos(allTime) * 10.0f);
    spotLightObject->getTransform()->setRot(Quaternion(Vector3f(1.0f, 0.0, 0.0), allTime));
//    plane->getTransform()->setRotation(allTime * 2.0f,allTime * 20.0f,allTime * 10.0f);
//    plane->getTransform()->setTranslation(sin(allTime),0,5.0f);
//    plane->getTransform()->setScale(sin(allTime)*2, sin(allTime)*2, 1);
}
