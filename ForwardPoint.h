//
// Created by rostard on 24.12.17.
//

#ifndef DORMENGINE_FORWARDPOINT_H
#define DORMENGINE_FORWARDPOINT_H


#include "Shader.h"

class ForwardPoint : public Shader{
public:
    ForwardPoint(const Shader& shader){
        setProgram(shader.getProgram());
    }

    void updateUniforms(Transform &transform, const Material &material, RenderingEngine* renderingEngine) override;
};


#endif //DORMENGINE_FORWARDPOINT_H
