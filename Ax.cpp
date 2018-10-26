#include "Ax.h"

int Ax::addPlt(pltT type) {
    Plt** tplts = this->plts;
    this->plts = new Plt*[this->pltN+1];
    for(int i=0; i<this->pltN; i++)
        this->plts[i] = tplts[i];

    Plt* p;
    switch(type) {
        case xy:
            p = new PltXY(this);
        break;
    };
    this->plts[this->pltN] = p;
    this->pltN++;
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

    this->pltN = 0;
    this->plts = NULL;
};


Ax::~Ax() {
    if(this->plts) {
        for(int i=0; i<this->pltN; i++)
           delete this->plts[i];
        delete[] this->plts;
    };
};
