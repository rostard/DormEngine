//
// Created by rostard on 14.12.17.
//

#include <glad/glad.h>
#include "Shader.h"
#include "Log.h"

Shader::Shader() {
    program = glCreateProgram();
}

void Shader::addShader(const std::string &shaderSource, GLenum shaderType) {
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

void Shader::Bind() {
    glUseProgram(program);
}


