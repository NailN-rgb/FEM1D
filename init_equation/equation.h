#include <iostream>
#include <vector>

class Equation
{
    float p, r, s, q, f;
    bool leftboundary, rightboundary; // if 0 - first BC, else - third
    float ua, ub; // values on sides
    float sa, sb; // values for third bc   

    // ua and ub setted without any control of mesh points...

    // bvp is a matrix size 2x3 where row values is BC type - g_i value - u_i value 
    std::vector<std::vector<float>> bvp; 
public:
    
    Equation();
    Equation(float p, float r, float s, float q, float f);
    
    // call after object init!!
    void initialization
    (
        bool leftboundary, 
        bool rightboundary, 
        float ua, 
        float ub, 
        float sa = 0, 
        float sb = 0
    );

    void bvp_fill();

    // TODO: rewrite later  
    float get_f(float x);
    float get_p(float x);
    float get_r(float x);
    float get_s(float x);
    float get_q(float x);

    std::vector<std::vector<float>> get_bvp();

};