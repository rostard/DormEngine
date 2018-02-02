#include "DirectionalLight.h"
#include "../resource_management/ResourceManager.h"

const Vector3f DirectionalLight::getDirection() const {
    return getTransform().getTransformedRot().getForward();
}

DirectionalLight::DirectionalLight(const Vector3f &color, float intensity, int shadowMapResolutionAsPowerOf2,
                                   float shadowSpace, float shadowSoftness, float lightBleedReductionAmount,
                                   float minVariance): BaseLight(color, intensity) {
    halfShadowSpace = shadowSpace / 2.0f;
    setShader(ResourceManager::loadShader("forward-directional_shader", "forward-directional.vs.glsl", "forward-directional.fs.glsl"));

    if(shadowMapResolutionAsPowerOf2 != 0){

        setShadowInfo(new ShadowInfo(Matrix4f().initOrtographic(-halfShadowSpace, halfShadowSpace, -halfShadowSpace, halfShadowSpace, -halfShadowSpace, halfShadowSpace), false, shadowMapResolutionAsPowerOf2, shadowSoftness, lightBleedReductionAmount, minVariance));
    }

}

ShadowCameraTransform
DirectionalLight::calcShadowCameraTransform(const Vector3f &mainCameraPos, const Quaternion &mainCameraRot) {
    ShadowCameraTransform res;
    res.pos = mainCameraPos + mainCameraRot.getForward() * halfShadowSpace;
    res.rot = getTransform().getTransformedRot();
    return res;
}
