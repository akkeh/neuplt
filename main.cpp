#include <iostream>
#include <fstream>
#include <vector>

#include <GLFW/glfw3.h>

#include "Win.h"

void error_callback(int error, const char* descr) {
    fprintf(stderr, "Error: %s (%d)\n", descr, error);
}

int initGLFW();

int main() {
    initGLFW();
    Win* win = new Win(10, 10, 2, 2);
    win->addAx(0, 0, 1, 2);
    win->addAx(1, 0, 2, 1);
    win->addAx(1, 1, 2, 2);
   
    /* 
    int N =0; 
    float* X; float* Y;
    std::string line;
    std::ifstream f("Vm.txt");
    while(getline(f, line)) {
        N++;
    }
    f.close();
    X = new float[N]; Y = new float[N];
    f.open("Vm.txt");
    int i = 0;
    while(getline(f, line)) {
        X[i] = atof(line.substr(0, line.find("\t")).c_str());
        Y[i] = atof(line.substr(line.find("\t"), line.find("\n")).c_str());
        i++;
    }
    f.close();
    */
   
    std::vector<const char*> args{"0", "1"};
    win->axs[0]->addPlt(xy, "./data/Vm.txt", args);
    std::vector<const char*> args2{"0"};
    win->axs[1]->addPlt(xy, "./data/gates.txt", args2);
    std::vector<const char*> args3{"1"};
    win->axs[1]->addPlt(xy, "./data/gates.txt", args3);
    std::vector<const char*> args4{"2"};
    win->axs[1]->addPlt(xy, "./data/gates.txt", args4);
    std::vector<const char*> args5{"0", "1"};
    win->axs[2]->addPlt(xy, "./data/spikes.txt", args5);
    //((PltXY*)win->axs[0]->plts[0])->setData(N, Y, X);
    win->axs[0]->plts[0]->readData();
    win->axs[1]->plts[0]->readData();
    win->axs[1]->plts[1]->readData();
    win->axs[1]->plts[1]->cr = 1;
    win->axs[1]->plts[2]->readData();
    win->axs[1]->plts[2]->cg = 1;
    win->axs[2]->plts[0]->readData();
    double time = glfwGetTime();

    while(win->draw()) {};
    std::cout << "point!\n";

    delete win;
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
