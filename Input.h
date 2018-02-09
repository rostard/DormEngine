//
// Created by rostard on 12.12.17.
//

#ifndef ENGINE_INPUT_H
#define ENGINE_INPUT_H


#include <vector>
class Window;

class Input {
public:
    Input(Window* window);

    void update();
    void setWindowCapture(Window &window);

    bool getKeyDown(unsigned int keyCode) const;
    bool getKeyUp(unsigned int keyCode) const;
    bool getKey(unsigned int keyCode) const;

    void setKeyDown(unsigned int keyCode, bool state);
    void setKeyUp(unsigned int keyCode, bool state);
    void setKey(unsigned int keyCode, bool state);

    static const unsigned int numOfKeys = 300;
private:
    bool inputs[numOfKeys];
    bool downKeys[numOfKeys];
    bool upKeys[numOfKeys];

    Window* window;
};


#endif //ENGINE_INPUT_H
