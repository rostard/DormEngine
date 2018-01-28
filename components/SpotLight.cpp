//
// Created by rostard on 25.12.17.
//

#include "SpotLight.h"
#include "../resource_management/ResourceManager.h"


SpotLight::SpotLight(const Vector3f &color, float intensity, const Vector3f &attenuation, float cutoff,
                     float outerCutoff, int shadowMapResolutionAsPowerOf2, float shadowSoftness,
                     float lightBleedReductionAmount, float minVariance) : PointLight(color, intensity, attenuation),
                        cutoff(cosf(cutoff / 2.0f)), outerCutoff(cosf(outerCutoff / 2.0f)){
    setShader(ResourceManager::loadShader("forward-spot_shader", "forward-spot.vs.glsl", "forward-spot.fs.glsl"));

    if(shadowMapResolutionAsPowerOf2 != 0){
        setShadowInfo(new ShadowInfo(Matrix4f().initPerspective(outerCutoff, 1, 0.1, this->getRange()), false, shadowMapResolutionAsPowerOf2,
        shadowSoftness, lightBleedReductionAmount, minVariance));
    }
}

float SpotLight::getCutoff() const {
    return cutoff;
}

void SpotLight::setCutoff(float cutoff) {
    SpotLight::cutoff = cutoff;
}

const Vector3f SpotLight::getDirection() const {
    return getTransform().getTransformedRot().getForward();
}

float SpotLight::getOuterCutoff() const {
    return outerCutoff;
}

void SpotLight::setOuterCutoff(float outerCutoff) {
    SpotLight::outerCutoff = outerCutoff;
}

