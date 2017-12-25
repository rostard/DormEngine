//
// Created by rostard on 24.12.17.
//

#include "ForwardPoint.h"
#include "components/PointLight.h"

void ForwardPoint::updateUniforms(const Transform &transform, const Material &material) {
    setMat4("model", transform.getTransformation());
    setMat4("MVP", transform.getProjectedTransformation(*getRenderingEngine()->getMainCamera()));
    setVec3("viewPos", getRenderingEngine()->getMainCamera()->getPos());
    setFloat("specularIntensity", 0.5f);
    setFloat("shininess", 64.0);

    PointLight* pointLight = (PointLight*)getRenderingEngine()->getActiveLight();
    setVec3("pointLight.base.color", pointLight->getColor());
    setFloat("pointLight.base.intensity", pointLight->getIntensity());
    setVec3("pointLight.position", pointLight->getTransform().getTranslation());
    setFloat("pointLight.range", pointLight->getRange());
    setFloat("pointLight.attenuation.constant", pointLight->getConstant());
    setFloat("pointLight.attenuation.linear", pointLight->getLinear());
    setFloat("pointLight.attenuation.quadratic", pointLight->getQuadratic());
    setFloat("pointLight.range", pointLight->getRange());
}
