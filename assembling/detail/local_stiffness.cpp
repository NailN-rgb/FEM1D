#include "../fe_method.h"

std::vector<std::vector<float>> FEM::fill_local_stiffness(int elem)
{
    float start = mesh.mesh[elem];
    float end = mesh.mesh[elem + 1];
    
    // integration algorithms in ../../calculus/integration.cpp file

    
    
}