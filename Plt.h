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

    Dat dat;
    int N;  // # of points
    int n;  // current plotted point

    void readDat(const char* fn);
    //void setData();
    void draw();

    Plt(Ax* ax);
    ~Plt();
};  // class Plt

class PltXY : public Plt {
public:
    float* X;
    float* Y;
    
    PltXY(Ax* ax) : Plt(ax){};
    ~PltXY();
    void setData(float* Y, float* X=NULL);
};  // class PltXY : Plt
#endif
