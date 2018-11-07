#include "Plt.h"

#include <iostream>

Plt::Plt(Ax* ax, const char* fn) {
    this->ax = ax;
    this->x0 = ax->x0;
    this->y0 = ax->y0;
    this->xN = ax->xN;
    this->yN = ax->yN;

    this->fn = fn;
};  // Plt::Plt();

std::string Plt::getCol(std::string line, std::string sep, int col) {
    if(col == 0)
        return line.substr(0, line.find(sep));
    else
        return this->getCol(line.substr(line.find(sep)+1, line.find("\n")), sep, col-1);
};
Plt::~Plt() {
    
};  // Plt::~Plt();


// PltXY
PltXY::PltXY(Ax* ax, const char* fn, int colX, int colY) : Plt(ax, fn) {
    this->colX = colX;
    this->colY = colY;
};  // PltXY::PltXY();

void PltXY::readData() {
    std::string line;
    int M = 256; int N = M; int i = 0;

    // init data containers:
    this->X = new float[N];
    this->Y = new float[N];
    this->Xmin = 1E38; this->Xmax = 1E-38;
    this->Ymin = 1E38; this->Ymax = 1E-38;
    float* tX; float* tY;

    if(this->file.is_open())
        this->file.close();
    this->file.open(this->fn);

    while(getline(this->file, line)) {
        if(i >= N) {
            tX = X; tY = Y;
            this->X = new float[N+M];
            this->Y = new float[N+M];
            for(int n=0; n<N; n++) {
                this->X[n] = tX[n];
                this->Y[n] = tY[n];
            }
            N += M;
        };    
        this->X[i] = atof(this->getCol(line, this->sep, this->colX).c_str());
        this->Y[i] = atof(this->getCol(line, this->sep, this->colY).c_str());
        this->Xmin = std::min(this->Xmin, this->X[i]);
        this->Xmax = std::max(this->Xmax, this->X[i]);
        this->Ymin = std::min(this->Ymin, this->Y[i]);
        this->Ymax = std::max(this->Ymax, this->Y[i]);
        i++;   
    }
    this->file.close();

    this->N = i;
    this->dx = (this->xN-this->x0) / (this->Xmax-this->Xmin);
    this->dy = (this->yN-this->y0) / (this->Ymax-this->Ymin);
};  // PltXY::readData();

void PltXY::setData(int N) { //, float* Y, float* X) {
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
};  // PltXY::setData();

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
};  // PltXY::draw();

PltXY::~PltXY() {
    if(this->X)
        delete[] X;
    if(this->Y)
        delete[] Y;
};  // PltXY::~PltXY();
// ----
