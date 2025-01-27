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
            else if(s.compare("putsphere") == 0){
                int xcenter, ycenter, zcenter, radius;
                float r, g, b, a;
                fin >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                figuras.push_back(
                    new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
            }
            else if(s.compare("putvoxel") == 0){
                int x, y, z;
                float r, g, b, a;
                fin >> x >> y >> z >> r >> g >> b >> a;
                figuras.push_back(
                    new PutVoxel(x, y, z, r, g, b, a));
            }
            else if(s.compare("cutellipsoid") == 0){
                int xcenter, ycenter, zcenter, rx, ry, rz;
                fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                figuras.push_back(
                    new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
            }
            else if(s.compare("cutsphere") == 0){
                int xcenter, ycenter, zcenter, radius;
                fin >> xcenter >> ycenter >> zcenter >> radius;
                figuras.push_back(
                    new CutSphere(xcenter, ycenter, zcenter, radius));
            }
            else if(s.compare("cutbox") == 0){
                int x0, x1, y0, y1, z0 ,z1;
                fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                figuras.push_back(
                    new CutBox(x0, x1, y0, y1, z0, z1));
            }
            else if(s.compare("cutvoxel") == 0){
                int x, y, z;
                fin >> x >> y >> z;
                figuras.push_back(
                    new CutVoxel(x, y, z));
            }
        }
    }


     for(int i=0; i<figuras.size(); i++){
        figuras[i]->draw();
    }

    for(int i=0; i<figuras.size(); i++){
        delete figuras[i];
    }


    return 0;
}
