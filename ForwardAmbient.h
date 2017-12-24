//
// Created by rostard on 24.12.17.
//

#ifndef DORMENGINE_FORWARDAMBIENT_H
#define DORMENGINE_FORWARDAMBIENT_H


#include "Shader.h"

class ForwardAmbient : public Shader{
public:
    ForwardAmbient(const Shader& shader){
        setRenderingEngine(shader.getRenderingEngine());
        setProgram(shader.getProgram());
    }
    void updateUniforms(const Transform &transform, const Material &material) override;
};


#endif //DORMENGINE_FORWARDAMBIENT_H
