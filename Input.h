//
// Created by rostard on 12.12.17.
//

#ifndef ENGINE_INPUT_H
#define ENGINE_INPUT_H


#include <vector>
#include "math/Vector2f.h"

class Window;

class Input {
public:
    Input(Window* window);

    void setWindowCapture(Window &window);

    bool getKeyDown(unsigned int keyCode) const;
    bool getKeyUp(unsigned int keyCode) const;
    bool getKey(unsigned int keyCode) const;

    void setKeyDown(unsigned int keyCode, bool state);
    void setKeyUp(unsigned int keyCode, bool state);
    void setKey(unsigned int keyCode, bool state);

    bool getMouseDown(unsigned int keyCode) const;
    bool getMouseUp(unsigned int keyCode) const;
    bool getMouse(unsigned int keyCode) const;

    void setMouseDown(unsigned int keyCode, bool state);
    void setMouseUp(unsigned int keyCode, bool state);
    void setMouse(unsigned int keyCode, bool state);

    int getMouseX() const;
    int getMouseY() const;
    Vector2f getMousePosition() const;

    void setMouseX(int mouseX);
    void setMouseY(int mouseY);

    void setMousePos(const Vector2f& pos) const;
    void setCursor(bool state) const;

    static const unsigned int NUM_OF_KEYS = 512;
    static const unsigned int NUM_OF_MOUSEBUTTONS = 256;
private:
    bool inputs[NUM_OF_KEYS];
    bool downKeys[NUM_OF_KEYS];
    bool upKeys[NUM_OF_KEYS];

    bool mouseInputs[NUM_OF_MOUSEBUTTONS];
    bool mouseDown[NUM_OF_MOUSEBUTTONS];
    bool mouseUp[NUM_OF_MOUSEBUTTONS];

    int mouseX;
    int mouseY;

    Window* window;
};


#endif //ENGINE_INPUT_H
