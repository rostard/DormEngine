//
// Created by rostard on 17.12.17.
//

#ifndef DORMENGINE_RESOURCEMANAGER_H
#define DORMENGINE_RESOURCEMANAGER_H


#include <map>
#include "../Shader.h"

class ResourceManager {
public:
    static Shader* loadShader(const std::string& name, const std::string& vsFilename, const std::string& fsFilename, const std::string& gsFilename = "");
    static Shader* getShader(const std::string& name);
private:
    static std::map<unsigned int, Shader> shaders;

};


#endif //DORMENGINE_RESOURCEMANAGER_H
