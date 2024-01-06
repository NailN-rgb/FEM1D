#include<iostream>

class Element1D
{
    unsigned int id;
    float lside, rside; // coordites of left and right ends
    
    unsigned int quadpoints; // quadrature points on element

    unsigned int elemorder; // order of element

public:
    Element1D(int id, float start, float end, int quadpoints, int elemorder = 1);
};