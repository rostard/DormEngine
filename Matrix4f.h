#ifndef DORMENGINE_MATRIX4F_H
#define DORMENGINE_MATRIX4F_H

#include <math.h>
#include <cstring>

class Vector3f;

class Matrix4f {
public:

    Matrix4f initIdentity();

    Matrix4f initTranslation(float x, float y, float z);

    Matrix4f initRotation(float x, float y, float z);

    Matrix4f initScale(float x, float y, float z);

    Matrix4f initPerspective(float fov, float aspectRatio, float zNear, float zFar);

    Matrix4f initOrtographic(float left, float right, float top, float bottom, float zNear, float zFar);

    Matrix4f initRotation(const Vector3f &forward, const Vector3f &up);

    Matrix4f initRotation(const Vector3f &forward, const Vector3f &up, const Vector3f &right);

    Matrix4f operator*(const Matrix4f& m2) const;

    float get(int i, int j) const;

    void set(int i, int j, float val);

    float* getM() const;
private:
    float m[4][4];
};


#endif //DORMENGINE_MATRIX4F_H
