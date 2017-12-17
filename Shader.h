//
// Created by rostard on 14.12.17.
//

#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

#include <string>


class Shader {
public:
    Shader();


    void addVertexShader(const std::string& shaderSource);
    void addFragmentShader(const std::string& shaderSource);
    void addGeometryShader(const std::string& shaderSource);

    void linkProgram();

    void Bind();

private:
    void addShader(const std::string& shaderSource, int shaderType);

    unsigned int program;
};


#endif //ENGINE_SHADER_H
