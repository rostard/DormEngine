//
// Created by rostard on 14.12.17.
//

#include "Game.h"
#include "RenderingEngine.h"
void Game::input(float d_time) {
    root->inputAll(d_time);

}

void Game::update(float d_time) {
    root->updateAll(d_time);
}

void Game::init() {
}

GameObject *Game::getRoot() {
    return root;
}

void Game::render(RenderingEngine *renderingEngine) {
    renderingEngine->render(*root);
}

void Game::addObject(GameObject *gameObject) {
    root->addChild(gameObject);
}

void Game::setEngine(CoreEngine *engine) {
    root = new GameObject();
    root->setEngine(engine);
}
