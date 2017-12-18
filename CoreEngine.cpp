//
// Created by rostard on 14.12.17.
//

#include "CoreEngine.h"
#include "Shader.h"
#include "Mesh.h"
#include "resource_management/ShaderLoader.h"
#include "resource_management/ResourceManager.h"
#include "resource_management/TextureLoader.h"
#include "Transform.h"

CoreEngine::CoreEngine(unsigned int width, unsigned int height, unsigned int framerate, Game &game) : width(width), height(height), game(game){
    isRunning = false;
    frameTime = 1.0 / framerate;
}

CoreEngine::~CoreEngine() {
    delete renderingEngine;
}

void CoreEngine::cleanUp() {
    Window::dispose();
}

void CoreEngine::start() {
    if(isRunning)
        return;

    run();
}

void CoreEngine::stop() {
    isRunning = false;
}

void CoreEngine::createWindow(const std::string &title) {
    Window::initGLFW();
    Window::createWindow(width, height, title);
    this->renderingEngine = new RenderingEngine();
}

void CoreEngine::run() {
    this->isRunning = true;
    double lastTime = glfwGetTime();

    double frameTime = 1.0 / 90.0;
    double passedTime = 0.0;

    int frames = 0;
    double framesCounter = 0;

    Shader shader =  *ResourceManager::loadShader("simple_shader", "SimpleVertex.vs", "SimpleFragment.fs");
    shader.bind();

    Texture texture = *ResourceManager::loadTexture("test", "test.png");
    texture.bind();

    shader.setInt("tex", 0);
    Transform transform;

    //transform.setRotation(90.0f, 0.0f, 0.0f);
//    transform.getTransformation();
    Mesh mesh;
    std::vector<Vertex> vertices;
    vertices.emplace_back(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 0.0));
    vertices.emplace_back(glm::vec3(-0.5,  0.5, 0.0), glm::vec2(0.0, 1.0));
    vertices.emplace_back(glm::vec3( 0.5, 0.5, 0.0), glm::vec2(1.0, 1.0));
    vertices.emplace_back(glm::vec3( 0.5, -0.5, 0.0), glm::vec2(1.0, 0.0));
    std::vector<unsigned int> indices;
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);

    indices.push_back(0);
    indices.push_back(2);
    indices.push_back(3);

    mesh.addVertices(vertices, indices);

    while(this->isRunning){
        double curTime = glfwGetTime();
        double deltaTime = curTime - lastTime;
        lastTime = curTime;
        bool render = false;

        passedTime += deltaTime;
        framesCounter += deltaTime;

        while(passedTime > frameTime){
            transform.setRotation(0,0,curTime*1000.0f);
            transform.setTranslation(sin(curTime),0,0);
            render = true;
            passedTime-=frameTime;

            glfwPollEvents();
            if(Window::isShouldClose())this->isRunning = false;

            game.update(deltaTime);
            game.input(deltaTime);

            if(framesCounter >= 1.0){
                //TODO: print number of frames
                frames = 0;
                framesCounter =0;
            }
        }
        if(render){
            frames++;
            shader.setMat4("transform", transform.getTransformation());
            mesh.render();
            Window::render();
        } else{
//                std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    cleanUp();
}

