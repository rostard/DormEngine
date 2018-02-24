//
// Created by rostard on 14.12.17.
//

#include <iostream>
#include <cassert>
#include "RenderingEngine.h"
#include "Window.h"
#include "components/Camera.h"
#include "GameObject.h"
#include "resource_management/ResourceManager.h"
#include "components/BaseLight.h"
#include "Framebuffer.h"

const Matrix4f RenderingEngine::biasMatrix = Matrix4f().initScale(0.5, 0.5, 0.5) * Matrix4f().initTranslation(1.0, 1.0, 1.0);



RenderingEngine::RenderingEngine(Window *window): window(window) {

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


    for(int i = 0; i < maxResolutionOfShadowMapAsPowerOf2; i++){
        int resolution = 1 << (i + 1);
        m_shadowMaps[i] = new Framebuffer(1, resolution, resolution, &internalFormat, &format, &filter, &attachment);
        m_shadowMaps[i]->getTextureId(0)->bind(getSamplerSlot("shadowMap"));
        float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
        m_shadowMapTempTargets[i] = new Framebuffer(1, resolution, resolution, &internalFormat, &format, &filter, &attachment);
    }

    std::vector<Vertex> vertices = { Vertex(Vector3f(-1,-1,-1),Vector2f(0,0)),
                          Vertex(Vector3f(-1,1,-1),Vector2f(0,1)),
                          Vertex(Vector3f(1,1,-1),Vector2f(1,1)),
                          Vertex(Vector3f(1,-1,-1),Vector2f(1,0)) };

    std::vector<unsigned int> indices = { 1, 2, 0,
                                        2, 3, 0 };

    Material material;

    m_plain = new Mesh(vertices, indices);
    m_altCamera = new Camera(Matrix4f().initIdentity());
    m_plainCamera = new Camera(Matrix4f().initIdentity());
    m_plainCameraObject = new GameObject;
    m_plainCameraObject->addComponent(m_plainCamera);
    m_altCameraObject = new GameObject();
    m_altCameraObject->addComponent(m_altCamera);
    m_plainMaterial = new Material();
    m_gausBlurFilter = ResourceManager::loadShader("gausBlur1x7", "filter-gausBlur1x7.vs.glsl", "filter-gausBlur1x7.fs.glsl");
    m_hdrFilter = ResourceManager::loadShader("hdr", "filter-hdr.vs.glsl", "filter-hdr.fs.glsl");
    preRenderFramebuffer = new Framebuffer(1, window->getSize().getX(), window->getSize().getY(), new GLint(GL_RGBA16F), &format, new int(GL_NEAREST),  new GLenum(GL_COLOR_ATTACHMENT0));

}


RenderingEngine::~RenderingEngine() {

}

void RenderingEngine::render(GameObject& object) {
//    window->bindAsRenderTarget();
    preRenderFramebuffer->bindAsRenderTarget();
    clearScreen();

    Shader* ambientShader = ResourceManager::loadShader("forward-ambient_shader", "forward-ambient.vs.glsl", "forward-ambient.fs.glsl");
    Shader* shadowMapGenerator = ResourceManager::loadShader("shadowMapGenerator", "shadow_map.vs.glsl", "shadow_map.fs.glsl");
    object.renderAll(*ambientShader, this);


    for(auto light : lights){
        activeLight = light;
        ShadowInfo* shadowInfo = light->getShadowInfo();
        int shadowMapIndex = 0;
        if(shadowInfo) {
            shadowMapIndex = shadowInfo->getResolutionAsPowerOf2() - 1;
        }

        setTexture("shadowMap", m_shadowMaps[shadowMapIndex]->getTextureId(0));
        m_shadowMaps[shadowMapIndex]->bindAsRenderTarget();
        glClearColor(1.0f, 1.0f, 0.0, 0.0);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        if(shadowInfo){

            Camera* temp = mainCamera;

            m_altCamera->setProjection(shadowInfo->getProjection());
            ShadowCameraTransform shadowCameraTransform = light->calcShadowCameraTransform(mainCamera->getTransform().getTransformedPos(), mainCamera->getTransform().getTransformedRot());
            m_altCamera->getTransform().setPos(shadowCameraTransform.pos);
            m_altCamera->getTransform().setRot(shadowCameraTransform.rot);

            lightMatrix = biasMatrix * m_altCamera->getViewProjection();

            mainCamera = m_altCamera;

            bool flipFaces = shadowInfo->getFlipFaces();

            if(flipFaces){
                glCullFace(GL_FRONT);
            }

            object.renderAll(*shadowMapGenerator, this);

            if(flipFaces){
                glCullFace(GL_BACK);
            }

            mainCamera = temp;

            setFloat("minVariance", shadowInfo->getMinVariance());
            setFloat("lightBleedReductionAmount", shadowInfo->getLightBleedReductionAmount());

            float shadowSoftness = shadowInfo->getShadowSoftness();
            if(shadowSoftness != 0) blurShadowMap7x7(shadowMapIndex, shadowSoftness);
        }
        else{
            lightMatrix = Matrix4f().initScale(0, 0, 0);
            setFloat("minVariance", 0.0002f);
            setFloat("lightBleedReductionAmount", 0);
        }

//        window->bindAsRenderTarget();
        setFloat("exposure", 0.5);
        preRenderFramebuffer->bindAsRenderTarget();

        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_ONE);
        glDepthMask(static_cast<GLboolean>(false));
        glDepthFunc(GL_EQUAL);

        object.renderAll(*light->getShader(), this);
        glDepthFunc(GL_LESS);
        glDepthMask(static_cast<GLboolean>(true));
        glDisable(GL_BLEND);

        applyFilter(m_hdrFilter, preRenderFramebuffer->getTextureId(0), nullptr);
    }
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

void RenderingEngine::applyFilter(Shader *shader, Texture *source, Framebuffer *dest) {

    if(dest == nullptr){
        window->bindAsRenderTarget();
    } else{
        assert(source->getId() != dest->getTextureId(0)->getId());
        dest->bindAsRenderTarget();
    }
    glClear(GL_DEPTH_BUFFER_BIT);
    m_plainMaterial->setTexture("sourceTexture", source);

    Camera* temp = mainCamera;
    mainCamera = m_plainCamera;

    shader->bind();
    Transform transform;
    shader->updateUniforms(transform, *m_plainMaterial, this);
    m_plain->render();

    mainCamera = temp;

}

void RenderingEngine::blurShadowMap7x7(int shadowMapIndex, float blurAmount)
{
    Framebuffer* shadowMap = m_shadowMaps[shadowMapIndex];
    Framebuffer* shadowMapTempTarget = m_shadowMapTempTargets[shadowMapIndex];

    setVector3f("blurScale", Vector3f(blurAmount / shadowMap->getWidth(), 0.0f, 0.0f));
    applyFilter(m_gausBlurFilter, shadowMap->getTextureId(0), shadowMapTempTarget);
    setVector3f("blurScale", Vector3f(0.0f, blurAmount / shadowMap->getHeight(), 0.0f));
    applyFilter(m_gausBlurFilter, shadowMapTempTarget->getTextureId(0), shadowMap);
}

