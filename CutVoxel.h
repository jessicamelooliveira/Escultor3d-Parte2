#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"

class CutVoxel:public FiguraGeometrica
{
    int x; int y; int z;
public:
    CutVoxel(int x, int y, int z);
    ~CutVoxel();
    void draw(Sculptor &t);
};

#endif 
