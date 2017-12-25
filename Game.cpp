//
// Created by rostard on 14.12.17.
//

#include "Game.h"

void Game::input(float d_time) {
    root->input(d_time);

}

void Game::update(float d_time) {
    root->update(d_time);
}

void Game::init() {

}

GameObject *Game::getRoot() {
    return root;
}
