#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

class FiguraGeometrica {
protected:
    float r, g, b, a;
public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica();
    virtual void draw(Sculptor &t) = 0;
};

#endif // FIGURAGEOMETRICA_H
