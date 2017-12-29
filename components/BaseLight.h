//
// Created by rostard on 24.12.17.
//

#ifndef DORMENGINE_BASELIGHT_H
#define DORMENGINE_BASELIGHT_H


#include "GameComponent.h"
#include "../math/Vector3f.h"
#include "../Shader.h"

class BaseLight : public GameComponent {
public:
    BaseLight(const Vector3f &color, float intensity);

    const Vector3f &getColor() const;

    void setColor(const Vector3f &color);

    float getIntensity() const;

    void setIntensity(float intensity);

    void addToEngine(CoreEngine *engine);

    Shader* getShader();

    void setShader(Shader *shader);

private:
    Shader* shader;
    Vector3f color;
    float intensity;
};


#endif //DORMENGINE_BASELIGHT_H
