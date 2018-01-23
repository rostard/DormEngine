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

private:
    static const Matrix4f biasMatrix;

    std::vector<BaseLight*> lights;
    BaseLight* activeLight;
    Camera* mainCamera;
    std::vector<unsigned int> samplers;
    Matrix4f lightMatrix;
    GameObject* m_plainObject;
    Camera* m_altCamera;
    Camera* m_planeCamera;
};


#endif //DORMENGINE_RENDERINGENGINE_H
