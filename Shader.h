//
// Created by rostard on 14.12.17.
//

#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

#include <string>
#include "Transform.h"
#include "RenderingEngine.h"

class RenderingEngine;

class Shader {
public:
    Shader();


    void addVertexShader(const std::string& shaderSource);
    void addFragmentShader(const std::string& shaderSource);
    void addGeometryShader(const std::string& shaderSource);

    void linkProgram();

    void bind();

    void setInt(const std::string &name, int value) const;
    void setMat4(const std::string &name, Matrix4f matrix) const;

    void setRenderingEngine(RenderingEngine* engine);

    void updateMatrices(const Transform &transform);

private:
    void addShader(const std::string& shaderSource, int shaderType);

    unsigned int program;
    RenderingEngine* renderingEngine;
};


#endif //ENGINE_SHADER_H
