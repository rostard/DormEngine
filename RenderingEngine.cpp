//
// Created by rostard on 14.12.17.
//

#include <glad/glad.h>
#include "RenderingEngine.h"

RenderingEngine::RenderingEngine() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH_CLAMP);
    glEnable(GL_TEXTURE_2D);
}

void RenderingEngine::clearScreen() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

