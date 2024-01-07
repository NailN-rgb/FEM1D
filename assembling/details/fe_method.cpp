#include "../fe_method.h"

FEM::FEM(Equation eq, UniformMesh mesh, int elem_order, int quad)
{
    this->eq = eq;
    this->mesh = mesh;
    this->elements_order = elem_order;
    this->quad = quad;

    int dof = 2 * elements_order;

    K_local.resize(dof, std::vector<float>(dof, 0));  
    K.resize(mesh.n, std::vector<float>(mesh.n, 0));

    F_local.resize(dof, 0);
    F.resize(mesh.n, 0);
}

void FEM::stiffness_display()
{
    int size = mesh.n;
    std::vector<std::vector<float>> bvp = eq.get_bvp();

    if(bvp[0][0] == 1)  {   size--; }
    if(bvp[1][0] == 1)  {   size--; }

    std::cout << "\nStiffness matrix" << std::endl;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            std::cout << K[i][j] << "\t";
        }   

        std::cout << std::endl;
    }
}

void FEM::power_display()
{
    int size = mesh.n;
    std::vector<std::vector<float>> bvp = eq.get_bvp();

    if(bvp[0][0] == 1)  {   size--; }
    if(bvp[1][0] == 1)  {   size--; }

    std::cout << "\nForce vector" << std::endl;

    for(int i = 0; i < size; i++)
    {
        std::cout << F[i] << std::endl;
    }
}