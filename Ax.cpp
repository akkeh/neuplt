#include "Ax.h"

int Ax::addPlt() {
    Plt** tplts = this->plts;
    
    return 0;
};

int Ax::draw() {
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
        glVertex2f(this->x0, this->y0);
        glVertex2f(this->xN, this->y0);

        glVertex2f(this->xN, this->y0);
        glVertex2f(this->xN, this->yN);

        glVertex2f(this->xN, this->yN);
        glVertex2f(this->x0, this->yN);

        glVertex2f(this->x0, this->yN);
        glVertex2f(this->x0, this->y0);
    glEnd();    
    return 0;
};

Ax::Ax(float x0, float y0, float xN, float yN) {
    this->x0 = x0; this->y0 = y0;
    this->xN = xN; this->yN = yN;

    this->plts = NULL;
};


Ax::~Ax() {};
