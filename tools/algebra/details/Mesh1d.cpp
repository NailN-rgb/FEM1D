#include "../Mesh1d.h"

#include <iostream>


Mesh1d::Mesh1d()
{
    this->n = 10;
    this->start = 0.0;
    this->end = 1.0;
}

Mesh1d::Mesh1d(float start, float end, int n)
{
    this->n = n;
    this->start = start;
    this->end = end;
}

void Mesh1d::mesh_info()
{
    std::string output = "Here is mesh on segment started on " + std::to_string(start) + 
                        " ended on " + std::to_string(end) + " and have a " + std::to_string(n) + " points";

    std::cout << output << std::endl;
}
