//
// Created by rostard on 18.12.17.
//

#ifndef DORMENGINE_MESHRENDERER_H
#define DORMENGINE_MESHRENDERER_H


#include "../GameComponent.h"
#include "../Mesh.h"
#include "../Material.h"

class MeshRenderer : public GameComponent {
public:
    MeshRenderer(const Mesh &mesh, const Material &material);

    void render(Transform &transform, Shader shader) override;

    void input(Transform &transform, float d_time) override;

    void update(Transform &transform, float d_time) override;

private:
    Mesh mesh;
    Material material;
};


#endif //DORMENGINE_MESHRENDERER_H
