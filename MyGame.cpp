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

static GameObject* dirLightObject;

void MyGame::init() {
    Game::init();
//    camera = new Camera();

    plane = new GameObject();
    addObject(plane);


    texture = ResourceManager::loadTexture("test", "test.png");
    mesh = ResourceManager::loadMesh("plane", "plane/plane.obj");
    plane->getTransform()->setPos(0, -1, 0);
    Material cleanMaterial;
    Material material;
    material.setTexture("diffuse", ResourceManager::loadTexture("bricks", "bricks2.jpg"));
    material.setTexture("normalMap", ResourceManager::loadTexture("bricks_normal", "bricks2_normal.jpg"));
    material.setTexture("dispMap", ResourceManager::loadTexture("bricks_disp", "bricks2_disp.jpg"));
    material.setFloat("dispMapScale", 0.03f);
//    material.setFloat("dispMapOffset", -0.015f);
    material.setFloat("shininess", 20);
    material.setFloat("specularIntensity", 1);
    plane->addComponent(new MeshRenderer(*mesh, material));

    dirLightObject = new GameObject();
    GameObject* dirLightObject2 = new GameObject();
    DirectionalLight* dirLight = new DirectionalLight(Vector3f(1.0f, 1.0f, 1.0f), 0.5f, 10, 20);
    DirectionalLight* dirLight2 = new DirectionalLight(Vector3f(0.0f, 0.0f, 1.0f), 0.5f);
    dirLightObject->addComponent(dirLight);
    dirLightObject->getTransform()->setRot(Quaternion(Vector3f(1.0f, 0.0f, 0.0f), M_PI_4));
    dirLightObject->getTransform()->setPos(0, 1, 0);
    dirLightObject2->addComponent(dirLight2);
    addObject(dirLightObject);
    dirLightObject2->getTransform()->setRot(Quaternion(Vector3f(0,1,0), M_PI));
//    addObject(dirLightObject2);



    Mesh * cube = ResourceManager::loadMesh("cube", "cube/cube.obj");

    pointLightObject = new GameObject();
    PointLight* pointLight = new PointLight(Vector3f(0.0f, 1.0f, 0.0f), 1.0f, Vector3f(0, 0, 1));
//    pointLightObject->addComponent(pointLight);
    pointLightObject->addComponent(new MeshRenderer(*cube, cleanMaterial));
//    pointLightObject->getTransform()->setScale(0.1f, 0.1f, 0.1f);
    pointLightObject->getTransform()->setPos(4.0f, 0.0f, 0.0f);


    spotLightObject = new GameObject();

    SpotLight* spotLight = new SpotLight(Vector3f(1.0f, 1.0f, 1.0f), 4.0f, Vector3f(0, 0, 1), M_PI_4, M_PI_4, 7);
    spotLightObject->addComponent(spotLight);
    spotLightObject->addComponent(new MeshRenderer(*cube, cleanMaterial));
    spotLightObject->getTransform()->setScale(0.1f, 0.1f, 0.1f);
    spotLightObject->getTransform()->setPos(0.0f, 1.0f, 0.0f);
    spotLightObject->getTransform()->setRot(Quaternion(Vector3f(1.0, 0, 0), M_PI_2));

    addObject(spotLightObject);
    spotLightObject->addChild(pointLightObject);

    GameObject* wolfObject = new GameObject();
    Mesh* wolfMesh = ResourceManager::loadMesh("wolf", "wolf/wolf.obj");
    wolfObject->addComponent(new MeshRenderer(*wolfMesh, cleanMaterial));
    spotLightObject->addChild(wolfObject);
    wolfObject->getTransform()->setPos(0, 0.8, 4);
    wolfObject->getTransform()->setScale(0.4, 0.4, 0.4);

    GameObject* wolfObject2 = new GameObject();
    wolfObject2->addComponent(new MeshRenderer(*wolfMesh, cleanMaterial));
    spotLightObject->addChild(wolfObject2);
    wolfObject2->getTransform()->setPos(0, 0.8, -4);
    wolfObject2->getTransform()->setScale(0.4, 0.4, 0.4);

    GameObject* wolfObject3 = new GameObject();
    wolfObject3->addComponent(new MeshRenderer(*wolfMesh, cleanMaterial));
    spotLightObject->addChild(wolfObject3);
    wolfObject3->getTransform()->setPos(4, 0.8, 0);
    wolfObject3->getTransform()->setScale(0.4, 0.4, 0.4);

    GameObject* wolfObject4 = new GameObject();
    wolfObject4->addComponent(new MeshRenderer(*wolfMesh, cleanMaterial));
    spotLightObject->addChild(wolfObject4);
    wolfObject4->getTransform()->setPos(-4, 0.8, 0);


    GameObject* cameraObject = new GameObject();
    Camera* camera = new Camera(70.0f * (M_PI / 180.0f), Window::getSize().getX() / Window::getSize().getY(), 0.01f, 1000.0f);
    cameraObject->addComponent(camera);
//    cameraObject->addComponent(new SpotLight(Vector3f(1.0f, 1.0f, 1.0f), 4.0f, Vector3f(1, 1, 0.5f), M_PI_4, M_PI_4));
    addObject(cameraObject);
}


void MyGame::input(float d_time) {
    Game::input(d_time);
    Input::update();
}

void MyGame::update(float d_time) {
    static float allTime = 0;
    allTime += d_time;
    Game::update(d_time);
//    pointLightObject->getTransform()->setPos(sin(allTime) * 10.0f, 0.0f, cos(allTime) * 10.0f);
    spotLightObject->getTransform()->setRot(Quaternion(Vector3f(1.0f, 0.0, 0.0), allTime));
    dirLightObject->getTransform()->rotate(Vector3f(0.0, 1.0, 0.0), d_time/10);
}
