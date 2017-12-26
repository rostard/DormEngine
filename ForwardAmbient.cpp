//
// Created by rostard on 24.12.17.
//

#include "ForwardAmbient.h"

void ForwardAmbient::updateUniforms(Transform &transform, const Material &material) {
    this->setMat4("MVP", transform.getProjectedTransformation(*getRenderingEngine()->getMainCamera()));
    this->setVec3("ambientIntensity", getRenderingEngine()->getAmbientLight());
}
