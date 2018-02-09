//
// Created by rostard on 12.12.17.
//

#include <algorithm>
#include <iostream>
#include "Input.h"

Input::Input(Window *window): window(window) {

}


void Input::setWindowCapture(Window &window) {
    Input::window = &window;
}

bool Input::getKeyDown(unsigned int keyCode) const{
    return downKeys[keyCode];
}

bool Input::getKeyUp(unsigned int keyCode) const{
    return upKeys[keyCode];
}

bool Input::getKey(unsigned int keyCode) const{
    return inputs[keyCode];
}

void Input::setKeyUp(unsigned int keyCode, bool state){
    upKeys[keyCode] = state;
}

void Input::setKeyDown(unsigned int keyCode, bool state){
    downKeys[keyCode] = state;
}

void Input::setKey(unsigned int keyCode, bool state) {
    inputs[keyCode] = state;
}
