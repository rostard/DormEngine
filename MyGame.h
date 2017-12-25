//
// Created by rostard on 18.12.17.
//

#ifndef DORMENGINE_MYGAME_H
#define DORMENGINE_MYGAME_H


#include "Game.h"
#include "Shader.h"
#include "Mesh.h"
#include "Transform.h"
#include "Texture.h"

class MyGame : public Game{
public:
    void init() override;

    void update(float d_time) override;

    void input(float d_time) override;

private:
    GameObject* pointLightObject;
    GameObject* spotLightObject;
    Shader* shader;
    Mesh* mesh;
    Texture* texture;
    GameObject* plane;
};


#endif //DORMENGINE_MYGAME_H
