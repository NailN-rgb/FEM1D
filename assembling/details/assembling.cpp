#include "../fe_method.h"
#include "../../tools/solvers/zeidel.cpp"

void FEM::fill_globals()
{
    int elems_count = mesh.n - 1;

    for(int e = 0; e < elems_count; e++)
    {
        fill_local_stiffness(e);    // fill local stiffness matrix
        fill_local_power(e);        // and local power vector

        int idx_i = e; // north - west corner coordinates of local st. matrix
        int idx_j = e; // in terms of global matrix indexes

        // global stiffness matrix assembling
        for(int i = 0; i < elements_order + 1; i++)
        {
            for(int j = 0; j < elements_order + 1; j++)
            {
                K[idx_i + i][idx_j + j] += K_local[i][j];
            } 
        } 

        // global power vector filling
        for(int i = 0; i < elements_order + 1; i++)
        {
            F[idx_i + i] = F_local[i];
        }
    }

    boundary_conditions();
    solve();
}

void FEM::solve()
{
    bool leftBC, rightBC = false;

    if(bvp[0][0] == 1) 
    {    
        leftBC = true;    
    }
    if(bvp[1][0] == 1) 
    {    
        rightBC = true;
    }

    zeidel_method(solution, K, F, mesh.n - leftBC - rightBC, 0.1, 100);

    if(leftBC || rightBC)
    {
        if(leftBC && rightBC)
        {
            float *tempsol = new float[mesh.n - 2];

            for(int i = 0; i < mesh.n - 2; i++)
            {
                tempsol[i] = solution[i];
            }

            solution[0] = bvp[0][2];
            solution[mesh.n - 1] = bvp[1][2];

            for(int i = 1; i < mesh.n - 1; i++)
            {
                solution[i] = tempsol[i-1];
            }
        }
        else if(leftBC)
        {
            float *tempsol = new float[mesh.n - 1];

            for(int i = 0; i < mesh.n - 1; i++)
            {
                tempsol[i] = solution[i];
            }

            solution[0] = bvp[0][2];

            for(int i = 1; i < mesh.n; i++)
            {
                solution[i] = tempsol[i-1];
            }
        }
        else if(rightBC)
        {
            float *tempsol = new float[mesh.n - 1];

            for(int i = 0; i < mesh.n - 1; i++)
            {
                tempsol[i] = solution[i];
            }

            solution[mesh.n - 1] = bvp[1][2];

            for(int i = 0; i < mesh.n - 1; i++)
            {
                solution[i] = tempsol[i-1];
            }
        }
    }
}