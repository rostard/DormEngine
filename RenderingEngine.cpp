//
// Created by rostard on 14.12.17.
//

#include <glad/glad.h>
#include "RenderingEngine.h"
#include "Window.h"
#include "components/Camera.h"
#include "ForwardAmbient.h"
#include "ForwardDirectional.h"
#include "ForwardPoint.h"
#include "GameObject.h"
#include "resource_management/ResourceManager.h"
#include "components/BaseLight.h"

RenderingEngine::RenderingEngine() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH_CLAMP);
    glEnable(GL_TEXTURE_2D);

    //Temporary
    ambientLight = Vector3f(0.2f, 0.2f, 0.2f);
}

void RenderingEngine::render(GameObject& object) {

    clearScreen();

    lights.clear();
    object.addToRenderingEngine(*this);

    ForwardAmbient * ambientShader = new ForwardAmbient(*ResourceManager::loadShader("forward-ambient_shader", "forward-ambient.vs.glsl", "forward-ambient.fs.glsl"));

    object.render(*ambientShader, this);

    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glDepthMask(static_cast<GLboolean>(false));
    glDepthFunc(GL_EQUAL);

    for(auto light : lights){
        activeLight = light;
        object.render(*light->getShader(), this);
    }

    glDepthFunc(GL_LESS);
    glDepthMask(static_cast<GLboolean>(true));
    glDisable(GL_BLEND);

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

Vector3f RenderingEngine::getAmbientLight() {
    return ambientLight;
}

BaseLight *RenderingEngine::getActiveLight() const {
    return activeLight;
}

void RenderingEngine::addLight(BaseLight *light) {
    lights.push_back(light);
}

void RenderingEngine::addCamera(Camera *camera) {
    mainCamera = camera;
}


