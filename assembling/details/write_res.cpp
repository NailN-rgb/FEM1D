#include "../fe_method.h"
#include <fstream>

void FEM::results_write(bool write)
{
    if(write)
    {
        std::ofstream str;

        str.open("../data/data.txt");

        if(str.is_open())
        {
            // boundary conditions locate
            for(int i = 0; i < mesh.n; i++)
            {
                str << mesh.mesh[i] << '\t' << solution[i] << std::endl;
            }

            str.close();

            std::cout << "Data writed" << std::endl;
        }
        else
        {
            std::cout << "File is not opened" << std::endl;
        }
    }
    else
    {

    }
}