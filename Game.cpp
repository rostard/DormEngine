//
// Created by rostard on 14.12.17.
//

#include "Game.h"
#include "RenderingEngine.h"
void Game::input(float d_time) {
    root->input(d_time);

}

void Game::update(float d_time) {
    root->update(d_time);
}

void Game::init() {
    root = new GameObject();
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
