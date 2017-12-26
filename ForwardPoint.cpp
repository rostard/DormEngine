//
// Created by rostard on 24.12.17.
//

#include "ForwardPoint.h"
#include "components/PointLight.h"

void ForwardPoint::updateUniforms(Transform &transform, const Material &material, RenderingEngine* renderingEngine) {
    setMat4("model", transform.getTransformation());
    setMat4("MVP", transform.getProjectedTransformation(*renderingEngine->getMainCamera()));
    setVec3("viewPos", renderingEngine->getMainCamera()->getTransform().getTransformedPos());
    setFloat("specularIntensity", 0.5f);
    setFloat("shininess", 64.0);

    PointLight* pointLight = (PointLight*)renderingEngine->getActiveLight();
    setVec3("pointLight.base.color", pointLight->getColor());
    setFloat("pointLight.base.intensity", pointLight->getIntensity());
    setVec3("pointLight.position", pointLight->getTransform().getTransformedPos());
    setFloat("pointLight.range", pointLight->getRange());
    setFloat("pointLight.attenuation.constant", pointLight->getConstant());
    setFloat("pointLight.attenuation.linear", pointLight->getLinear());
    setFloat("pointLight.attenuation.quadratic", pointLight->getQuadratic());
    setFloat("pointLight.range", pointLight->getRange());
}
