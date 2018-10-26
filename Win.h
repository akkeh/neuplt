#ifndef NEUPLT_H
#define NEUPLT_H

#include <iostream>
#include <GLFW/glfw3.h>

#include "Ax.h"
/*      w
    |-------------------|
    |  ]   bh        [  |
    |===================|
 h  |bw] c0 |c1 |c2 |[bw| 
    |  ] r0 |r0 |r0 |[  |
    |  ]    |   |   |[  |
    |  ]----|---|---|[  |
    |  ] c0 |c1 |c2 |[  |
    |  ] r1 |r1 |r1 |[  |
    |  ]    |   |   |[  |
    |===================|
    |  ]   bh        [  |
    |-------------------|
*/
class Win {
public:
    int w, h;       // width, height
    int rows, cols; // rows, columns
    float cw, rh;   // col width, row height
    int r, c;       // currently filled
    float bw, bh;     // border width, height
    GLFWwindow* win;
    int Nax;
    Ax** axs;

    Win(int w, int h, int rows, int cols);
    static void key_callback(GLFWwindow* win, int key, int scancode, int action, int mods);
    bool draw(); 
    int addAx(int r0, int c0, int R, int C);
    ~Win();
};

#endif
