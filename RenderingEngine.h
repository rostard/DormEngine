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
#include "Profiling.h"


class BaseLight;
class Camera;
class GameObject;
class Framebuffer;
class Shader;
class Mesh;
class Material;
class Window;

class RenderingEngine : public MappedValues{
public:
    RenderingEngine(Window* window);
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
    void applyFilter(Shader* shader, Texture* source1, Texture* source2, Framebuffer* dest);

    void blurShadowMap7x7(int shadowMapIndex, float blurAmount);
    void blurBloom(float blurAmount);

    double displayRenderTime(double delimeter = 0);
    double displayWindowSyncTime(double delimeter = 0);
private:
    ProfileTimer renderProfileTimer;
    ProfileTimer windowSyncProfileTimer;
    static const Matrix4f biasMatrix;
    static const int maxResolutionOfShadowMapAsPowerOf2 = 10;

    Window* window;

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
    Shader* m_hdrFilter;

    Framebuffer* m_shadowMaps[maxResolutionOfShadowMapAsPowerOf2];
    Framebuffer* m_shadowMapTempTargets[maxResolutionOfShadowMapAsPowerOf2];
    Framebuffer* HDRFramebuffer;
    Framebuffer* BloomFramebuffer;
    Framebuffer* BloomTempFramebuffer;
};


#endif //DORMENGINE_RENDERINGENGINE_H
