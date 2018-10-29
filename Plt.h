#ifndef PLT_H
#define PLT_H

#include "Ax.h"

class Ax;

struct Dat {
    int M;      // # of var.s
    int N;      // length of data
    float** X;  // the data
};  // struct Dat

class Plt {
public:
    Ax* ax;   
    float x0, y0;
    float xN, yN;

    Dat dat;
    int N;  // # of points
    int n;  // current plotted point

    void readDat(const char* fn);
    virtual void draw() = 0;

    Plt(Ax* ax);
    ~Plt();
};  // class Plt

class PltXY : public Plt {
public:
    float* X;
    float* Y;
    float Xmin, Ymin, Xmax, Ymax;
    float dx, dy;
    
    PltXY(Ax* ax) : Plt(ax){};
    ~PltXY();
    void setData(int N, float* Y, float* X=NULL);
    void draw();
};  // class PltXY : Plt
#endif
