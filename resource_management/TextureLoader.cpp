//
// Created by rostard on 17.12.17.
//

#include <GL/glew.h>
#include "../dependencies/stb_image.h"
#include "TextureLoader.h"

Texture TextureLoader::Load(const std::string &filename,  GLint filter, bool srgb) {
    stbi_set_flip_vertically_on_load(true);

    int width, height, nrChannels;
    unsigned char* data = stbi_load(("res/textures/" + filename).c_str(), &width, &height,&nrChannels, 0);

    unsigned int id;
    glGenTextures(1, &id);

    glBindTexture(GL_TEXTURE_2D, id);

    GLenum format;
    if(nrChannels == 1) format = GL_RED;
    else if(nrChannels == 3) format = GL_RGB;
    else if(nrChannels == 4) format = GL_RGBA;
    GLenum internalFormat = format;
    if(srgb){
        internalFormat = GL_SRGB;
    }
    glBindTexture(GL_TEXTURE_2D, id);
    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, data);

    if(filter == GL_LINEAR_MIPMAP_LINEAR ||
            filter == GL_LINEAR_MIPMAP_NEAREST ||
            filter == GL_NEAREST_MIPMAP_LINEAR ||
            filter == GL_NEAREST_MIPMAP_NEAREST){
        glGenerateMipmap(GL_TEXTURE_2D);
        GLfloat maxAnisotropy;
        glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropy);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAnisotropy);
    } else {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    stbi_image_free(data);

    return Texture(id, width, height);
}
