//
// Created by rostard on 11.12.17.
//

#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H


#include <GLFW/glfw3.h>
#include <string>
#include "math/Vector2f.h"

class Window {
public:
    Window() = delete;

    static void initGLFW();

    static void createWindow(const unsigned int &screen_width, const unsigned int &screen_height,
                      const std::string& title);

    static bool isShouldClose();

    static void render();

    static bool getKey(int key);

    static Vector2f getSize();

    static Vector2f getCenter();

    static bool getMouseButton(int button);

    static void dispose();
private:
    static GLFWwindow* window;
    static bool initialized;
};


#endif //ENGINE_WINDOW_H
