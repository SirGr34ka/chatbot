#include <iostream>
#include "matrix.h"

Matrix::Matrix( const size_t& m, const size_t& n )
{
    rows = m;
    columns = n;

    matrix = new double* [ rows ];
        
    for ( size_t i = 0 ; i < rows ; ++i )
    {
        matrix[i] = new double [ columns ]{};
    }
}

Matrix::Matrix( Matrix& copied_matrix )
{
    rows = copied_matrix.rows;
    columns = copied_matrix.columns;

    matrix = new double* [ rows ];
    
    for ( size_t i = 0 ; i < rows ; ++i )
    {
        matrix[i] = new double [ columns ];
    }

    *this = copied_matrix;
}

Matrix Matrix::operator * ( Matrix& right_matrix )
{
    const size_t m = rows;
    const size_t n = right_matrix.columns;
    const size_t k = columns;
    double** right_matrix_ptr = right_matrix.matrix;

    Matrix result_matrix( m , n );
    double** result_matrix_ptr = result_matrix.matrix;

    for ( size_t i = 0 ; i < m ; ++i )
    {
        for ( size_t j = 0 ; j < n ; ++j )
        {
            for ( size_t s = 0 ; s < k ; ++s )
            {
                result_matrix_ptr[i][j] += matrix[i][s] * right_matrix_ptr[s][j];
            }
        }
    }

    return result_matrix;
}

Matrix& Matrix::operator = ( Matrix& right_matrix )
{
    const size_t m = rows;
    const size_t n = columns;
    double** right_matrix_ptr = right_matrix.matrix;

    for ( size_t i = 0 ; i < m ; ++i )
    {
        double* left_row = matrix[i];
        double* right_row = right_matrix_ptr[i];

        for ( size_t j = 0 ; j < n ; ++j )
        {
            left_row[j] = right_row[j];
        }
    }

    return *this;
}

Matrix::~Matrix()
{
    for ( size_t i = 0 ; i < rows ; ++i )
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

std::ostream& operator << ( std::ostream &os , Matrix& matrix )
{
    const size_t m = matrix.rows;
    const size_t n = matrix.columns;
    double** matrix_ptr = matrix.matrix;

    for ( size_t i = 0 ; i < m ; ++i )
    {
        double* row = matrix_ptr[i];

        for ( size_t j = 0 ; j < n ; ++j )
        {
            os << row[j] << " ";
        }

        os << std::endl;
    }

    return os;
}

std::istream& operator >> (std::istream &is, Matrix& matrix)
{
    const size_t m = matrix.rows;
    const size_t n = matrix.columns;
    double** matrix_ptr = matrix.matrix;

    for ( size_t i = 0 ; i < m ; ++i )
    {
        double* row = matrix_ptr[i];

        for ( size_t j = 0 ; j < n ; ++j )
        {
            is >> row[j];
        }
    }

    return is;
}