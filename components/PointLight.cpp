//
// Created by rostard on 24.12.17.
//

#include <iostream>
#include "PointLight.h"
#include "../resource_management/ResourceManager.h"
#include "../GameObject.h"
#include "../utility/Log.h"

PointLight::PointLight(const Vector3f &color, float intensity, const Vector3f &attenuation) :
        BaseLight(color, intensity),
        constant(attenuation.getX()), linear(attenuation.getY()),
        quadratic(attenuation.getZ()){

    float a = attenuation.getZ();
    float b = attenuation.getY();
    float c = attenuation.getX() - intensity * color.max() * COLOR_DEPTH;

    range = (-b + std::sqrt(b * b - 4 * a * c)) / (2 * a);

    setShader(ResourceManager::loadShader("forward-point_shader", "forward-point.vs.glsl", "forward-point.fs.glsl"));
}



float PointLight::getRange() const {
    return range;
}

void PointLight::setRange(float range) {
    PointLight::range = range;
}

float PointLight::getConstant() const {
    return constant;
}

void PointLight::setConstant(float constant) {
    PointLight::constant = constant;
}

float PointLight::getLinear() const {
    return linear;
}

void PointLight::setLinear(float linear) {
    PointLight::linear = linear;
}

float PointLight::getQuadratic() const {
    return quadratic;
}

void PointLight::setQuadratic(float quadratic) {
    PointLight::quadratic = quadratic;
}
