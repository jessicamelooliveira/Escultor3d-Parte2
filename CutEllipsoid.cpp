#include "CutEllipsoid.h"

CutEllipsoid::CutEllipsoid(int xcenter_, int ycenter_, int zcenter_, int rx_, int ry_, int rz_){
    this->xcenter_=xcenter_;
    this->ycenter_=ycenter_;
    this->zcenter_=zcenter_;
    this->rx_=rx_;
    this->ry_=ry_;
    this->rz_=rz_;
}

void CutEllipsoid::draw(Sculptor &t){
    float newx, newy, newz;

    for (int x = 0; x <t.getx(); x++){
        for (int y = 0; y < t.gety(); y++){
            for (int z = 0; z <t.getz(); z++){
                newx = ((float)(x-xcenter_)*(float)(x-xcenter_))/(rx_ * rx_);
                newy = ((float)(y-ycenter_)*(float)(y-ycenter_))/(ry_ * ry_);
                newz = ((float)(z-zcenter_)*(float)(z-zcenter_))/(rz_ * rz_);

                if ((newx + newy + newz) < 1)
                    t.cutVoxel(x,y,z);
            }
        }
    }
}
