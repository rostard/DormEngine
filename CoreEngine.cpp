//
// Created by rostard on 14.12.17.
//

#include <chrono>
#include <thread>
#include "CoreEngine.h"
#include "Mesh.h"
#include "Window.h"
#include "utility/Log.h"
#include "Time.h"

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
    double lastTime = Time::GetTime();

    double passedTime = 0.0;

    int frames = 0;
    double framesCounter = 0;

    game->init(*window);

    while (this->isRunning) {
        double curTime = Time::GetTime();
        double deltaTime = curTime - lastTime;
        lastTime = curTime;
        bool render = false;

        passedTime += deltaTime;
        framesCounter += deltaTime;

        if (framesCounter >= 1.0) {
            //TODO: print number of frames
            double totalTime = ((1000.0 * framesCounter)/((double)frames));
            double totalMeasuredTime = 0.0;

            totalMeasuredTime += renderingEngine->displayRenderTime(frames);
            totalMeasuredTime += renderingEngine->displayWindowSyncTime(frames);
            totalMeasuredTime += updateProfileTimer.displayAndReset("Update time: ", frames);
            totalMeasuredTime += swapBufferProfileTimer.displayAndReset("SwapBuffer time: ", frames);

            Log::Message("Other time: " + std::to_string(totalTime - totalMeasuredTime), LOG_INFO);
            Log::Message("All time: " + std::to_string(totalTime) + "ms", LOG_INFO);
            Log::Message("FPS: " + std::to_string(frames), LOG_INFO);

            frames = 0;
            framesCounter = 0;
        }

        while (passedTime > frameTime) {
            render = true;
            passedTime -= frameTime;

            updateProfileTimer.startInvocation();
            window->update();
            if (window->shouldClose())this->isRunning = false;

            game->processInput(window->getInput(), frameTime);
            game->update(frameTime);
            updateProfileTimer.stopInvocation();
        }
        if (render) {
            frames++;
            game->render(renderingEngine);

            swapBufferProfileTimer.startInvocation();
            window->swapBuffers();
            swapBufferProfileTimer.stopInvocation();
        } else {
//                std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

RenderingEngine *CoreEngine::getRenderingEngine() {
    return renderingEngine;
}

