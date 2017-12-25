//
// Created by rostard on 24.12.17.
//

#include "ForwardDirectional.h"
#include "components/DirectionalLight.h"


void ForwardDirectional::updateUniforms(const Transform &transform, const Material &material) {
    setMat4("model", transform.getTransformation());
    setMat4("MVP", transform.getProjectedTransformation(*getRenderingEngine()->getMainCamera()));
    setVec3("viewPos", getRenderingEngine()->getMainCamera()->getPos());
    setFloat("specularIntensity", 0.5);
    setFloat("shininess", 20.0);

    DirectionalLight* dirLight = (DirectionalLight*)getRenderingEngine()->getActiveLight();
    setVec3("dirLight.base.color", dirLight->getColor());
    setFloat("dirLight.base.intensity", dirLight->getIntensity());
    setVec3("dirLight.direction", dirLight->getDirection());
}
