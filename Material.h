//
// Created by rostard on 18.12.17.
//

#ifndef DORMENGINE_MATERIAL_H
#define DORMENGINE_MATERIAL_H


#include <map>
#include "Texture.h"
#include "Vector3f.h"
#include "utility/SID.h"
#include "MappedValues.h"

class Material : public MappedValues{
public:
    Material();
    void addTexture(const std::string& name,Texture* texture);
    Texture* getTexture(const std::string& name) const;

private:
    std::map<unsigned int, Texture*> textures;
};


#endif //DORMENGINE_MATERIAL_H
