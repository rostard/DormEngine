//
// Created by rostard on 24.12.17.
//

#include "BaseLight.h"
#include "../resource_management/ResourceManager.h"
#include "../CoreEngine.h"

const Vector3f &BaseLight::getColor() const {
    return color;
}

void BaseLight::setColor(const Vector3f &color) {
    BaseLight::color = color;
}

float BaseLight::getIntensity() const {
    return intensity;
}

void BaseLight::setIntensity(float intensity) {
    BaseLight::intensity = intensity;
}

BaseLight::BaseLight(const Vector3f &color, float intensity) : color(color), intensity(intensity) {
    //shader = ResourceManager::loadShader()
}

void BaseLight::addToEngine(CoreEngine *engine) {
    engine->getRenderingEngine()->addLight(this);
}

Shader* BaseLight::getShader() {
    return shader;
}

void BaseLight::setShader(Shader *shader) {
    BaseLight::shader = shader;
}
