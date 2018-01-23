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

