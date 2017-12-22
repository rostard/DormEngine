//
// Created by rostard on 11.12.17.
//
#include <glad/glad.h>
#include <iostream>
#include "Window.h"
#include "utility/Log.h"

GLFWwindow* Window::window = nullptr;
bool Window::initialized = false;

void Window::createWindow(const unsigned int& screen_width, const unsigned int& screen_height, const std::string& title) {

    window = glfwCreateWindow(screen_width, screen_height, title.c_str(), nullptr, nullptr);

    glfwMakeContextCurrent(window);

    if (window == nullptr)
    {
        glfwTerminate();
        Log::log("Failed to create GLFW window");
    }


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        Log::log("Failed to initialize GLAD");

}

bool Window::isShouldClose() {
    return static_cast<bool>(glfwWindowShouldClose(window));
}

void Window::render() {
    glfwSwapBuffers(window);
}

bool Window::getKey(const int key) {
    return glfwGetKey(window, key) == GLFW_PRESS;
}

Vector2f Window::getSize() {
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    return {width, height};
}


bool Window::getMouseButton(const int button) {
    return static_cast<bool>(glfwGetMouseButton(window, button));
}

void Window::dispose() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::initGLFW() {
    if(initialized)
        return;
    initialized = true;

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}

Vector2f Window::getCenter() {
    Vector2f size = getSize();
    return Vector2f(size.getX() / 2.0f, size.getY() / 2.0f);
}
