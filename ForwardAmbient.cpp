//
// Created by rostard on 24.12.17.
//

#include "ForwardAmbient.h"

void ForwardAmbient::updateUniforms(Transform &transform, const Material &material, RenderingEngine* renderingEngine) {
    this->setMat4("MVP", transform.getProjectedTransformation(*renderingEngine->getMainCamera()));
    this->setVec3("ambientIntensity", renderingEngine->getAmbientLight());
}
