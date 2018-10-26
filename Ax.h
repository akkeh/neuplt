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

class Ax {
public:
    float x0, y0; //  top left 
    float xN, yN; //  bottom right

    Plt** plts;

    Ax(float x0, float y0, float xN, float yN);
    ~Ax();
    int draw();
    int addPlt();
};
#endif
