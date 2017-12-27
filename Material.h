//
// Created by rostard on 18.12.17.
//

#ifndef DORMENGINE_MATERIAL_H
#define DORMENGINE_MATERIAL_H


#include <map>
#include "Texture.h"
#include "Vector3f.h"
#include "utility/SID.h"

class Material {
public:
    Material();
    void addTexture(const std::string& name,Texture* texture){
        textures[SID(name)] = texture;
    }
    Texture* getTexture(const std::string& name){
        if(textures.find(SID(name)) != textures.end()){
            return textures[SID(name)];
        }
        else return textures[SID("none")];
    }

    void addVector3f(const std::string& name, Vector3f& vector){
        vectors[SID(name)] = vector;
    }

    Vector3f& getVector3f(const std::string& name){
        if(vectors.find(SID(name)) != vectors.end()){
            return vectors[SID(name)];
        }
        else Vector3f(0, 0, 0);
    }

    void addFloat(const std::string& name, float value){
        floats[SID(name)] = value;
    }

    float getFloat(const std::string& name){
        if(floats.find(SID(name)) != floats.end()){
            return floats[SID(name)];
        }
        else 0.0f;
    }

private:
    std::map<unsigned int, Texture*> textures;
    std::map<unsigned int, Vector3f> vectors;
    std::map<unsigned int, float> floats;
};


#endif //DORMENGINE_MATERIAL_H
