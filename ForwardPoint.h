//
// Created by rostard on 24.12.17.
//

#ifndef DORMENGINE_FORWARDPOINT_H
#define DORMENGINE_FORWARDPOINT_H


#include "Shader.h"

class ForwardPoint : public Shader{
public:
    ForwardPoint(const Shader& shader){
        setRenderingEngine(shader.getRenderingEngine());
        setProgram(shader.getProgram());
    }

    void updateUniforms(Transform &transform, const Material &material) override;
};


#endif //DORMENGINE_FORWARDPOINT_H
