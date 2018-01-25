//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_RENDERINGENGINE_H
#define DORMENGINE_RENDERINGENGINE_H

#include <string>
#include <vector>

#include "math/Vector3f.h"
#include "MappedValues.h"
#include "math/Matrix4f.h"


class BaseLight;
class Camera;
class GameObject;
class Framebuffer;
class Shader;
class Mesh;
class Material;

class RenderingEngine : public MappedValues{
public:
    RenderingEngine();
    virtual ~RenderingEngine();
    void render(GameObject& object);

    void clearScreen();

    static std::string getOpenGLVersion();

    Camera *getMainCamera() const;

    BaseLight *getActiveLight() const;

    void addLight(BaseLight* light);

    void addCamera(Camera* camera);

    unsigned int getSamplerSlot(const std::string& samplerName);

    const Matrix4f &getLightMatrix() const;

    void applyFilter(Shader* shader, Texture* source, Framebuffer* dest);

    void blurTexture7x7(Framebuffer* framebuffer, float blurAmount);
private:
    static const Matrix4f biasMatrix;

    std::vector<BaseLight*> lights;
    BaseLight* activeLight;
    Camera* mainCamera;
    std::vector<unsigned int> samplers;
    Matrix4f lightMatrix;
    Mesh* m_plain;
    Camera* m_altCamera;
    Camera* m_plainCamera;
    GameObject* m_plainCameraObject;
    GameObject* m_altCameraObject;
    Framebuffer* m_shadowMapFramebuffer;
    Material* m_plainMaterial;
    Shader* m_gausBlurFilter;
    Framebuffer* m_shadowMapTempTarget;
};


#endif //DORMENGINE_RENDERINGENGINE_H
