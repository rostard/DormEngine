//
// Created by rostard on 15.01.18.
//

#ifndef DORMENGINE_FRAMEBUFFER_H
#define DORMENGINE_FRAMEBUFFER_H


class Texture;
class Framebuffer {
public:
    Framebuffer(int num_textures, int width, int height, int* filters, int *attachments);
    void bindAsRenderTarget();
    Texture* getTextureId(int pos);
private:
    unsigned int m_framebuffer;
    unsigned int m_renderBuffer;
    int m_width;
    int m_height;
    int m_numTextures;
    unsigned int *ids;
};


#endif //DORMENGINE_FRAMEBUFFER_H
