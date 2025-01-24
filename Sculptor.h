#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel{
    float r, g, b; // Cores
    float a;       // Transparencia
    bool show;     // Mostrado ou nao
};

class Sculptor{
protected:
    Voxel ***v;       // Matriz 3d
    int nx,ny,nz;   // Dimensoes
    float r,g,b,a; // Cor atual de desenho

public:
    Sculptor(int _nx, int _ny, int _nz);                   // Construtor da classe
    ~Sculptor();                                           // Destrutor da classe
    void setColor(float r, float g, float b, float alpha); // Define a cor atual de desenho

    // Voxel na posição (x,y,z)
    void putVoxel(int x, int y, int z); // Ativa (show = true) e atribui a cor atual de desenho
    void cutVoxel(int x, int y, int z); // Desativa (show = false)

    // Voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1]:
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1); // Ativa e atribui a cor atual de desenho
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); // Desativa

    // Voxels que satisfazem à equação da esfera
    void putSphere(int xcenter, int ycenter, int zcenter, int radius); // Ativa e atribui a cor atual de desenho
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius); // Desativa

    // Voxels que satisfazem à equação do elipsóide
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // Ativa e atribui a cor atual de desenho
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // Desativa

    void writeOFF(const char *filename); // Grava a escultura no formato OFF no arquivo filename
};

#endif // SCULPTOR_H
