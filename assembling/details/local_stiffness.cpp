#include "../fe_method.h"
//#include "../../tools/calculus/integration.cpp"

void quad1_stiffness(
    Equation &eq,                            // equation coefs
    std::vector<std::vector<float>> &local,  // local matrix
    float start,                             // elem left end
    float end                                // elem right end
)                               
{
    // integration by central quad rule
    
    float h = end - start;

    float quad_point = start + h / 2;

    float p = eq.get_p(quad_point);
    float r = eq.get_q(quad_point);
    float s = eq.get_s(quad_point);
    float q = eq.get_q(quad_point);

    local[0][0] =  p - r - s + q;
    local[0][1] = -p - r + s + q;
    local[1][0] = -p + r - s + q;
    local[1][1] =  p + r + s + q;
}

void FEM::fill_local_stiffness(int elem)
{
    float start = mesh.mesh[elem];
    float end = mesh.mesh[elem + 1];
    
    // integration algorithms in ../../calculus/integration.cpp file

    quad1_stiffness(eq, K_local, start, end);
}