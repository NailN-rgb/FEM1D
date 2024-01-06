#include "../fe_method.h"

FEM::FEM(Equation eq, UniformMesh mesh, int elem_order = 1, int quad = 1)
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