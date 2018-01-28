//
// Created by rostard on 24.12.17.
//

#ifndef DORMENGINE_BASELIGHT_H
#define DORMENGINE_BASELIGHT_H


#include "GameComponent.h"
#include "../math/Vector3f.h"
#include "../Shader.h"

class ShadowInfo{
public:
    ShadowInfo(const Matrix4f &projection, bool flipFaces, int shadowMapResolutionAsPowerOf2 = 10, float shadowSoftness = 1.0f, float lightBleedReductionAmount = 0.2f, float minVariance = 0.00002f);

    const Matrix4f &getProjection() const;

    bool getFlipFaces() const;

    float getShadowSoftness() const;

    float getMinVariance() const;

    float getLightBleedReductionAmount() const;

    int getResolutionAsPowerOf2() const;

    void setResolutionAsPowerOf2(int resolutionAsPowerOf2);

private:
    Matrix4f projection;

    int resolutionAsPowerOf2;

    bool flipFaces;
    float shadowSoftness;
    float minVariance;
    float lightBleedReductionAmount;
};

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

    ShadowInfo *getShadowInfo() const;

    void setShadowInfo(ShadowInfo *shadowInfo);


private:
    Shader* shader;
    Vector3f color;
    float intensity;
    ShadowInfo* shadowInfo;
};


#endif //DORMENGINE_BASELIGHT_H
