#include <iostream>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* descr) {
    fprintf(stderr, "Error: %s (%d)\n", descr, error);
}
/*
void close(GLFWwindow* win) {
    std::cout << "Closing win\n";
    //glfwSetWindowShouldClose(win, GL_TRUE);
}
*/
void key_callback(GLFWwindow* win, int key, int scancode, int action, int mods) {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(win, GLFW_TRUE);
}

int initGLFW();

int main() {
    initGLFW();
    int w, h;
    double time = glfwGetTime();
    // -------------------------------------------------------------- | 
    /*
    while(!glfwWindowShouldClose(win)) {
        //glfwWaitEvents();   // glfwPollEvents()?
        glfwSwapBuffers(win);
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glVertex3f(-1, -1, 0);
        glVertex3f(1, 1, 0);
        glVertex3f(-1, 1, 0);
        glEnd();

        glfwGetFramebufferSize(win, &w, &h);
        glViewport(0, 0, w, h);
    }
    
    std::cout << "closing...\n";
    glfwDestroyWindow(win);
    */
    glfwTerminate();
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
    /*
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    */
    GLFWwindow* win = glfwCreateWindow(640, 480, "title", NULL, NULL);
    if(!win) {
        std::cout << "error in win creation\n";
    }
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwSetKeyCallback(win, key_callback);

    //glfwSetWindowCloseCallback(win, close);

    glfwMakeContextCurrent(win);    // make OpenGL API useable on win 

    glfwSwapInterval(1);

    return 1;
}
