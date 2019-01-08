#include "Ax.h"

int Ax::addPlt(pltT type, const char* fn, std::vector<const char*> args) {
    Plt** tplts = this->plts;
    this->plts = new Plt*[this->pltN+1];
    for(int i=0; i<this->pltN; i++)
        this->plts[i] = tplts[i];

    Plt* p;
    switch(type) {
        case xy:
            int colX = -1; int colY = 0;
            if(args.size() == 2) {
                colX = atoi(args[0]);
                colY = atoi(args[1]); 
            } else if(args.size() == 1) {
                colY = atoi(args[0]);
                colX = -1;
            };
            p = new PltXY(this, fn, colX, colY);
        break;
    };
    this->plts[this->pltN] = p;
    this->pltN++;
    return 0;
};

int Ax::draw() {
    // draw axis:
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

    for(int i=0; i<this->pltN; i++)
        this->plts[i]->draw();
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
