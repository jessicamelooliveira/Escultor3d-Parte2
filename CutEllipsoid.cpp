#include "CutEllipsoid.h"

CutEllipsoid::CutEllipsoid(int xcenter_, int ycenter_, int zcenter_, int rx_, int ry_, int rz_){
    this->xcenter_=xcenter_;
    this->ycenter_=ycenter_;
    this->zcenter_=zcenter_;
    this->rx_=rx_;
    this->ry_=ry_;
    this->rz_=rz_;
}

CutEllipsoid::~CutEllipsoid(){}

void CutEllipsoid::draw(Sculptor &t){
    t.cutEllipsoid(xcenter_, ycenter_, zcenter_, rx_, ry_, rz_);
}
