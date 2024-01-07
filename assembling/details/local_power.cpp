#include "../fe_method.h"
//#include "../../tools/calculus/integration.cpp"

void quad1_power(
    Equation &eq,
    std::vector<float> local,
    float start,
    float end
)
{
    float h = end - start;
    
    float quad_point = start + h / 2;

    local[0] = local[1] = h/2 * eq.get_f(quad_point);
}

void FEM::fill_local_power(int elem)
{
    float start = mesh.mesh[elem];
    float end = mesh.mesh[elem + 1];
    
    // integration algorithms in ../../calculus/integration.cpp file

    quad1_power(eq, F_local, start, end);
}

