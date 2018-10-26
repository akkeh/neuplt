#include "Win.h"

int Win::addAx(int r0, int c0, int rN, int cN) {
    // check out of bounds
    //if((r0+R)>rows || (c0+C)>cols) {
    //    return -1;
    //}
    float x0 = -1+this->bw+this->cw*((float)c0);
    float y0 = -1+this->bh+this->rh*((float)r0);
    float xN = -1+this->bw+this->cw*((float)(cN));
    float yN = -1+this->bh+this->rh*((float)(rN));
    std::cout << "x0, y0: " << x0 << ", " << y0;
    std::cout << "xN, yN: " << xN << ", " << yN << std::endl;

    Ax* nax = new Ax(x0, y0, xN, yN);
    Ax** tax = this->axs;
    this->axs = new Ax*[this->Nax+1];
    for(int i=0; i<this->Nax; i++)
        this->axs[i] = tax[i];
    this->axs[this->Nax] = nax;
    this->Nax++;
};

Win::Win(int w, int h, int rows, int cols) {
    this->w = w; this->h = h;
    this->rows = rows; this->cols = cols;
    this->bw = 0.1; this->bh = 0.1;
    this->cw = (2-2*this->bw) / ((float)this->cols); //(w-2*this->bw) / this->rows;
    this->rh = (2-2*this->bh) / ((float)this->rows); //(h-2*this->bh) / this->cols;
    this->r = 0; this->c = 0;

    this->Nax = 0;
    this->axs = NULL;

    this->win = glfwCreateWindow(this->w, this->h, "plt", NULL, NULL);
    if(!this->win) {
        std::cout << "error in window creation\n";
    }    
    // GLFW init
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwSetKeyCallback(this->win, this->key_callback);
    glfwMakeContextCurrent(this->win);
    glfwSwapInterval(1);
    // ...
    glfwSetWindowShouldClose(win, GLFW_FALSE);
    glClearColor(1, 1, 1, 1);
};

bool Win::draw() {
    glfwMakeContextCurrent(this->win);
    glfwSwapBuffers(this->win);
    glfwPollEvents();

    glClear(GL_COLOR_BUFFER_BIT);
    // drawing
    /*
    glBegin(GL_POLYGON);
        glVertex3f(-1, -1, 0); 
        glVertex3f(1, -1, 0); 
        glVertex3f(1, 1, 0); 
    glEnd();
    */
    // ...
    for(int i=0; i<this->Nax; i++) {
        this->axs[i]->draw();
    };

    glfwGetFramebufferSize(this->win, &this->w, &this->h);
    glViewport(0, 0, this->w, this->h);

    return !glfwWindowShouldClose(this->win);
};

void Win::key_callback(GLFWwindow* win, int key, int scancode, int action, int mods) {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(win, GLFW_TRUE);
    // destroy instance??
};

Win::~Win() {
    for(int i=0; i<this->Nax; i++)
        delete axs[i];
    delete[] axs;

    glfwDestroyWindow(this->win);
};
