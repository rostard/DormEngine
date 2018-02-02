//
// Created by rostard on 24.12.17.
//

#include "BaseLight.h"
#include "../CoreEngine.h"


ShadowInfo::ShadowInfo(const Matrix4f &projection, bool flipFaces, int shadowMapResolutionAsPowerOf2,
                       float shadowSoftness, float lightBleedReductionAmount, float minVariance) :
        projection(projection), flipFaces(flipFaces), resolutionAsPowerOf2(shadowMapResolutionAsPowerOf2),
        shadowSoftness(shadowSoftness), minVariance(minVariance),
        lightBleedReductionAmount(lightBleedReductionAmount) {}


const Matrix4f &ShadowInfo::getProjection() const {
    return projection;
}


bool ShadowInfo::getFlipFaces() const {
    return flipFaces;
}

float ShadowInfo::getShadowSoftness() const {
    return shadowSoftness;
}

float ShadowInfo::getMinVariance() const {
    return minVariance;
}

float ShadowInfo::getLightBleedReductionAmount() const {
    return lightBleedReductionAmount;
}

int ShadowInfo::getResolutionAsPowerOf2() const {
    return resolutionAsPowerOf2;
}

void ShadowInfo::setResolutionAsPowerOf2(int resolutionAsPowerOf2) {
    ShadowInfo::resolutionAsPowerOf2 = resolutionAsPowerOf2;
}


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

BaseLight::BaseLight(const Vector3f &color, float intensity) : color(color), intensity(intensity), shadowInfo(nullptr) {
    //shader = ResourceManager::loadShader()
}

ShadowCameraTransform BaseLight::calcShadowCameraTransform(const Vector3f& mainCameraPos, const Quaternion& mainCameraRot) {
    ShadowCameraTransform res;
    res.pos = getTransform().getTransformedPos();
    res.rot = getTransform().getTransformedRot();
    return res;
}

void BaseLight::addToEngine(CoreEngine *engine) {
    engine->getRenderingEngine()->addLight(this);
}

Shader *BaseLight::getShader() {
    return shader;
}

void BaseLight::setShader(Shader *shader) {
    BaseLight::shader = shader;
}

ShadowInfo *BaseLight::getShadowInfo() const {
    return shadowInfo;
}

void BaseLight::setShadowInfo(ShadowInfo *shadowInfo) {
    BaseLight::shadowInfo = shadowInfo;
}
