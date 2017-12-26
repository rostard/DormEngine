//
// Created by rostard on 24.12.17.
//

#ifndef DORMENGINE_FORWARDDIRECTIONAL_H
#define DORMENGINE_FORWARDDIRECTIONAL_H


#include "Shader.h"

class ForwardDirectional : public Shader{
public:
    ForwardDirectional(const Shader& shader){
        setRenderingEngine(shader.getRenderingEngine());
        setProgram(shader.getProgram());
    }

    void updateUniforms(Transform &transform, const Material &material) override;
};


#endif //DORMENGINE_FORWARDDIRECTIONAL_H
