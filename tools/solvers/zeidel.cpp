#include<cmath>
#include <iostream>
#include <vector>

float norm(float* oldsolution, float *newsolution, int size)
{
    long squaresum = 0;

    for(int i = 0; i < size; i++) { squaresum += pow(oldsolution[i] - newsolution[i], 2); }

    return sqrt(squaresum); 
}

void zeidel_method(
    float* solution, 
    std::vector<std::vector<float>> matrix,
    std::vector<float> rhs, 
    int size, 
    float tol, 
    float itercount)
{
    int iters = 0;

    for(int i = 0; i < size; i++) { solution[i] = 0.0f;} //start approximation

    float *oldsolution = new float[size];   

    do
    {
        for(int i = 0; i < size; i++)
        {
            oldsolution[i] = solution[i];
        }

        for(int i = 0; i < size; i++)
        {
            float temp = 0;
            for(int j = 0; j < size; j++)
            {
                if(i != j)
                {
                    temp += (matrix[i][j] * solution[j]);
                }
            }

            solution[i] = (rhs[i] - temp)/matrix[i][i]; 
        }

        iters++;
    }
    while (norm(oldsolution, solution, size) > tol || iters < itercount);

    if(iters == itercount)
    {
        std::cout << "Iteration overflow" << std::endl;
    }

}