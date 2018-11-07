#ifndef PLT_H
#define PLT_H

#include <fstream>

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

    const char* fn;
    std::string sep = "\t";
    std::ifstream file;

    int N;  // # of points
    int n;  // current plotted point

    std::string getCol(std::string line, std::string sep, int col);
    virtual void readData() = 0;
    virtual void setData(int N) = 0;
    virtual void draw() = 0;

    Plt(Ax* ax, const char* fn);
    ~Plt();
};  // class Plt

class PltXY : public Plt {
public:
    int colX, colY;

    float* X;
    float* Y;
    float Xmin, Ymin, Xmax, Ymax;
    float dx, dy;
    
    PltXY(Ax* ax, const char* fn, int colX=0, int colY=1);
    ~PltXY();
    void readData();
    void setData(int N);//, float* Y, float* X=NULL);
    void draw();
};  // class PltXY : Plt
#endif
