#ifndef CUTBOX_H
#define CUTBOX_H

#include "FiguraGeometrica.h"

<<<<<<< HEAD
class CutBox : public FiguraGeometrica{
=======
class CutBox : public FiguraGeometrica {
>>>>>>> 45e38a930d35edb6585ed10fbfa69fb911b41849
    int x0, x1, y0, y1, z0, z1;
public:
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    ~CutBox(){};
    void draw(Scultor &t);
};

#endif // CUTBOX_H

