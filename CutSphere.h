#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "FiguraGeometrica.h"

class CutSphere : public FiguraGeometrica {

    int xcenter, ycenter, zcenter, radius;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void draw(Sculptor &t);
    ~CutSphere(){};
};

#endif // CUTSPHERE_H
