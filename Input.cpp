//
// Created by rostard on 12.12.17.
//

#include <algorithm>
#include <iostream>
#include "Input.h"
#include "Window.h"

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

bool Input::getMouseDown(unsigned int keyCode) const {
    return mouseDown[keyCode];
}

bool Input::getMouseUp(unsigned int keyCode) const {
    return mouseUp[keyCode];
}

bool Input::getMouse(unsigned int keyCode) const {
    return mouseInputs[keyCode];
}

void Input::setMouseDown(unsigned int keyCode, bool state) {
    mouseDown[keyCode] = state;
}

void Input::setMouseUp(unsigned int keyCode, bool state) {
    mouseUp[keyCode] = state;
}

void Input::setMouse(unsigned int keyCode, bool state) {
    mouseInputs[keyCode] = state;
}

int Input::getMouseX() const {
    return mouseX;
}

int Input::getMouseY() const {
    return mouseY;
}

Vector2f Input::getMousePosition() const {
    return Vector2f(mouseX, mouseY);
}

void Input::setMouseX(int mouseX) {
    Input::mouseX = mouseX;
}

void Input::setMouseY(int mouseY) {
    Input::mouseY = mouseY;
}

void Input::setMousePos(const Vector2f &pos) const{
    window->setMousePos(pos);
}

void Input::setCursor(bool state) const {
    window->setCursor(state);
}

