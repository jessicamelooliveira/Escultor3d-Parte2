#include "PutEllipsoid.h"
#include "Sculptor.h"
#include "interpretador.h"

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a)
{
    this->xcenter=xcenter; 
    this->ycenter=ycenter; 
    this->zcenter=zcenter; 
    this->rx=rx; 
    this->ry=ry; 
    this->rz=rz;
    this->r=r; 
    this->g=g; 
    this->b=b; 
    this->a=a;
}

void PutEllipsoid::draw(Sculptor &t)
{
    float newx, newy, newz;
    t.setColor(r,g,b,a);

     for (int x = 0; x <t.getx(); x++){
         for (int y = 0; y < t.gety(); y++){
             for (int z = 0; z <t.getz(); z++){
             newx = ((float)(x-xcenter)*(float)(x-xcenter))/(rx * rx);
             newy = ((float)(y-ycenter)*(float)(y-ycenter))/(ry * ry);
             newz = ((float)(z-zcenter)*(float)(z-zcenter))/(rz * rz);

             if ((newx + newy + newz) < 1){
                 t.putVoxel(x,y,z);
             }
             }
         }
     }
 }
