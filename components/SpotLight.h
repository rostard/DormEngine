//
// Created by rostard on 25.12.17.
//

#ifndef DORMENGINE_SPOTLIGHT_H
#define DORMENGINE_SPOTLIGHT_H


#include "PointLight.h"

class SpotLight : public PointLight {

public:
    SpotLight(const Vector3f& color, float intensity, const Vector3f& attenuation, float cutoff, float outerCutoff, int shadowMapResolutionAsPowerOf2 = 0, float shadowSoftness = 1.0f, float lightBleedReductionAmount = 0.2f, float minVariance = 0.0002f);

    float getCutoff() const;

    void setCutoff(float cutoff);

    const Vector3f getDirection() const;

    float getOuterCutoff() const;

    void setOuterCutoff(float outerCutoff);

private:
    float cutoff;
    float outerCutoff;
};


#endif //DORMENGINE_SPOTLIGHT_H
