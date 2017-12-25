//
// Created by rostard on 25.12.17.
//

#include "ForwardSpot.h"
#include "components/SpotLight.h"

void ForwardSpot::updateUniforms(const Transform &transform, const Material &material) {
    setMat4("model", transform.getTransformation());
    setMat4("MVP", transform.getProjectedTransformation(*getRenderingEngine()->getMainCamera()));
    setVec3("viewPos", getRenderingEngine()->getMainCamera()->getPos());
    setFloat("specularIntensity", 0.5f);
    setFloat("shininess", 64.0);

    SpotLight* spotLight = (SpotLight*)getRenderingEngine()->getActiveLight();
    setVec3("spotLight.base.color", spotLight->getColor());
    setFloat("spotLight.base.intensity", spotLight->getIntensity());
    setVec3("spotLight.position", spotLight->getTransform().getTranslation());
    setFloat("spotLight.range", spotLight->getRange());
    setFloat("spotLight.attenuation.constant", spotLight->getConstant());
    setFloat("spotLight.attenuation.linear", spotLight->getLinear());
    setFloat("spotLight.attenuation.quadratic", spotLight->getQuadratic());
    setFloat("spotLight.cutOff", spotLight->getCutoff());
    setVec3("spotLight.direction", spotLight->getDirection());
}