//
// Created by rostard on 25.12.17.
//

#include "ForwardSpot.h"
#include "components/SpotLight.h"

void ForwardSpot::updateUniforms(Transform &transform, const Material &material, RenderingEngine* renderingEngine) {
    setMat4("model", transform.getTransformation());
    setMat4("MVP", transform.getProjectedTransformation(*renderingEngine->getMainCamera()));
    setVec3("viewPos", renderingEngine->getMainCamera()->getTransform().getTransformedPos());
    setFloat("specularIntensity", 0.5f);
    setFloat("shininess", 64.0);

    SpotLight* spotLight = (SpotLight*)renderingEngine->getActiveLight();
    setVec3("spotLight.base.base.color", spotLight->getColor());
    setFloat("spotLight.base.base.intensity", spotLight->getIntensity());
    setVec3("spotLight.base.position", spotLight->getTransform().getTransformedPos());
    setFloat("spotLight.base.range", spotLight->getRange());
    setFloat("spotLight.base.attenuation.constant", spotLight->getConstant());
    setFloat("spotLight.base.attenuation.linear", spotLight->getLinear());
    setFloat("spotLight.base.attenuation.quadratic", spotLight->getQuadratic());
    setFloat("spotLight.cutOff", spotLight->getCutoff());
    setVec3("spotLight.direction", spotLight->getDirection());
}