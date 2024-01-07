#include "../init_equation/equation.h"
#include "../tools/algebra/UniformMesh.h"

class FEM
{
    Equation eq; // copy of given Equation
    UniformMesh mesh; // mesh params

    int elements_order, quad; // elements order and quadrature points number

    std::vector<std::vector<float>> K_local; // local stiffness matrix 
    std::vector<float> F_local; // local power vector

    std::vector<std::vector<float>> K; // global stiffness matrix
    std::vector<float> F; // global power vector

    std::vector<std::vector<float>> bvp;

    float *solution;

public:
    FEM();

    FEM(Equation eq, UniformMesh mesh, int elem_order = 1, int quad = 1);

    void fill_globals();

    void fill_local_stiffness(int elem);

    void fill_local_power(int elem);

    void boundary_conditions();

    void solve();

    void results_write(bool write);


    // testing methods 

    void stiffness_display();
    void power_display();
};