//
// Created by rostard on 24.12.17.
//

#ifndef DORMENGINE_FORWARDAMBIENT_H
#define DORMENGINE_FORWARDAMBIENT_H


#include "Shader.h"

class ForwardAmbient : public Shader{
public:
    ForwardAmbient(const Shader& shader){
        setProgram(shader.getProgram());
    }
    void updateUniforms(Transform &transform, const Material &material, RenderingEngine* renderingEngine) override;
};


#endif //DORMENGINE_FORWARDAMBIENT_H
