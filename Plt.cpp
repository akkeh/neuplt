#include "Plt.h"

#include <iostream>

Plt::Plt(Ax* ax) {
    this->ax = ax;
    this->x0 = ax->x0;
    this->y0 = ax->y0;
    this->xN = ax->xN;
    this->yN = ax->yN;
};

Plt::~Plt() {
    
};


// PltXY
void PltXY::setData(int N, float* Y, float* X) {
    this->N = N;
    this->X = X; this->Y = Y;
    if(X) {
        this->Xmin = X[0]; this->Xmax = X[0];
    } else {
        this->Xmin = 0; this->Xmax = N;
    };
    this->Ymin = Y[0]; this->Ymax = Y[0];
    for(int n=0; n<N; n++) {
        if(X) {
            if(X[n] < this->Xmin)
                this->Xmin = X[n];
            if(X[n] > this->Xmax)
                this->Xmax = X[n];   
        }
        if(Y[n] < this->Ymin)
            this->Ymin = Y[n];
        if(Y[n] > this->Ymax)
            this->Ymax = Y[n];
    };
    this->dx = (this->xN-this->x0) / (this->Xmax-this->Xmin);
    this->dy = (this->yN-this->y0) / (this->Ymax-this->Ymin);
};

void PltXY::draw() {
    glColor3f(0, 0, 0);
    float xA, xB, yA, yB;
    glBegin(GL_LINES);
        for(int n=0; n<this->N-1; n++) {
            if(this->X) {
                xA = this->X[n] * this->dx;
                xB = this->X[n+1] * this->dx;
            } else {
                xA = n * this->dx;
                xB = (n+1) * this->dx;
            };
            glVertex2f(
                this->x0+(xA-this->Xmin), 
                this->y0+(this->Y[n]-this->Ymin)*dy
            );
            glVertex2f(
                this->x0+(xB-this->Xmin), 
                this->y0+(this->Y[n+1]-this->Ymin)*dy
            );
        };
    glEnd();
};

PltXY::~PltXY() {
    if(this->X)
        delete[] X;
    if(this->Y)
        delete[] Y;
};
// ----
