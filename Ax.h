#ifndef AX_H
#define AX_H

#include <GLFW/glfw3.h>
#include <vector>

#include "Plt.h"    
#include "Win.h"    

/*  x0
  y0|-------------------|
    |                   |
    |                   |
    |-------------------|yN
*/                  // xN
class Plt;
class Win;

enum pltT { xy };

class Ax {
public:
    Win* win;
    float x0, y0; //  top left 
    float xN, yN; //  bottom right

    int pltN;
    Plt** plts;

    Ax(Win* win, float x0, float y0, float xN, float yN);
    ~Ax();
    int draw();
    int addPlt(pltT type, const char* fn, std::vector<const char*> args);
};
#endif
