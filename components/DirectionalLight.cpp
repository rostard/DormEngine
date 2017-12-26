//
// Created by rostard on 24.12.17.
//

#include "DirectionalLight.h"
#include "../resource_management/ResourceManager.h"
#include "../ForwardDirectional.h"

const Vector3f DirectionalLight::getDirection() const {
    return getTransform().getTransformedRot().getForward();
}


DirectionalLight::DirectionalLight(const Vector3f &color, float intensity): BaseLight(color, intensity) {
    setShader(new ForwardDirectional(*ResourceManager::loadShader("forward-directional_shader", "forward-directional.vs.glsl", "forward-directional.fs.glsl")));
}
