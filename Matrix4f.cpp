//
// Created by rostard on 18.12.17.
//

#include "Matrix4f.h"

Matrix4f Matrix4f::initIdentity() {
    m[0][0] = 1; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
    m[1][0] = 0; m[1][1] = 1; m[1][2] = 0; m[1][3] = 0;
    m[2][0] = 0; m[2][1] = 0; m[2][2] = 1; m[2][3] = 0;
    m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
    return *this;
}

Matrix4f Matrix4f::initTranslation(float x, float y, float z) {
    m[0][0] = 1; m[0][1] = 0; m[0][2] = 0; m[0][3] = x;
    m[1][0] = 0; m[1][1] = 1; m[1][2] = 0; m[1][3] = y;
    m[2][0] = 0; m[2][1] = 0; m[2][2] = 1; m[2][3] = z;
    m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
    return *this;
}

Matrix4f Matrix4f::initRotation(float x, float y, float z) {
    x =  x * ((float)M_PI /180.0f);
    y =  y * ((float)M_PI /180.0f);
    z =  z * ((float)M_PI /180.0f);

    Matrix4f rx;
    Matrix4f ry;
    Matrix4f rz;

    rx.m[0][0] = 1;             rx.m[0][1] = 0;                 rx.m[0][2] = 0;             rx.m[0][3] = 0;
    rx.m[1][0] = 0;             rx.m[1][1] = (float)cos(x);     rx.m[1][2] = -(float)sin(x);rx.m[1][3] = 0;
    rx.m[2][0] = 0;             rx.m[2][1] = (float)sin(x);     rx.m[2][2] = (float)cos(x); rx.m[2][3] = 0;
    rx.m[3][0] = 0;             rx.m[3][1] = 0;                 rx.m[3][2] = 0;             rx.m[3][3] = 1;

    ry.m[0][0] = (float)cos(y); ry.m[0][1] = 0;                 ry.m[0][2] = -(float)sin(y);ry.m[0][3] = 0;
    ry.m[1][0] = 0;             ry.m[1][1] = 1;                 ry.m[1][2] = 0;             ry.m[1][3] = 0;
    ry.m[2][0] = (float)sin(y); ry.m[2][1] = 0;                 ry.m[2][2] = (float)cos(y); ry.m[2][3] = 0;
    ry.m[3][0] = 0;             ry.m[3][1] = 0;                 ry.m[3][2] = 0;             ry.m[3][3] = 1;

    rz.m[0][0] = (float)cos(z); rz.m[0][1] = -(float)sin(z);    rz.m[0][2] = 0;             rz.m[0][3] = 0;
    rz.m[1][0] = (float)sin(z); rz.m[1][1] = (float)cos(z);     rz.m[1][2] = 0;             rz.m[1][3] = 0;
    rz.m[2][0] = 0;             rz.m[2][1] = 0;                 rz.m[2][2] = 1;             rz.m[2][3] = 0;
    rz.m[3][0] = 0;             rz.m[3][1] = 0;                 rz.m[3][2] = 0;             rz.m[3][3] = 1;

    memcpy((void*)m, ((void*)(rz * ry * rx).m),  16*sizeof(float));
    return *this;
}

Matrix4f Matrix4f::initScale(float x, float y, float z) {
    m[0][0] = x; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
    m[1][0] = 0; m[1][1] = y; m[1][2] = 0; m[1][3] = 0;
    m[2][0] = 0; m[2][1] = 0; m[2][2] = z; m[2][3] = 0;
    m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
    return *this;
}

Matrix4f Matrix4f::initPerspective(float fov, float aspectRatio, float zNear, float zFar) {
    float tanHalfFOV = (float)tan(fov/2.0f);
    float zRange = zNear - zFar;

    m[0][0] = 1.0f / (tanHalfFOV * aspectRatio);m[0][1] = 0;                    m[0][2] = 0;                        m[0][3] = 0;
    m[1][0] = 0;                                m[1][1] = 1.0f / tanHalfFOV;    m[1][2] = 0;                        m[1][3] = 0;
    m[2][0] = 0;                                m[2][1] = 0;                    m[2][2] = (-zNear - zFar) / zRange; m[2][3] = 2 * zFar * zNear / zRange;
    m[3][0] = 0;                                m[3][1] = 0;                    m[3][2] = 1;                        m[3][3] = 0;
    return *this;
}

Matrix4f Matrix4f::initRotation(const Vector3f &forward, const Vector3f &up) {
    Vector3f f = forward.normalized();
    Vector3f r = up.normalized().cross(f).normalized();
    Vector3f u = f.cross(r).normalized();

    m[0][0] = r.getX(); m[0][1] = r.getY(); m[0][2] = r.getZ(); m[0][3] = 0;
    m[1][0] = u.getX(); m[1][1] = u.getY(); m[1][2] = u.getZ(); m[1][3] = 0;
    m[2][0] = f.getX(); m[2][1] = f.getY(); m[2][2] = f.getZ(); m[2][3] = 0;
    m[3][0] = 0;        m[3][1] = 0;        m[3][2] = 0;        m[3][3] = 1;

    return *this;
}

Matrix4f Matrix4f::operator*(const Matrix4f &m2) const{
    Matrix4f ret;
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            ret.set(i, j, m[i][0] * m2.get(0, j) +
                          m[i][1] * m2.get(1, j) +
                          m[i][2] * m2.get(2, j) +
                          m[i][3] * m2.get(3, j));
        }
    }
    return ret;
}

float Matrix4f::get(int i, int j) const {
    return m[i][j];
}

void Matrix4f::set(int i, int j, float val) {
    m[i][j] = val;
}

float *Matrix4f::getM() const {
    return (float*)m;
}
