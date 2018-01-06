//
// Created by rostard on 18.12.17.
//

#include "Material.h"

#include "resource_management/ResourceManager.h"

Material::Material() {
    textures[SID("none")] = ResourceManager::loadTexture("none", "none.png");
    textures[SID("normalMap")] = ResourceManager::loadTexture("default_normal", "default_normal.jpg");
    textures[SID("dispMap")] = ResourceManager::loadTexture("default_disp", "default_disp.png");
}

void Material::addTexture(const std::string &name, Texture *texture) {
    textures[SID(name)] = texture;
}

Texture *Material::getTexture(const std::string &name) const {
    if(textures.find(SID(name)) != textures.end()){
        return textures.at(SID(name));
    }
    else return textures.at(SID("none"));
}
