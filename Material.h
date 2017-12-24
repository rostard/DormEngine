//
// Created by rostard on 18.12.17.
//

#ifndef DORMENGINE_MATERIAL_H
#define DORMENGINE_MATERIAL_H


#include <map>
#include "Texture.h"
#include "Vector3f.h"

class Material {
public:
    const Vector3f &getColor() const;

    void setColor(const Vector3f &color);

private:
    std::map<std::string, Texture*> textures;
    Vector3f color;
};


#endif //DORMENGINE_MATERIAL_H
