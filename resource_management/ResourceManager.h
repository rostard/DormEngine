//
// Created by rostard on 17.12.17.
//

#ifndef DORMENGINE_RESOURCEMANAGER_H
#define DORMENGINE_RESOURCEMANAGER_H


#include <map>
#include <GL/gl.h>
#include "../Shader.h"
#include "../Texture.h"
#include "../Mesh.h"


class ResourceManager {
public:
    static Shader* loadShader(const std::string& name, const std::string& vsFilename, const std::string& fsFilename, const std::string& gsFilename = "");
    static Shader* getShader(const std::string& name);

    static Texture* loadTexture(const std::string& name, const std::string& filename, GLint filter = GL_LINEAR, bool srgb = false);
    static Texture* getTexture(const std::string& name);

    //TODO: cubemap loader
    //TODO: mesh loader

    static Mesh* loadMesh(const std::string& name, const std::string& filename);
    static Mesh* getMesh(const std::string& name);

private:
    static std::map<unsigned int, Shader> shaders;
    static std::map<unsigned int, Texture> textures;
    static std::map<unsigned int, Mesh> meshes;
};


#endif //DORMENGINE_RESOURCEMANAGER_H
