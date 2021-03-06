//
// Created by rostard on 17.12.17.
//

#ifndef DORMENGINE_TEXTURELOADER_H
#define DORMENGINE_TEXTURELOADER_H
#include <GL/gl.h>
#include <string>
#include "../Texture.h"

class TextureLoader {
public:
    static Texture Load(const std::string& filename, GLint filter = GL_LINEAR,  bool srgb = false);
};


#endif //DORMENGINE_TEXTURELOADER_H
