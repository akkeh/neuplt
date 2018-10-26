#ifndef AX_H
#define AX_H

#include <GLFW/glfw3.h>

#include "Plt.h"    

/*  x0
  y0|-------------------|
    |                   |
    |                   |
    |-------------------|yN
*/                  // xN
class Plt;
enum pltT { xy };
class Ax {
public:
    float x0, y0; //  top left 
    float xN, yN; //  bottom right

    int pltN;
    Plt** plts;

    Ax(float x0, float y0, float xN, float yN);
    ~Ax();
    int draw();
    int addPlt(pltT type);
};
#endif
