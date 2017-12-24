//
// Created by rostard on 24.12.17.
//

#include "ForwardDirectional.h"

void ForwardDirectional::updateUniforms(const Transform &transform, const Material &material) {
    this->setMat4("model", transform.getTransformation());
    this->setMat4("MVP", transform.getProjectedTransformation(*getRenderingEngine()->getMainCamera()));
    this->setVec3("viewPos", getRenderingEngine()->getMainCamera()->getPos());
    this->setFloat("specularIntensity", 0.1);
    this->setFloat("specularPower", 1.0);

    this->setVec3("dirLight.base.color", getRenderingEngine()->getDirectionalLight().getColor());
    this->setFloat("dirLight.base.intensity", getRenderingEngine()->getDirectionalLight().getIntensity());
    this->setVec3("dirLight.direction", getRenderingEngine()->getDirectionalLight().getDirection());
}
