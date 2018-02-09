//
// Created by rostard on 11.12.17.
//
#include <glad/glad.h>
#include <iostream>
#include "Window.h"
#include "utility/Log.h"
std::map<GLFWwindow*, Window*> Window::windows;

static void error_callback(int error, const char* description)
{
    Log::Message(std::string("GLFW Error: ") + description, LOG_ERROR);
}

void Window::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    switch(action){
        case GLFW_PRESS:
            windows[window]->input.setKey(key, true);
            windows[window]->input.setKeyDown(key, true);
            break;

        case GLFW_RELEASE:
            windows[window]->input.setKey(key, false);
            windows[window]->input.setKeyDown(key, true);
            break;

        case GLFW_REPEAT:

            break;

        default:
            Log::Message("key callback unhandled action" + std::to_string(key), LOG_WARNING);
    }


}

Window::Window(unsigned int screen_width, unsigned int screen_height, const std::string &title) : width(screen_width), height(screen_height), title(title), input(this), initialized(false) {
    initGLFW();

    window = glfwCreateWindow(screen_width, screen_height, title.c_str(), nullptr, nullptr);
    windows.insert(std::make_pair(window, this));
    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);

    if (window == nullptr)
    {
        glfwTerminate();
        Log::Message("Failed to create GLFW window", LOG_ERROR);
    }


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        Log::Message("Failed to initialize GLAD", LOG_ERROR);
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::initGLFW() {
    if(initialized)
        return;
    initialized = true;

    glfwSetErrorCallback(error_callback);

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}

bool Window::shouldClose() const{
    return static_cast<bool>(glfwWindowShouldClose(window));
}


void Window::update() {
    for(int i = 0; i < Input::numOfKeys; ++i){
        input.setKeyDown(i, false);
        input.setKeyUp(i, false);
    }

    glfwPollEvents();

}

void Window::swapBuffers() {
    glfwSwapBuffers(window);
}

Vector2f Window::getSize() const {
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    return {width, height};
}

Vector2f Window::getCenter() const {
    Vector2f size = getSize();
    return Vector2f(size.getX() / 2.0f, size.getY() / 2.0f);
}

void Window::bindAsRenderTarget() {
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
    Vector2f size = getSize();
    glViewport(0, 0, size.getX(), size.getY());
}

const Input &Window::getInput() const {
    return input;
}
