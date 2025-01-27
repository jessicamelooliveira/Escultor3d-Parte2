#include "CutSphere.h"

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->radius=radius;
}

void CutSphere::draw(Sculptor &t){
    for(int i = -radius; i<=radius; i++){
        for(int j = -radius; j<=radius; j++){
            for(int k = -radius; k<=radius; k++){
            if ((i*i+j*j+k*k) < radius*radius)
                t.cutVoxel(i+xcenter,j+ycenter,k+zcenter);
            }
        }
    }
}
