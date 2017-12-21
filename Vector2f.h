//
// Created by rostard on 20.12.17.
//

#ifndef DORMENGINE_VECTOR2F_H
#define DORMENGINE_VECTOR2F_H


#include <cmath>

class Vector2f {
public:
    Vector2f();
    Vector2f(float x, float y);

    float length();

    Vector2f normalized();

    float dot(const Vector2f& r);

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    Vector2f rotate(const float angle);

    Vector2f operator+(const Vector2f& r);
    Vector2f operator+(float val);

    Vector2f operator-(const Vector2f& r);
    Vector2f operator-(float val);

    Vector2f operator*(float val);
    Vector2f operator/(float val);


private:
    float x;
    float y;
};


#endif //DORMENGINE_VECTOR2F_H
