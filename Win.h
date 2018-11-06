#ifndef WIN_H 
#define WIN_H

#include <iostream>
#include <GLFW/glfw3.h>

#include "Ax.h"
/*      w
    |---------------------------|
    |  ]   bh                [  |
    |===========================|
 h  |bw] c0 |  |c1  |  |c2  |[bw| 
    |  ] r0 |  |r0  |  |r0  |[  |
    |  ]    |cs|    |cs|    |[  |
    |  ]----|--|----|--|----|[  |
    |  ]      rs             [  |
    |  ]----|--|----|--|----|[  |
    |  ] c0 |  |c1  |  |c2  |[  |
    |  ] r1 |  |r1  |  |r1  |[  |
    |  ]    |  |    |  |    |[  |
    |===========================|
    |  ]   bh                [  |
    |---------------------------|
*/
class Win {
public:
    int w, h;               // width, height
    int rows, cols;         // rows, columns
    float col_w, row_h;     // col width, row height
    int r, c;               // currently filled
    float marg_w, marg_h;   // margin width, height
    float col_sep, row_sep; // col, width separator
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
