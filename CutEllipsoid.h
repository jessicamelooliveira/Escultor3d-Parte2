#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "FiguraGeometrica.h"

class CutEllipsoid : public FiguraGeometrica {
    int xcenter_, ycenter_, zcenter_, rx_, ry_, rz_;
public:
    CutEllipsoid(int xcenter_, int ycenter_, int zcenter_, int rx_, int ry_, int rz_);
    ~CutEllipsoid(){};
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
