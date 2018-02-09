//
// Created by rostard on 11.12.17.
//

#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H


#include <GLFW/glfw3.h>
#include <string>
#include <map>
#include "math/Vector2f.h"
#include "Input.h"

class Window {
public:
    Window(unsigned int screen_width, unsigned int screen_height, const std::string& title);

    virtual ~Window();

    void initGLFW();

    void bindAsRenderTarget();

    bool shouldClose() const;

    void update();

    void swapBuffers();

    Vector2f getSize() const;

    Vector2f getCenter() const;

    const Input& getInput() const;
private:
    static std::map<GLFWwindow*, Window*> windows;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    GLFWwindow* window;

    unsigned int width;
    unsigned int height;
    std::string title;
    Input input;
    bool initialized;
};


#endif //ENGINE_WINDOW_H
