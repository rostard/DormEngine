//
// Created by rostard on 24.12.17.
//

#include "DirectionalLight.h"
#include "../resource_management/ResourceManager.h"
#include "../ForwardDirectional.h"

const Vector3f &DirectionalLight::getDirection() const {
    return direction;
}

void DirectionalLight::setDirection(const Vector3f &direction) {
    DirectionalLight::direction = direction;
}

DirectionalLight::DirectionalLight(const Vector3f &color, float intensity, const Vector3f &direction): BaseLight(color, intensity), direction(direction) {
    setShader(new ForwardDirectional(*ResourceManager::loadShader("forward-directional_shader", "forward-directional.vs.glsl", "forward-directional.fs.glsl")));
}
