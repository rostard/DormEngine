//
// Created by rostard on 17.12.17.
//

#include <glad/glad.h>

#include "ShaderLoader.h"



Shader ShaderLoader::Load(const std::string &vsFilename, const std::string &fsFilename, const std::string &gsFilename) {

    Shader shader;

    std::string vsSource = ReadFile(vsFilename);
    shader.addVertexShader(vsSource);

    std::string fsSource = ReadFile(fsFilename);
    shader.addFragmentShader(fsSource);

    if(gsFilename != ""){
        std::string gsSource = ReadFile(gsFilename);
        shader.addGeometryShader(gsSource);
    }

    shader.linkProgram();

    return shader;
}

std::string ShaderLoader::ReadFile(const std::string &filename) {
    std::stringstream shaderStream;
    std::ifstream file;

    file.open("res/shaders/" + filename);

    if(!file.is_open()){
        Log::log("error loading file " + filename);
        exit(1);
    }

    shaderStream<<file.rdbuf();
    file.close();

    return shaderStream.str();

}
