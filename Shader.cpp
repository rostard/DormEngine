//
// Created by rostard on 14.12.17.
//

#include <glad/glad.h>
#include "Shader.h"
#include "utility/Log.h"

Shader::Shader() {
    program = glCreateProgram();
}

void Shader::addShader(const std::string &shaderSource, int shaderType) {
    unsigned int shader = glCreateShader(shaderType);
    const char* shaderCode = shaderSource.c_str();
    glShaderSource(shader, 1, &shaderCode , nullptr);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    
    if(!success){
        glGetShaderInfoLog(shader, 512, nullptr, &infoLog[0]);
        Log::log("ERROR::SHADER::COMPILATION_FAILED\n" + std::string(infoLog));
    }

    glAttachShader(program, shader);
}

void Shader::linkProgram() {
    glLinkProgram(program);

    int success;
    char infoLog[512];

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        Log::log("ERROR::SHADER::LINK_FAILED\n" + std::string(infoLog));
    }

    glValidateProgram(program);

    glGetProgramiv(program, GL_VALIDATE_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        Log::log("ERROR::SHADER::VALIDATION_FAILED\n" + std::string(infoLog));
    }
}

void Shader::bind() {
    glUseProgram(program);
}

void Shader::addVertexShader(const std::string &shaderSource) {
    addShader(shaderSource, GL_VERTEX_SHADER);
}

void Shader::addFragmentShader(const std::string &shaderSource) {
    addShader(shaderSource, GL_FRAGMENT_SHADER);
}

void Shader::addGeometryShader(const std::string &shaderSource) {
    addShader(shaderSource, GL_GEOMETRY_SHADER);
}

void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::setMat4(const std::string &name, Matrix4f matrix) const {
    glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_TRUE, matrix.getM());
}
