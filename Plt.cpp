#include "Plt.h"

Plt::Plt(Ax* ax) {
    this->ax = ax;
};

Plt::~Plt() {
    
};


// PltXY
void PltXY::setData(float* Y, float* X) {
    this->X = X; this->Y = Y;
};

PltXY::~PltXY() {
    if(this->X)
        delete[] X;
    if(this->Y)
        delete[] Y;
};
// ----
