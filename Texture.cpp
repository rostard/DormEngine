//
// Created by rostard on 17.12.17.
//

#include <glad/glad.h>
#include "Texture.h"

Texture::Texture(int id) : id(id) {}

void Texture::bind() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, id);
}

Texture::Texture():id(0) {}


