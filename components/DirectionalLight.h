//
// Created by rostard on 24.12.17.
//

#ifndef DORMENGINE_DIRECTIONALLIGHT_H
#define DORMENGINE_DIRECTIONALLIGHT_H


#include "BaseLight.h"

class DirectionalLight : public BaseLight{
public:
    DirectionalLight(const Vector3f &color = Vector3f(1.0f, 1.0f, 1.0f), float intensity = 0.5f, int shadowMapResolutionAsPowerOf2 = 0, float shadowSpace = 40.0f, float shadowSoftness = 1.0f, float lightBleedReductionAmount = 0.2f, float minVariance = 0.0002f);

    ShadowCameraTransform
    calcShadowCameraTransform(const Vector3f &mainCameraPos, const Quaternion &mainCameraRot) override;

    const Vector3f getDirection() const;

private:
    float halfShadowSpace;
};


#endif //DORMENGINE_DIRECTIONALLIGHT_H
