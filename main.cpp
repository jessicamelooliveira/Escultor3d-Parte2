#include "CutEllipsoid.h"
#include "CutSphere.h"
#include "CutBox.h"
#include "CutVoxel.h"
#include "PutVoxel.h"
#include "PutBox.h"
#include "PutSphere.h"
#include "PutEllipsoid.h"
#include "Sculptor.h"
#include "FiguraGeometrica.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

int main(){
    FiguraGeometrica *pfig;

    std::vector <FiguraGeometrica*> figuras;

    // Verificar se o arquivo esta aberto corretamente
    std::ifstream fin;
    fin.open("figura.txt");
    if(!fin.is_open()){
        exit(0);
    }

    std::string s;

    while(fin.good()){
        fin >> s;
        if(fin.good()){
            if(s.compare("putbox") == 0){
                int x0, x1, y0, y1, z0, z1;
                float r, g, b, a;
                fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                figuras.push_back(
                    new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
            }
            else if(s.compare("putellipsoid") == 0){
                int xcenter, ycenter, zcenter, rx, ry, rz;
                float r, g, b, a;
                fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                figuras.push_back(
                    new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
            }
            else if(s.compare("circulo") == 0){
                float xc, yc, raio;
                fin >> xc >> yc >> raio;
                figuras.push_back(
                    new Circulo(xc,yc,raio));

            }
        }
    }

    return 0;
}
