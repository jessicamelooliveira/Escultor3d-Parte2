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
            else if(s.compare("reta") == 0){
                float x1, y1, x2, y2;
                fin >> x1 >> y1 >> x2 >> y2;
                figuras.push_back(
                    new Reta(x1,y1,x2,y2));
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
