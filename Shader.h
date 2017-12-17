//
// Created by rostard on 14.12.17.
//

#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

#include <string>

class Shader {
public:
    Shader();

    void addShader(const std::string& shaderSource, GLenum shaderType);

    void linkProgram();

    void Bind();

private:
    unsigned int program;
};


#endif //ENGINE_SHADER_H
