//
// Created by rostard on 14.12.17.
//

#include <glad/glad.h>
#include "RenderingEngine.h"
#include "Window.h"

RenderingEngine::RenderingEngine() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH_CLAMP);
    glEnable(GL_TEXTURE_2D);


    mainCamera = new Camera(70.0f * (M_PI / 180.0f), Window::getSize().getX() / Window::getSize().getY(), 0.01f, 1000.0f);
}

void RenderingEngine::render(GameObject& object, Shader& shader) {
    clearScreen();

    object.render(shader);
}

void RenderingEngine::clearScreen() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

std::string RenderingEngine::getOpenGLVersion() {
    return std::string((char*)glGetString(GL_VERSION));
}

Camera *RenderingEngine::getMainCamera() const {
    return mainCamera;
}

void RenderingEngine::setMainCamera(Camera *mainCamera) {
    RenderingEngine::mainCamera = mainCamera;
}


