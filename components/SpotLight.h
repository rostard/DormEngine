//
// Created by rostard on 25.12.17.
//

#ifndef DORMENGINE_SPOTLIGHT_H
#define DORMENGINE_SPOTLIGHT_H


#include "PointLight.h"

class SpotLight : public PointLight {

public:
    SpotLight(const Vector3f& color, float intensity, const Vector3f& attenuation, float cutoff);

    float getCutoff() const;

    void setCutoff(float cutoff);

    const Vector3f getDirection() const;

private:
    float cutoff;
};


#endif //DORMENGINE_SPOTLIGHT_H
