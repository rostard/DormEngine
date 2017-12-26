//
// Created by rostard on 25.12.17.
//

#ifndef DORMENGINE_FORWARDSPOT_H
#define DORMENGINE_FORWARDSPOT_H


#include "Shader.h"

class ForwardSpot : public Shader {
public:
    ForwardSpot(const Shader& shader){
        setRenderingEngine(shader.getRenderingEngine());
        setProgram(shader.getProgram());
    }

    void updateUniforms(Transform &transform, const Material &material) override;
};


#endif //DORMENGINE_FORWARDSPOT_H
