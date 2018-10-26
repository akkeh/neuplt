#include <iostream>
#include <GLFW/glfw3.h>

#include "Win.h"

void error_callback(int error, const char* descr) {
    fprintf(stderr, "Error: %s (%d)\n", descr, error);
}

int initGLFW();

int main() {
    initGLFW();
    Win* win = new Win(10, 10, 2, 2);
    //win->addAx(0, 0, 1, 1);
    win->addAx(0, 0, 1, 1);
    win->addAx(0, 1, 1, 2);
    double time = glfwGetTime();

    while(win->draw()) {};

    delete win;
    glfwTerminate();

    std::cout << "point!\n";
    return 0;
}


int initGLFW() {
    // init GLFW ---------------------------------------------------- | 
    if (!glfwInit()) {
        std::cout << "error in GLFW init\n";
    }

    glfwSetErrorCallback(error_callback);

    return 1;
}
