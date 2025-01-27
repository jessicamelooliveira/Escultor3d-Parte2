#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"

class PutSphere : public FiguraGeometrica
{
    int xcenter, ycenter, zcenter, radius;
public:
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    void draw(Scultor &t);
    ~PutSphere(){};
};

#endif // PUTSPHERE_H
