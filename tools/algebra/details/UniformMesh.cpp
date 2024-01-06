#include "../UniformMesh.h"

#include <iostream>

//basic Constuctor
UniformMesh::UniformMesh()
{
    this->n = 10;
    this->start = 0.0;
    this->end = 1.0;
    this->h =  0.1;
}

//Classic Constructor
UniformMesh::UniformMesh(float start, float end, int n)
{
    this->n = n;
    this->start = start;
    this->end = end;
    this->h = (end - start) / n;
}


void UniformMesh::mesh_calculate()
{
    for(size_t i = 0; i < n; i++)
    {
        mesh[i] = this->start + i * this->h;
    }
}

void UniformMesh::print_mesh()
{
    //call mesh_initializing

    //TODO: Check if mesh - array is filled, we dont need to fill them again

    mesh_calculate();

    for(int i = 0; i < n; i++)
    {
        if(i % 5 == 0)
        {
            std::cout << std::endl;
        }

        std::cout << mesh[i] << ",\t"; 
    }
}