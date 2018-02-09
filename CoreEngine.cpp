//
// Created by rostard on 14.12.17.
//

#include <chrono>
#include <thread>
#include "CoreEngine.h"
#include "Mesh.h"
#include "Window.h"
#include "utility/Log.h"

CoreEngine::CoreEngine(unsigned int width, unsigned int height, unsigned int framerate, Game *game) : width(width),
                                                                                                      height(height),
                                                                                                      game(game),
                                                                                                      isRunning(false),
                                                                                                      frameTime(1.0f / framerate){
    game->setEngine(this);
}

CoreEngine::~CoreEngine() {
    delete window;
    delete renderingEngine;
}


void CoreEngine::start() {
    if (isRunning)
        return;

    run();
}

void CoreEngine::stop() {
    isRunning = false;
}

void CoreEngine::createWindow(const std::string &title) {

    window = new Window(width, height, title);
    this->renderingEngine = new RenderingEngine(window);
}

void CoreEngine::run() {
    this->isRunning = true;
    double lastTime = glfwGetTime();

    double frameTime = 1.0 / 90.0;
    double passedTime = 0.0;

    int frames = 0;
    double framesCounter = 0;

    game->init(*window);

    while (this->isRunning) {
        double curTime = glfwGetTime();
        double deltaTime = curTime - lastTime;
        lastTime = curTime;
        bool render = false;

        passedTime += deltaTime;
        framesCounter += deltaTime;

        while (passedTime > frameTime) {
            render = true;
            passedTime -= frameTime;

            window->update();
            if (window->shouldClose())this->isRunning = false;

            game->update(deltaTime);
            game->processInput(window->getInput(), deltaTime);

            if (framesCounter >= 1.0) {
                //TODO: print number of frames
                Log::Message(std::to_string(frames), LOG_INFO);
                frames = 0;
                framesCounter = 0;
            }
        }
        if (render) {
            frames++;
            game->render(renderingEngine);
            window->swapBuffers();
        } else {
//                std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

RenderingEngine *CoreEngine::getRenderingEngine() {
    return renderingEngine;
}

