//
// Created by rostard on 29.12.17.
//

#ifndef DORMENGINE_MAPPEDVALUES_H
#define DORMENGINE_MAPPEDVALUES_H


#include "Vector3f.h"
#include <map>

class MappedValues {
public:
    void addVector3f(const std::string& name, Vector3f& vector);

    Vector3f getVector3f(const std::string& name) const;

    void addFloat(const std::string& name, float value);

    float getFloat(const std::string& name) const;

protected:
    std::map<unsigned int, Vector3f> vectors;
    std::map<unsigned int, float> floats;
};


#endif //DORMENGINE_MAPPEDVALUES_H
