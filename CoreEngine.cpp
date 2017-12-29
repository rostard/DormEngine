//
// Created by rostard on 14.12.17.
//

#include <chrono>
#include <thread>
#include "CoreEngine.h"
#include "Mesh.h"
#include "Window.h"

CoreEngine::CoreEngine(unsigned int width, unsigned int height, unsigned int framerate, Game *game) : width(width),
                                                                                                      height(height),
                                                                                                      game(game) {
    isRunning = false;
    frameTime = 1.0 / framerate;
}

CoreEngine::~CoreEngine() {
    delete renderingEngine;
}

void CoreEngine::cleanUp() {
    Window::dispose();
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
    Window::initGLFW();
    Window::createWindow(width, height, title);
    this->renderingEngine = new RenderingEngine();
}

void CoreEngine::run() {
    this->isRunning = true;
    double lastTime = glfwGetTime();

    double frameTime = 1.0 / 90.0;
    double passedTime = 0.0;

    int frames = 0;
    double framesCounter = 0;

    game->init();

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

            glfwPollEvents();
            if (Window::isShouldClose())this->isRunning = false;

            game->update(deltaTime);
            game->input(deltaTime);

            if (framesCounter >= 1.0) {
                //TODO: print number of frames
                frames = 0;
                framesCounter = 0;
            }
        }
        if (render) {
            frames++;
            game->render(renderingEngine);
            Window::render();
        } else {
//                std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    cleanUp();
}

