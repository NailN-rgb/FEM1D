#include "../fe_method.h"

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
}