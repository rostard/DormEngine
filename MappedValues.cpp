//
// Created by rostard on 29.12.17.
//

#include "MappedValues.h"
#include "utility/SID.h"

void MappedValues::addVector3f(const std::string &name, Vector3f &vector) {
    vectors[SID(name)] = vector;
}

Vector3f MappedValues::getVector3f(const std::string &name) const {
    if(vectors.find(SID(name)) != vectors.end()){
        return vectors.at(SID(name));
    }
    else Vector3f(0, 0, 0);
}

void MappedValues::addFloat(const std::string &name, float value) {
    floats[SID(name)] = value;
}

float MappedValues::getFloat(const std::string &name) const {
    if(floats.find(SID(name)) != floats.end()){
        return floats.at(SID(name));
    }
    else 0.0f;
}
