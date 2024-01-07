#include <iostream>
#include "../assembling/fe_method.h"
#include "../tools/solvers/zeidel.cpp"

int main()
{
    int elements_order = 1;
    int quad_points = 1;

    UniformMesh mesh1d(0, 1, 100);                // set mesh 

    Equation equation(1, 0, 0, 0, 0);            // set equation coeficients
    equation.initialization(false, false, 0, 1); // bvp initialization

    FEM finite_elements_method(equation, mesh1d, elements_order, quad_points);
    finite_elements_method.fill_globals();       // assemble system

    

    

    

    return 0;
}