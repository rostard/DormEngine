//
// Created by rostard on 24.12.17.
//

#ifndef DORMENGINE_BASELIGHT_H
#define DORMENGINE_BASELIGHT_H


#include "Vector3f.h"

class BaseLight {
public:
    BaseLight(const Vector3f &color, float intensity);

    const Vector3f &getColor() const;

    void setColor(const Vector3f &color);

    float getIntensity() const;

    void setIntensity(float intensity);

private:
    Vector3f color;
    float intensity;
};


#endif //DORMENGINE_BASELIGHT_H
