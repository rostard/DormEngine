//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_COREENGINE_H
#define DORMENGINE_COREENGINE_H


#include "ProjectHeaders.h"

class Window;

class CoreEngine {
public:
    CoreEngine(unsigned int width, unsigned int height, unsigned int framerate, Game *game);
    ~CoreEngine();
    void start();

    void stop();

    void createWindow(const std::string& title);

    RenderingEngine* getRenderingEngine();
private:
    Window* window;

    void run();

    Game *game;
    RenderingEngine* renderingEngine;

    unsigned int width;
    unsigned int height;

    double frameTime;

    bool isRunning;
    ProfileTimer swapBufferProfileTimer;
    ProfileTimer updateProfileTimer;
};


#endif //DORMENGINE_COREENGINE_H
