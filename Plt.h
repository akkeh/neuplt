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
    void draw();

    Plt(Ax* ax);
    ~Plt();
};  // class Plt

class PltXY : public Plt {
    float* X;
    float* Y;
};  // class PltXY : Plt
#endif
