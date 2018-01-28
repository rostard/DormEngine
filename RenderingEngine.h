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

    void blurShadowMap7x7(int shadowMapIndex, float blurAmount);
private:
    static const Matrix4f biasMatrix;
    static const int maxResolutionOfShadowMapAsPowerOf2 = 10;

    std::vector<BaseLight*> lights;
    BaseLight* activeLight;
    Matrix4f lightMatrix;

    Camera* mainCamera;

    std::vector<unsigned int> samplers;

    Mesh* m_plain;
    Material* m_plainMaterial;
    Camera* m_plainCamera;
    GameObject* m_plainCameraObject;

    Camera* m_altCamera;
    GameObject* m_altCameraObject;

    Shader* m_gausBlurFilter;

    Framebuffer* m_shadowMaps[maxResolutionOfShadowMapAsPowerOf2];
    Framebuffer* m_shadowMapTempTargets[maxResolutionOfShadowMapAsPowerOf2];
};


#endif //DORMENGINE_RENDERINGENGINE_H
