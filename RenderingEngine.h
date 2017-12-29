//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_RENDERINGENGINE_H
#define DORMENGINE_RENDERINGENGINE_H

#include <string>
#include <vector>

#include "Vector3f.h"
#include "MappedValues.h"


class BaseLight;
class Camera;
class GameObject;

class RenderingEngine : public MappedValues{
public:
    RenderingEngine();

    void render(GameObject& object);

    void clearScreen();

    static std::string getOpenGLVersion();

    Camera *getMainCamera() const;

    BaseLight *getActiveLight() const;

    void addLight(BaseLight* light);

    void addCamera(Camera* camera);

    unsigned int getSamplerSlot(const std::string& samplerName);
private:
    std::vector<BaseLight*> lights;
    BaseLight* activeLight;
    Camera* mainCamera;
    std::vector<unsigned int> samplers;
};


#endif //DORMENGINE_RENDERINGENGINE_H
