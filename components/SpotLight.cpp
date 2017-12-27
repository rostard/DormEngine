//
// Created by rostard on 25.12.17.
//

#include "SpotLight.h"
#include "../resource_management/ResourceManager.h"
#include "../ForwardSpot.h"

SpotLight::SpotLight(const Vector3f& color, float intensity, const Vector3f& attenuation, float cutoff) : PointLight(color, intensity, attenuation), cutoff(cutoff) {
    setShader(new ForwardSpot(*ResourceManager::loadShader("forward-spot_shader", "forward-spot.vs.glsl", "forward-spot.fs.glsl")));
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