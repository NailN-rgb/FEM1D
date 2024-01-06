#include <cmath>
#include <../init_equation/equation.h>

void quadpoint
(Equation &eq,                           // equation coefs
std::vector<std::vector<float>> &local,  // local matrix
float start,                             // elem left end
float end)                               // elem right end
{
    // integration by central quad rule
    
    float h = end - start;

    float point = start + h / 2;


}
