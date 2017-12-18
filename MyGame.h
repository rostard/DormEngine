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

    void render() override;

    void update(float d_time) override;

private:
    Shader* shader;
    Mesh* mesh;
    Transform* transform;
    Texture* texture;
};


#endif //DORMENGINE_MYGAME_H
