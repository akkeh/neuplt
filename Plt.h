#ifndef PLT_H
#define PLT_H

#include "Ax.h"

class Ax;

class Plt {
public:
    Ax* ax;   

    Plt(Ax* ax);
    ~Plt();
};
#endif
