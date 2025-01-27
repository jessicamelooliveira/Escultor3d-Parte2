#include "putsphere.h"

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a)
{
this->xcenter=xcenter; 
this->ycenter=ycenter; 
this->zcenter=zcenter; 
this->radius=radius;
this->r=r; 
this->g=g; 
this->b=b; 
this->a=a;
}

void PutSphere::draw(Scultor &t)
{
    t.setColor(r,g,b,a);

    for(int i = -radius; i<=radius; i++){
        for(int j = -radius; j<=radius; j++){
            for(int k = -radius; k<=radius; k++){

              if ((i*i+j*j+k*k) < radius*radius){
                t.putVoxel(i+xcenter,j+ycenter,k+zcenter);
              }
            }
        }
    }
}
