//
// Created by rostard on 24.12.17.
//

#ifndef DORMENGINE_DIRECTIONALLIGHT_H
#define DORMENGINE_DIRECTIONALLIGHT_H


#include "BaseLight.h"

class DirectionalLight : public BaseLight{
public:
    DirectionalLight(const Vector3f &color = Vector3f(1.0f, 1.0f, 1.0f), float intensity = 0.5f);

    const Vector3f getDirection() const;

};


#endif //DORMENGINE_DIRECTIONALLIGHT_H
