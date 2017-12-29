//
// Created by rostard on 17.12.17.
//

#include <glad/glad.h>
#include "Texture.h"

Texture::Texture(int id) : id(id) {}

void Texture::bind(unsigned int slot) {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, id);
}

Texture::Texture():id(0) {}


