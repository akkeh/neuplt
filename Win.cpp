#include "Win.h"

int Win::addAx(int r0, int c0, int rN, int cN) {
    // check out of bounds
    //if((r0+R)>rows || (c0+C)>cols) {
    //    return -1;
    //}
    float x0 = -1+this->marg_w+this->col_w*((float)c0)+((float)c0>0)*this->col_sep/2;
    float y0 = -1+this->marg_h+this->row_h*((float)r0)+((float)r0>0)*this->row_sep/2;
    float xN = x0 + this->col_w*((float)(cN-c0))-((float)(cN-c0)<this->cols)*this->col_sep/2; 
    float yN = y0 + this->row_h*((float)(rN-r0))-((float)(rN-r0)<this->rows)*this->row_sep/2;
    std::cout << "x0, y0: " << x0 << ", " << y0;
    std::cout << "xN, yN: " << xN << ", " << yN << std::endl;

    Ax* nax = new Ax(x0, y0, xN, yN);
    Ax** tax = this->axs;
    this->axs = new Ax*[this->Nax+1];
    for(int i=0; i<this->Nax; i++)
        this->axs[i] = tax[i];
    this->axs[this->Nax] = nax;
    this->Nax++;
    return 0;
};

Win::Win(int w, int h, int rows, int cols) {
    this->w = w; this->h = h;

    this->rows = rows; this->cols = cols;
    this->marg_w = 0.1; this->marg_h = 0.1;
    this->col_w = (2-2*this->marg_w) / ((float)this->cols); //(w-2*this->bw) / this->rows;
    this->row_h = (2-2*this->marg_h) / ((float)this->rows); //(h-2*this->bh) / this->cols;
    if(rows > 1) {
        this->row_sep = .1*this->row_h;
    } else
        this->row_sep = 0;

    if(cols > 1) {
        this->col_sep = .1*this->col_w;
    } else
        this->col_sep = 0;



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
    if(this->axs) {
        for(int i=0; i<this->Nax; i++)
            delete axs[i];
        delete[] axs;
    };

    glfwDestroyWindow(this->win);
};
