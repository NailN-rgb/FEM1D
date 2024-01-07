#include "../element.h"



Element1D::Element1D(int id, float start, float end, int quadpoints, int elemorder)
{
    this->id = id;
    this->lside = start;
    this->rside = end;
    this->quadpoints = quadpoints;
    this->elemorder = elemorder;
}
