//
// Created by rostard on 14.12.17.
//

#include <glad/glad.h>
#include "RenderingEngine.h"
#include "Window.h"
#include "components/Camera.h"
#include "GameObject.h"
#include "resource_management/ResourceManager.h"
#include "components/BaseLight.h"
#include "Framebuffer.h"
#include "components/MeshRenderer.h"

//Temp variables
static Framebuffer* g_tempTarget = 0;
static Mesh* g_mesh = 0;
static GameObject* g_meshObject = 0;
static Transform g_transform;
static Material* g_material;
static Camera* g_camera = 0;
static GameObject* g_cameraObject = 0;

RenderingEngine::RenderingEngine() {

    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH_CLAMP);
    glEnable(GL_TEXTURE_2D);

    Vector3f ambientLight =  Vector3f(0.2f, 0.2f, 0.2f);
    addVector3f("ambientLight", ambientLight);

    //Begin Temp initialization
    if(g_mesh) delete g_mesh;
    if(g_material) delete g_material;
    if(g_cameraObject) delete g_cameraObject;

    int width = Window::getSize().getX() / 3;
    int height = Window::getSize().getY() / 3;

    int filter = GL_LINEAR;
    int attachment = GL_COLOR_ATTACHMENT0;
    g_tempTarget = new Framebuffer(1, width, height, &filter, &attachment);

    std::vector<Vertex> vertices = { Vertex(Vector3f(-1,-1,-1),Vector2f(0,0)),
                          Vertex(Vector3f(-1,1,-1),Vector2f(0,1)),
                          Vertex(Vector3f(1,1,-1),Vector2f(1,1)),
                          Vertex(Vector3f(1,-1,-1),Vector2f(1,0)) };

    std::vector<unsigned int> indices = { 1, 2, 0,
                                        2, 3, 0 };

    g_material = new Material();
    g_material->addTexture("diffuse", g_tempTarget->getTextureId(0));
    g_mesh = new Mesh(vertices, indices);

    g_meshObject = new GameObject();
    g_meshObject->addComponent(new MeshRenderer(*g_mesh, *g_material));

    g_meshObject->getTransform()->setScale(0.9f, 0.9f, 0.9f);
    g_camera = new Camera(Matrix4f().initIdentity());
    g_cameraObject = new GameObject();
    g_cameraObject->addComponent(g_camera);
//    g_camera->getTransform().rotate(Vector3f(0,1,0), 2*M_PI);//getTransform()->rotate(Vector3f(0,1,0), M_PI_2);
}


RenderingEngine::~RenderingEngine() {
    //Temp destruction
//    if(g_mesh) delete g_mesh;
//    if(g_material) delete g_material;
//    if(g_cameraObject) delete g_cameraObject;
}

void RenderingEngine::render(GameObject& object) {
    g_tempTarget->bindAsRenderTarget();
    clearScreen();

    Shader * ambientShader = ResourceManager::loadShader("forward-ambient_shader", "forward-ambient.vs.glsl", "forward-ambient.fs.glsl");

    object.renderAll(*ambientShader, this);

    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glDepthMask(static_cast<GLboolean>(false));
    glDepthFunc(GL_EQUAL);

    for(auto light : lights){
        activeLight = light;
        object.renderAll(*light->getShader(), this);
    }

    glDepthFunc(GL_LESS);
    glDepthMask(static_cast<GLboolean>(true));
    glDisable(GL_BLEND);

    //Temp Render
    Window::bindAsRenderTarget();
//
    Camera* temp = mainCamera;
    mainCamera = g_camera;
//
    glClearColor(0.0f,0.0f,1.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////    ResourceManager::getShader("forward-ambient_shader")->bind();
////    ResourceManager::getShader("forward-ambient_shader")->updateUniforms(g_transform, *g_material, this);
////    g_mesh->render();
    g_meshObject->render(*ResourceManager::loadShader("default_shader", "default_shader.vs.glsl", "default_shader.fs.glsl") ,this);
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



