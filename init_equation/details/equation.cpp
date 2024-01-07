#include "../equation.h"

Equation::Equation()
{

}

Equation::Equation(float p, float r, float s, float q, float f)
{
    this->p = p;
    this->r = r;
    this->s = s;
    this->q = q;
    this->f = f;

    // standart bvp fill
    this->leftboundary = false;
    this->rightboundary = false;
    this->ua = 0;
    this->ub = 0;
    this->sa = 0;
    this->sb = 0;

    bvp.resize(2, std::vector<float>(3, 0));
    
    bvp_fill();
}

void Equation::initialization(bool leftboundary, bool rightboundary, float ua, float ub, float sa, float sb)
{
    this->leftboundary = leftboundary;
    this->rightboundary = rightboundary;
    this->ua = ua;
    this->ub = ub;
    this->sa = sa;
    this->sb = sb;

    bvp_fill();
}

void Equation::bvp_fill()
{
    // matrix first row filling
    if(!leftboundary)
    {
        bvp[0][0] = 1;
        bvp[0][2] = ua;
    }
    else
    {
        bvp[0][0] = 3;
        bvp[0][1] = sa;
        bvp[0][2] = ua;
    }

    // matrix second row filling
    if(!rightboundary)
    {
        bvp[1][0] = 1;
        bvp[1][2] = ub;
    }
    else
    {
        bvp[1][0] = 3;
        bvp[1][1] = sb;
        bvp[1][2] = ub;
    }

    std::cout << "BVP fill" << std::endl;
}

// TODO:
// вызов функций отвечающих за параметры уравнения можно орагнизовать с использованием ссылок на функции
// т.е. где то в папке start задаются параметрны функциями и их ссылки передаются куда то сюда.
// почему нельзя реализовать это лишь в одном месте? потому что так получается немного ебано 
//                                                                                  и рушится логика классов
// а может можно передавать эти ссылки до квадратур?


float Equation::get_f(float x)  {   return f; }

float Equation::get_p(float x)  {   return p;    }

float Equation::get_r(float x)  {   return r;    }

float Equation::get_s(float x)  {   return s;    }

float Equation::get_q(float x)  {   return q;    }


std::vector<std::vector<float>> Equation::get_bvp()   {   return bvp;   }
