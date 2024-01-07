#ifndef UNIFORMMESH
#define UNIFIRMMESH

#include "Mesh1d.h"
#include <vector>

//TODO: Need to add destructors

class UniformMesh : public Mesh1d
{
public:
    int n; //number of mesh points
    float start;
    float end;
    float * mesh;
    float h; //step of the mesh

public:
    UniformMesh();
    UniformMesh(float start, float end, int n);
    
public:
    void mesh_calculate();
    void print_mesh();
};

#endif