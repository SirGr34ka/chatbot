#include <iostream>
#include "matrix.h"

Matrix::Matrix( const int m, const int n )
{
    rows = m;
    columns = n;

    matrix = new double* [ rows ];
        
    for ( int i = 0 ; i < rows ; ++i )
    {
        matrix[i] = new double [ columns ]{0};
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

size_t Matrix::getRows() const
{
    return rows;
}

size_t Matrix::getColumns() const
{
    return columns;
}

Matrix Matrix::operator * ( Matrix& right_matrix )
{
    if ( columns != right_matrix.rows )
    {
        throw "Left matrix columns not equal right matrix rows!";
    }

    const size_t m = rows;
    const size_t n = right_matrix.columns;
    const size_t k = columns;

    Matrix result_matrix( m , n );

    for ( size_t i = 0 ; i < m ; ++i )
    {
        for ( size_t j = 0 ; j < n ; ++j )
        {
            for ( size_t s = 0 ; s < k ; ++s )
            {
                result_matrix[i][j] += matrix[i][s] * right_matrix[s][j];
            }
        }
    }

    return result_matrix;
}

std::vector<double> Matrix::operator * (std::vector<double>& right_vector)
{
    if (rows != right_vector.size())
    {
        throw "Right vector columns not equal left matrix rows!";
    }

    const size_t n = columns;
    const size_t k = rows;

    std::vector<double> result_vector(n);

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < k; ++j)
        {
            result_vector[i] += right_vector[j] * matrix[j][i];
        }
    }

    return result_vector;
}

Matrix& Matrix::operator = ( Matrix& right_matrix )
{
    if ( ( rows != right_matrix.rows ) || ( columns != right_matrix.columns ) )
    {
        throw "Rows or columns of both matrices are not equal!";
    }
    
    const size_t m = rows;
    const size_t n = columns;

    for ( size_t i = 0 ; i < m ; ++i )
    {
        for ( size_t j = 0 ; j < n ; ++j )
        {
            matrix[i][j] = right_matrix[i][j];
        }
    }

    return *this;
}

double*& Matrix::operator [] ( const size_t index )
{
    return matrix[ index ];
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
    const size_t m = matrix.getRows();
    const size_t n = matrix.getColumns();

    for ( size_t i = 0 ; i < m ; ++i )
    {
        for ( size_t j = 0 ; j < n ; ++j )
        {
            os << matrix[i][j] << " ";
        }

        os << std::endl;
    }

    return os;
}

std::istream& operator >> (std::istream &is, Matrix& matrix)
{
    const size_t m = matrix.getColumns();
    const size_t n = matrix.getRows();

    for ( size_t i = 0 ; i < m ; ++i )
    {
        for ( size_t j = 0 ; j < n ; ++j )
        {
            is >> matrix[i][j];
        }
    }

    return is;
}