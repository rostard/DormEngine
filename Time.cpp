//
// Created by rostard on 24.02.18.
//

#include <GLFW/glfw3.h>
#include "Time.h"

double Time::GetTime() {
    return glfwGetTime();
}
