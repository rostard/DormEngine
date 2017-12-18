//
// Created by rostard on 14.12.17.
//

#ifndef DORMENGINE_COREENGINE_H
#define DORMENGINE_COREENGINE_H


#include "Game.h"
#include "Window.h"
#include "RenderingEngine.h"

class CoreEngine {
public:
    CoreEngine(unsigned int width, unsigned int height, unsigned int framerate, Game *game);
    ~CoreEngine();
    void start();

    void stop();

    void createWindow(const std::string& title);
private:
    void cleanUp();

    void run();

    Game *game;
    RenderingEngine* renderingEngine;

    unsigned int width;
    unsigned int height;

    double frameTime;

    bool isRunning;
};


#endif //DORMENGINE_COREENGINE_H
