#include "../matrix.h"

//initializing free matrix
Matrix::Matrix()
{
    this->size = 0;
};

Matrix::Matrix(unsigned int size)
{
    this->size = size;

    matrix = new float*[size];

    for(size_t i = 0; i < size; i++)
    {
        matrix[i] = new float[size];
    }

    set_zeros();
};

Matrix::~Matrix()
{
    for(size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
}

void Matrix::set_zeros()
{
    unsigned int size = this->size;
    float **matrix = this->matrix;

    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = 0; j < size; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void Matrix::set_value(unsigned int i, unsigned int j, float value)
{
    matrix[i][j] = value;
}

float Matrix::get_value(unsigned int i, unsigned int j)
{
    return matrix[i][j];
}


void Matrix::matrix_display()
{
    if(size > 10)
    {
        std::cout << "Matrix is too big" << std::endl;
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                std::cout << matrix[i][j] << "\t";
            }

            std::cout << std::endl;
        }
    }
}

void Matrix::non_zero_elements()
{

}