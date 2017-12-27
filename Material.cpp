//
// Created by rostard on 18.12.17.
//

#include "Material.h"

#include "resource_management/ResourceManager.h"

Material::Material() {
    textures[SID("none")] = ResourceManager::loadTexture("none", "none.png");
}
