//
// Created by rostard on 18.12.17.
//

#ifndef DORMENGINE_MATERIAL_H
#define DORMENGINE_MATERIAL_H


#include <map>
#include "Texture.h"

class Material {

private:
    std::map<std::string, Texture*> textures;
};


#endif //DORMENGINE_MATERIAL_H
