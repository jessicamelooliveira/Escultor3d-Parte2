#include "CutVoxel.h"

CutVoxel::Cutvoxel(int x, int y, int z){
    this->x=x; 
    this->y=y; 
    this->z=z;
}

CutVoxel::~CutVoxel(){}

void CutVoxel::draw(Sculptor &t){
    t.cutVoxel(x, y, z);
}
