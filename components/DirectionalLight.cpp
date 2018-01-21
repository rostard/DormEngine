//
// Created by rostard on 24.12.17.
//

#include "DirectionalLight.h"
#include "../resource_management/ResourceManager.h"

const Vector3f DirectionalLight::getDirection() const {
    return getTransform().getTransformedRot().getForward();
}


DirectionalLight::DirectionalLight(const Vector3f &color, float intensity): BaseLight(color, intensity) {
    setShader(ResourceManager::loadShader("forward-directional_shader", "forward-directional.vs.glsl", "forward-directional.fs.glsl"));
    setShadowInfo(new ShadowInfo(Matrix4f().initOrtographic(-40, 40, -40, 40, -40, 40)));
}
