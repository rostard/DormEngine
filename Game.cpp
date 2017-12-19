//
// Created by rostard on 14.12.17.
//

#include "Game.h"

void Game::input(float d_time) {
    root->input();
}

void Game::update(float d_time) {
    root->update();
}

void Game::init() {

}

void Game::render() {
    root->render();
}
