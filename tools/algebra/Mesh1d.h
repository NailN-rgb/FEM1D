#ifndef MESH1D_H
#define MESH1D_H

class Mesh1d
{
public:
    int n; //number of mesh points
    float start;
    float end;
    float* mesh;

public:
    Mesh1d();
    Mesh1d(float start, float end, int n);

public:
    void mesh_info();

private:

};

#endif