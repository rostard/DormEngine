//
// Created by rostard on 14.12.17.
//

#include <glad/glad.h>
#include <iostream>
#include "RenderingEngine.h"
#include "Window.h"
#include "components/Camera.h"
#include "GameObject.h"
#include "resource_management/ResourceManager.h"
#include "components/BaseLight.h"
#include "Framebuffer.h"
#include "components/MeshRenderer.h"


const Matrix4f RenderingEngine::biasMatrix = Matrix4f().initScale(0.5, 0.5, 0.5) * Matrix4f().initTranslation(1.0, 1.0, 1.0);

RenderingEngine::RenderingEngine() {

    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH_CLAMP);
    glEnable(GL_TEXTURE_2D);
//    glEnable(GL_MULTISAMPLE);

    Vector3f ambientLight =  Vector3f(0.2f, 0.2f, 0.2f);
    setVector3f("ambientLight", ambientLight);

    int filter = GL_LINEAR;
    GLenum attachment = GL_COLOR_ATTACHMENT0;
    GLenum format = GL_RGBA;
    GLint internalFormat = GL_RG32F;
    m_shadowMapFramebuffer = new Framebuffer(1, 2048, 2048, &internalFormat, &format, &filter, &attachment);

    std::vector<Vertex> vertices = { Vertex(Vector3f(-1,-1,-1),Vector2f(0,0)),
                          Vertex(Vector3f(-1,1,-1),Vector2f(0,1)),
                          Vertex(Vector3f(1,1,-1),Vector2f(1,1)),
                          Vertex(Vector3f(1,-1,-1),Vector2f(1,0)) };

    std::vector<unsigned int> indices = { 1, 2, 0,
                                        2, 3, 0 };

    Material material;
    material.setTexture("diffuse", m_shadowMapFramebuffer->getTextureId(0));

    m_plainObject = new GameObject();
    m_plainObject->addComponent(new MeshRenderer(Mesh(vertices, indices), material));
    setVector3f("shadowTexelSize", Vector3f(1.0f/2048.0f, 1.0f/2048.0f, 0.0f));
    setTexture("shadowMap", m_shadowMapFramebuffer->getTextureId(0));
    m_plainObject->getTransform()->setScale(0.5f, 0.5f, 0.5f);
    m_plainObject->getTransform()->setPos(0.5f, 0.5f, 0.0f);
    m_altCamera = new Camera(Matrix4f().initIdentity());
    m_planeCamera = new Camera(Matrix4f().initIdentity());
    m_planeCameraObject = new GameObject;
    m_planeCameraObject->addComponent(m_planeCamera);
    m_altCameraObject = new GameObject();
    m_altCameraObject->addComponent(m_altCamera);
}


RenderingEngine::~RenderingEngine() {

}

void RenderingEngine::render(GameObject& object) {
    std::cout<<mainCamera->getTransform().getPos().getY()<<std::endl;
    Window::bindAsRenderTarget();
    clearScreen();

    Shader * ambientShader = ResourceManager::loadShader("forward-ambient_shader", "forward-ambient.vs.glsl", "forward-ambient.fs.glsl");
    Shader* shadowMapGenerator = ResourceManager::loadShader("shadowMapGenerator", "shadow_map.vs.glsl", "shadow_map.fs.glsl");

    object.renderAll(*ambientShader, this);


    for(auto light : lights){
        activeLight = light;
        ShadowInfo* shadowInfo = light->getShadowInfo();
        if(shadowInfo) {
            m_shadowMapFramebuffer->bindAsRenderTarget();
            glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
            Camera* temp = mainCamera;

            m_altCamera->setProjection(shadowInfo->getProjection());

            m_altCamera->getTransform().setPos(light->getTransform().getTransformedPos());
            m_altCamera->getTransform().setRot(light->getTransform().getTransformedRot());

            lightMatrix = biasMatrix * m_altCamera->getViewProjection();

            mainCamera = m_altCamera;

            object.renderAll(*shadowMapGenerator, this);

            mainCamera = temp;
        }

        Window::bindAsRenderTarget();

        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_ONE);
        glDepthMask(static_cast<GLboolean>(false));
        glDepthFunc(GL_EQUAL);

        object.renderAll(*light->getShader(), this);

        glDepthFunc(GL_LESS);
        glDepthMask(static_cast<GLboolean>(true));
        glDisable(GL_BLEND);
    }


//  //Temp Render
    Window::bindAsRenderTarget();
//
    Camera* temp = mainCamera;
    mainCamera = m_planeCamera;


    m_plainObject->render(*ResourceManager::loadShader("default_shader", "default_shader.vs.glsl", "default_shader.fs.glsl") ,this);
//
    mainCamera = temp;

}

void RenderingEngine::clearScreen() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

std::string RenderingEngine::getOpenGLVersion() {
    return std::string((char*)glGetString(GL_VERSION));
}

Camera *RenderingEngine::getMainCamera() const {
    return mainCamera;
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

unsigned int RenderingEngine::getSamplerSlot(const std::string &samplerName) {
    unsigned int id = SID(samplerName);

    for(unsigned int i = 0; i < samplers.size(); ++i){
        if(id == samplers[i])
            return i;
    }

    samplers.push_back(id);
    return samplers.size()-1;
}

const Matrix4f &RenderingEngine::getLightMatrix() const {
    return lightMatrix;
}



