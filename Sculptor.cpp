#include "Sculptor.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

// Construtor da classe
Sculptor::Sculptor(int nx_, int ny_, int nz_){
    nx = nx_;
    ny = ny_;
    nz = nz_;

    // Alocacao dinamica de memoria
    v = new Voxel **[nx];

    for(int i=0; i<nx; i++){
        v[i] = new Voxel *[ny];

        for(int j=0; j<ny; j++){
            v[i][j] = new Voxel[nz];

            // Zerando cores, transparencia e show
            for(int k=0; k<nz; k++){
                v[i][j][k].r = 0;
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
                v[i][j][k].a = 0;
                v[i][j][k].show = false;
            }
        }
    }
}

// Destrutor da classe
Sculptor::~Sculptor(){
    // Liberacao de memoria
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;

    // Zerando cores, transparencia e show
    nx = ny = nz = 0;
    r = g = b = a = 0.0f;
}

// Define a cor atual de desenho
void Sculptor::setColor(float r_, float g_, float b_, float alpha_){
    r = r_;
    g = g_;
    b = b_;
    a = alpha_;
}

// Voxel na posição (x,y,z) // Ativa (show = true) e atribui a cor atual de desenho
void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].show = true;
}

// Voxel na posição (x,y,z) // Desativa (show = false)
void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].show = false;
}

// Voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] // Ativa e atribui a cor atual de desenho
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i=x0; i<=x1; i++){
        for(int j=y0; j<=y1; j++){
            for(int k=z0; k<=z1; k++){
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
                v[i][j][k].show = true;
            }
        }
    }
}

// Voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] // Desativa
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i=x0; i<=x1; i++){
        for(int j=y0; j<=y1; j++){
            for(int k=z0; k<=z1; k++){
                v[i][j][k].show = false;
            }
        }
    }
}

// Voxels que satisfazem à equação da esfera // Ativa e atribui a cor atual de desenho
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i=0; i<=nx; i++){
        for(int j=0; j<=ny; j++){
            for(int k=0; k<=nz; k++){
                float esfera = sqrt(pow((i-xcenter),2) + pow((j-ycenter),2) + pow((k-zcenter),2));
                if(esfera <= radius){
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                    v[i][j][k].show = true;
                }
            }
        }
    }
}

// Voxels que satisfazem à equação da esfera // Desativa
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i=0; i<=nx; i++){
        for(int j=0; j<=ny; j++){
            for(int k=0; k<=nz; k++){
                float esfera = sqrt(pow((i-xcenter),2) + pow((j-ycenter),2) + pow((k-zcenter),2));
                if(esfera <= radius){
                    v[i][j][k].show = false;
                }
            }
        }
    }
}

// Voxels que satisfazem à equação do elipsóide // Ativa e atribui a cor atual de desenho
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float rx2, ry2, rz2;
    rx2 = rx*rx;
    ry2 = ry*ry;
    rz2 = rz*rz;
    for(int i=0; i<=nx; i++){
        for(int j=0; j<=ny; j++){
            for(int k=0; k<=nz; k++){
                float elipsoide = pow((i-xcenter),2)/rx2 + pow((j-ycenter),2)/ry2 + pow((k-zcenter),2)/rz2;
                if(elipsoide <= 1){
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                    v[i][j][k].show = true;
                }
            }
        }
    }
}

// Voxels que satisfazem à equação do elipsóide // Desativa
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float rx2, ry2, rz2;
    rx2 = rx*rx;
    ry2 = ry*ry;
    rz2 = rz*rz;
    for(int i=0; i<=nx; i++){
        for(int j=0; j<=ny; j++){
            for(int k=0; k<=nz; k++){
                float elipsoide = pow((i-xcenter),2)/rx2 + pow((j-ycenter),2)/ry2 + pow((k-zcenter),2)/rz2;
                if(elipsoide <= 1){
                    v[i][j][k].show = false;
                }
            }
        }
    }
}

// Grava a escultura no formato OFF no arquivo filename
void Sculptor::writeOFF(const char *filename){
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        std::cout << "ERRO: Não abriu o arquivo!" << std::endl;
        return;
    }
    fout << "OFF" << std::endl;

    // Contagem do numero de voxels
    int nvoxels = 0;
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].show == true){
                    nvoxels++;
                }
            }
        }
    }

    // NVertices  NFaces  NArestas
    fout << nvoxels*8 << " " << nvoxels*6 << " 0" << std::endl;

    // Escreve os vértices
    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            for (int z = 0; z < nz; z++) {
                if (v[x][y][z].show) {
                    fout << x - 0.5 << " " << y - 0.5 << " " << z - 0.5 << std::endl;
                    fout << x + 0.5 << " " << y - 0.5 << " " << z - 0.5 << std::endl;
                    fout << x + 0.5 << " " << y + 0.5 << " " << z - 0.5 << std::endl;
                    fout << x - 0.5 << " " << y + 0.5 << " " << z - 0.5 << std::endl;
                    fout << x - 0.5 << " " << y - 0.5 << " " << z + 0.5 << std::endl;
                    fout << x + 0.5 << " " << y - 0.5 << " " << z + 0.5 << std::endl;
                    fout << x + 0.5 << " " << y + 0.5 << " " << z + 0.5 << std::endl;
                    fout << x - 0.5 << " " << y + 0.5 << " " << z + 0.5 << std::endl;
                }
            }
        }
    }

    // Escreve as faces
    int voxelFaces = 0;
    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            for (int z = 0; z < nz; z++) {
                if (v[x][y][z].show) {
                    // Define faces para um voxel (mini cubo)
                    fout << "4 " << voxelFaces*8 + 0 << " " << voxelFaces*8 + 1 << " " << voxelFaces*8 + 2 << " " << voxelFaces*8 + 3 << " "
                         << std::fixed << std::setprecision(1) << v[x][y][z].r << " "
                         << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl; // Face inferior
                    fout << "4 " << voxelFaces*8 + 4 << " " << voxelFaces*8 + 5 << " " << voxelFaces*8 + 6 << " " << voxelFaces*8 + 7 << " "
                         << std::fixed << std::setprecision(1) << v[x][y][z].r << " "
                         << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl; // Face superior
                    fout << "4 " << voxelFaces*8 + 0 << " " << voxelFaces*8 + 1 << " " << voxelFaces*8 + 5 << " " << voxelFaces*8 + 4 << " "
                         << std::fixed << std::setprecision(1) << v[x][y][z].r << " "
                         << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl; // Face lateral 1
                    fout << "4 " << voxelFaces*8 + 1 << " " << voxelFaces*8 + 2 << " " << voxelFaces*8 + 6 << " " << voxelFaces*8 + 5 << " "
                         << std::fixed << std::setprecision(1) << v[x][y][z].r << " "
                         << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl; // Face lateral 2
                    fout << "4 " << voxelFaces*8 + 2 << " " << voxelFaces*8 + 3 << " " << voxelFaces*8 + 7 << " " << voxelFaces*8 + 6 << " "
                         << std::fixed << std::setprecision(1) << v[x][y][z].r << " "
                         << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl; // Face lateral 3
                    fout << "4 " << voxelFaces*8 + 3 << " " << voxelFaces*8 + 0 << " " << voxelFaces*8 + 4 << " " << voxelFaces*8 + 7 << " "
                         << std::fixed << std::setprecision(1) << v[x][y][z].r << " "
                         << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl; // Face lateral 4
                    voxelFaces++;
                }
            }
        }
    }
    fout.close();
}
