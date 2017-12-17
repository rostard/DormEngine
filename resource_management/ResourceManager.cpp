//
// Created by rostard on 17.12.17.
//

#include "ResourceManager.h"
#include "../utility/SID.h"
#include "ShaderLoader.h"

std::map<unsigned int, Shader> ResourceManager::shaders = std::map<unsigned int, Shader>();



Shader *ResourceManager::getShader(const std::string &name) {
    unsigned int id = SID(name);
    return &shaders.at(id);
}

Shader *
ResourceManager::loadShader(const std::string &name, const std::string &vsFilename, const std::string &fsFilename,
                            const std::string &gsFilename) {
    unsigned int id = SID(name);
    if(shaders.find(id) != shaders.end()){
        return getShader(name);
    }
    shaders[id] = ShaderLoader::Load(vsFilename, fsFilename, gsFilename);
    return &shaders[id];
}
