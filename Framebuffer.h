//
// Created by rostard on 15.01.18.
//

#ifndef DORMENGINE_FRAMEBUFFER_H
#define DORMENGINE_FRAMEBUFFER_H


class Texture;

class Framebuffer {
public:
    Framebuffer(int num_textures, int width, int height, GLint* internalFormats, GLenum* formats, int* filters, GLenum *attachments);
    Framebuffer(int num_textures, Texture** textures, GLenum *attachments);
    virtual ~Framebuffer();

    void bindAsRenderTarget();
    Texture* getTextureId(int pos);

    inline int getWidth() const { return m_width; }
    inline int getHeight() const { return m_height; }
private:
    unsigned int m_framebuffer;
    unsigned int m_renderBuffer;
    int m_width;
    int m_height;
    int m_numTextures;;
    Texture ** m_textures;
};


#endif //DORMENGINE_FRAMEBUFFER_H
