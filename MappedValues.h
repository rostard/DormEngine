//
// Created by rostard on 29.12.17.
//

#ifndef DORMENGINE_MAPPEDVALUES_H
#define DORMENGINE_MAPPEDVALUES_H


#include "math/Vector3f.h"
#include <map>

class Texture;

class MappedValues {
public:
    void setVector3f(const std::string &name, Vector3f vector);

    Vector3f getVector3f(const std::string& name) const;

    void setFloat(const std::string &name, float value);

    float getFloat(const std::string& name) const;

    void setTexture(const std::string &name, Texture *texture);
    Texture* getTexture(const std::string& name) const;
protected:
    std::map<unsigned int, Vector3f> vectors;
    std::map<unsigned int, float> floats;
    std::map<unsigned int, Texture*> textures;
};


#endif //DORMENGINE_MAPPEDVALUES_H
