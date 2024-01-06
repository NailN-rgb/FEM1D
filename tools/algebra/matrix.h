#include <iostream>

//work only with float type
//only rectangle matrices

class Matrix
{
public:
    unsigned int size;
    float **matrix;

public:
    //initializing free matrix
    Matrix();
    Matrix(unsigned int size);

public:
    //destruct
    ~Matrix();

public:
    //set zero values on matrix(for escaping non-initialized memory error)
    void set_zeros();

    void set_value(unsigned int i, unsigned int j, float value);
    float get_value(unsigned int i, unsigned int j);
    
    void matrix_display();
    void non_zero_elements();
};