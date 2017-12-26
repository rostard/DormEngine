//
// Created by rostard on 24.12.17.
//

#include "ForwardDirectional.h"
#include "components/DirectionalLight.h"


void ForwardDirectional::updateUniforms(Transform &transform, const Material &material, RenderingEngine* renderingEngine) {
    setMat4("model", transform.getTransformation());
    setMat4("MVP", transform.getProjectedTransformation(*renderingEngine->getMainCamera()));
    setVec3("viewPos", renderingEngine->getMainCamera()->getTransform().getTransformedPos());
    setFloat("specularIntensity", 0.5);
    setFloat("shininess", 20.0);

    DirectionalLight* dirLight = (DirectionalLight*)renderingEngine->getActiveLight();
    setVec3("dirLight.base.color", dirLight->getColor());
    setFloat("dirLight.base.intensity", dirLight->getIntensity());
    setVec3("dirLight.direction", dirLight->getDirection());
}
