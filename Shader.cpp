//
// Created by rostard on 14.12.17.
//

#include <glad/glad.h>
#include "Shader.h"
#include "utility/Log.h"
#include "Material.h"

Shader::Shader() {
    program = glCreateProgram();
}


Shader::Shader(const Shader &shader) {
    setProgram(shader.getProgram());
}


std::string shaderTypeToStr(int shaderType){
    std::string ret;
    switch (shaderType){
        case GL_VERTEX_SHADER:
            ret = "VERTEX_SHADER";
            break;
        case GL_FRAGMENT_SHADER:
            ret = "FRAGMENT_SHADER";
            break;
        case GL_GEOMETRY_SHADER:
            ret = "GEOMETRY_SHADER";
            break;
        default:
            ret = "UNKNOWN_SHADER";
    }
    return ret;
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
        Log::log("ERROR::"+ shaderTypeToStr(shaderType) +"::COMPILATION_FAILED\n" + std::string(infoLog));
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

void Shader::setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::setMat4(const std::string &name, Matrix4f matrix) const {
    glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_TRUE, matrix.getM());
}


void Shader::setVec3(const std::string &name, Vector3f vector) const {
    glUniform3f(glGetUniformLocation(program, name.c_str()), vector.getX(), vector.getY(), vector.getZ());
}


void Shader::updateUniforms(Transform &transform, const Material &matrerial, RenderingEngine* renderingEngine) {
    setMat4("haha", transform.getTransformation());
    setMat4("transform", transform.getProjectedTransformation(*renderingEngine->getMainCamera()));

}

unsigned int Shader::getProgram() const {
    return program;
}

void Shader::setProgram(unsigned int program) {
    Shader::program = program;
}
