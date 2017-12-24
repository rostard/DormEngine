//
// Created by rostard on 24.12.17.
//

#include "DirectionalLight.h"

const Vector3f &DirectionalLight::getDirection() const {
    return direction;
}

void DirectionalLight::setDirection(const Vector3f &direction) {
    DirectionalLight::direction = direction;
}

DirectionalLight::DirectionalLight(const Vector3f &color, float intensity, const Vector3f &direction): BaseLight(color, intensity), direction(direction) {

}
