//
// Created by rostard on 24.12.17.
//

#ifndef DORMENGINE_POINTLIGHT_H
#define DORMENGINE_POINTLIGHT_H


#include "BaseLight.h"


class PointLight: public BaseLight {
public:
    PointLight(const Vector3f &color = Vector3f(0.0f, 1.0f, 0.0f), float intensity = 1.0f,
               const Vector3f &attenuation = Vector3f(1, 0.09, 0.032));


    float getRange() const;

    void setRange(float range);

    float getConstant() const;

    void setConstant(float constant);

    float getLinear() const;

    void setLinear(float linear);

    float getQuadratic() const;

    void setQuadratic(float quadratic);

private:
    float range;
    float constant;
    float linear;
    float quadratic;

    static const int COLOR_DEPTH = 256;
};


#endif //DORMENGINE_POINTLIGHT_H
