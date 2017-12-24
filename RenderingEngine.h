//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_RENDERINGENGINE_H
#define DORMENGINE_RENDERINGENGINE_H

#include <string>
#include "Camera.h"
#include "Shader.h"
#include "GameObject.h"
#include "DirectionalLight.h"

class Shader;
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

    const DirectionalLight &getDirectionalLight() const;

private:
    Vector3f ambientLight;
    DirectionalLight directionalLight;
    Camera* mainCamera;
};


#endif //DORMENGINE_RENDERINGENGINE_H
