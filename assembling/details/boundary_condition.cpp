#include "../fe_method.h"

void FEM::boundary_conditions()
{
    std::vector<std::vector<float>> bvp = eq.get_bvp();
    
    if(bvp[0][0] == 3)
    {
        K[0][0] += bvp[0][1];
        F[0]    += bvp[0][2];
    }
    else if(bvp[0][0] == 1)
    {
        K.erase(K.begin());

        for(auto& row : K)
        {
            row.erase(row.begin());
        } 

        F.erase(F.begin());

        for(int i = 0; i < F.size(); i++)
        {
            F[i] -= K[i][0] * bvp[0][2]; 
        }
    }
    else
    {
        std::cout << "left bvp type error";
    }

    if(bvp[1][0] == 3)
    {
        K[mesh.n - 1][mesh.n - 1] += bvp[1][1];
        F[mesh.n - 1]             += bvp[1][2];
    }
    else if(bvp[0][0] == 1)
    {
        int remove_row, remove_col = 0;

        K.erase(K.end() - 1);

        for(auto& row : K)
        {
            row.erase(row.end() - 1);
        } 

        F.erase(F.end() - 1);

        for(int i = 0; i < F.size(); i++)
        {
            F[i] -= K[i][mesh.n - 1] * bvp[1][2]; 
        }
    }
    else
    {
        std::cout << "right bvp type error";
    }

}