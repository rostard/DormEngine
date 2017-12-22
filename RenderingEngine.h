//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_RENDERINGENGINE_H
#define DORMENGINE_RENDERINGENGINE_H

#include <string>
#include "Camera.h"
#include "Shader.h"
#include "GameObject.h"
class Shader;
class GameObject;

class RenderingEngine {
public:
    RenderingEngine();

    void render(GameObject& object, Shader& shader);

    void clearScreen();

    static std::string getOpenGLVersion();

    Camera *getMainCamera() const;

    void setMainCamera(Camera *mainCamera);

private:
    Camera* mainCamera;
};


#endif //DORMENGINE_RENDERINGENGINE_H
