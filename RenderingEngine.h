//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_RENDERINGENGINE_H
#define DORMENGINE_RENDERINGENGINE_H

#include <string>
#include <vector>

#include "Vector3f.h"


class BaseLight;
class Camera;
class GameObject;

class RenderingEngine {
public:
    RenderingEngine();

    void render(GameObject& object);

    void clearScreen();

    static std::string getOpenGLVersion();

    Camera *getMainCamera() const;

    void setMainCamera(Camera *mainCamera);

    Vector3f getAmbientLight();

    BaseLight *getActiveLight() const;

    void addLight(BaseLight* light);

    void addCamera(Camera* camera);
private:
    std::vector<BaseLight*> lights;
    Vector3f ambientLight;
    BaseLight* activeLight;
    Camera* mainCamera;
};


#endif //DORMENGINE_RENDERINGENGINE_H
