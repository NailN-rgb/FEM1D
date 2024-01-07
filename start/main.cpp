#include <iostream>
#include "../assembling/fe_method.h"

int main()
{
    int elements_order = 1;
    int quad_points = 1;

    UniformMesh mesh1d(0, 1, 50);                // set mesh 

    Equation equation(1, 0, 0, 0, 0);            // set equation coeficients
    equation.initialization(false, false, 0, 0.9); // bvp initialization

    FEM finite_elements_method(equation, mesh1d, elements_order, quad_points);
    finite_elements_method.fill_globals();       // assemble system

    finite_elements_method.results_write(true);

    return 0;
}