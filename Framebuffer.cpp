//
// Created by rostard on 15.01.18.
//

#include <glad/glad.h>
#include <cstring>
#include <iostream>
#include <assert.h>
#include "Framebuffer.h"
#include "Texture.h"

Framebuffer::Framebuffer(int num_textures, int width, int height, GLint* internalFormats, GLenum* formats, int* filters, GLenum *attachments): m_numTextures(num_textures), m_width(width), m_height(height) {
    m_textures = new Texture*[num_textures];

    glGenFramebuffers(1, &m_framebuffer);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, m_framebuffer);

    unsigned int* ids = new unsigned int[num_textures];
    glGenTextures(num_textures, ids);

    GLenum drawBuffers[m_numTextures];
    bool hasDepth = false;

    int dataSize = width * height * 4;
    unsigned char* data = new unsigned char[dataSize];
    memset(data, 0, dataSize);


    for(int i = 0; i < m_numTextures; i++){
        if(attachments[i] == GL_DEPTH_ATTACHMENT)
        {
            drawBuffers[i] = GL_NONE;
            hasDepth = true;
        }
        else
            drawBuffers[i] = attachments[i];
        glBindTexture(GL_TEXTURE_2D, ids[i]);
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormats[i], width, height, 0, formats[i], GL_UNSIGNED_BYTE, data);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filters[i]);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filters[i]);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

        glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, attachments[i], GL_TEXTURE_2D, ids[i], 0);
        m_textures[i] = new Texture(ids[i], width, height);
    }

    if(!hasDepth){
        glGenRenderbuffers(1, &m_renderBuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, m_renderBuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, m_width, m_height);
        glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_renderBuffer);
    }


    glDrawBuffers(m_numTextures, drawBuffers);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER)!=GL_FRAMEBUFFER_COMPLETE){
        std::cerr << "Framebuffer creation failed!" << std::endl;
        assert(false);
    }

    delete[] data;
}


Framebuffer::Framebuffer(int num_textures, Texture **textures, GLenum *attachments) {
    m_textures = textures;

    glGenFramebuffers(1, &m_framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);

    bool hasDepth = false;
    GLenum drawBuffers[m_numTextures];

    m_numTextures = num_textures;


    for(int i = 0; i < num_textures; ++i){
        if(attachments[i] == GL_DEPTH_ATTACHMENT){
            hasDepth = true;
            drawBuffers[i] = GL_NONE;
        }
        else{
            drawBuffers[i] = attachments[i];
        }
        glBindTexture(GL_TEXTURE_2D, m_textures[i]->getId());
        glFramebufferTexture2D(GL_FRAMEBUFFER, attachments[i], GL_TEXTURE_2D, static_cast<GLuint>(textures[i]->getId()), 0);
    }


    if(!hasDepth){
        glGenRenderbuffers(1, &m_renderBuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, m_renderBuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, m_width, m_height);
        glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_renderBuffer);
    }


    glDrawBuffers(m_numTextures, drawBuffers);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER)!=GL_FRAMEBUFFER_COMPLETE){
        std::cerr << "Framebuffer creation failed!" << std::endl;
        assert(false);
    }
}

void Framebuffer::bindAsRenderTarget() {
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, m_framebuffer);
    glViewport(0, 0, m_width, m_height);
}

Texture* Framebuffer::getTextureId(int pos) {
    return m_textures[pos];
}

Framebuffer::~Framebuffer() {
    for(int i = 0; i < m_numTextures; ++i){
        delete m_textures[i];
    }
    delete[] m_textures;
}
