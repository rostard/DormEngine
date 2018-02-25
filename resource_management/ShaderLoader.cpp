//
// Created by rostard on 17.12.17.
//

#include <algorithm>
#include "ShaderLoader.h"



Shader ShaderLoader::Load(const std::string &vsFilename, const std::string &fsFilename, const std::string &gsFilename) {



    Shader shader;
#if PROFILING_DISABLE_SHADING == 0
    std::string vsSource = ReadFile(vsFilename);
#else
    std::string vsSource = ReadFile("null-shader.vs.glsl");
#endif
    shader.addVertexShader(vsSource);

#if PROFILING_DISABLE_SHADING == 0
    std::string fsSource = ReadFile(fsFilename);
#else
    std::string fsSource = ReadFile("null-shader.fs.glsl");
#endif
    shader.addFragmentShader(fsSource);

    if(!gsFilename.empty()){
        std::string gsSource = ReadFile(gsFilename);
        shader.addGeometryShader(gsSource);
    }

    shader.linkProgram();

    return shader;
}

std::string ShaderLoader::ReadFile(const std::string &filename) {
    const std::string INCLUDE_DIRECTIVE = "#include";
    std::ifstream file;

    file.open("res/shaders/" + filename);

    if(!file.is_open()){
        Log::Message("error loading file " + filename, LOG_WARNING);
        return "";
    }
    std::string res;
    while(!file.eof()){
        std::string string;
        std::getline(file, string);
        if(string.empty())continue;
        if(string.substr(0, INCLUDE_DIRECTIVE.size()) == INCLUDE_DIRECTIVE){
            string = ReadFile(string.substr(string.find_first_of('\"')+1, string.find_last_of('\"') - string.find_first_of(
                    '\"')-1));
        }
        res += string + "\n";
    }
    file.close();

    return res;
}
