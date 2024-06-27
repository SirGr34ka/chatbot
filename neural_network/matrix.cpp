#include <iostream>
#include "matrix.h"

Matrix::Matrix()
{
    rows = 2;
    columns = 2;

    matrix = new int* [rows];
        
    for (size_t i = 0; i < rows; ++i)
    {
        matrix[i] = new int [columns]{};
    }
}

Matrix::Matrix(const int& m, const int& n)
{
    rows = m;
    columns = n;

    matrix = new int* [rows];
        
    for (size_t i = 0; i < rows; ++i)
    {
        matrix[i] = new int [columns]{};
    }
}

Matrix::Matrix(Matrix& copied_matrix)
{
    rows = copied_matrix.getRows();
    columns = copied_matrix.getColumns();

    matrix = new int* [rows];
        
    for (size_t i = 0; i < rows; ++i)
    {
        matrix[i] = new int [columns];
    }

    *this = copied_matrix;
}

int** Matrix::getMatrix()
{
    return matrix;
}

int Matrix::getRows()
{
    return rows;
}

int Matrix::getColumns()
{
    return columns;
}

int Matrix::max()
{
    const size_t m = rows;
    const size_t n = columns;
    int max_num = **matrix;

    for (size_t i = 0; i < m; ++i)
    {
        int* row = matrix[i];

        for (size_t j = 0; j < n; ++j)
        {
            max_num = row[j] > max_num ? row[j]: max_num;
        }
    }

    return max_num;
}

int Matrix::dotProduct(Matrix& input_matrix, const size_t& row_offset = 0, const size_t& column_offset = 0)
{
    int res = 0;

    const size_t m = input_matrix.getRows();
    const size_t n = input_matrix.getColumns();
    int** input_matrix_ptr = input_matrix.getMatrix();

    for (size_t i = 0; i < m; ++i)
    {
        int* row = matrix[i + row_offset];
        int* input_row = input_matrix_ptr[i];

        for (size_t j = 0; j < n; ++j)
        {
            res += row[j + column_offset] * input_row[j];
        }
    }

    return res;
}

Matrix Matrix::getPatch(Matrix& input_matrix, const size_t& row_offset = 0, const size_t& column_offset = 0)
{
    const size_t m = rows;
    const size_t n = columns;
    int** input_matrix_ptr = input_matrix.getMatrix();

    for (size_t i = 0; i < m; ++i)
    {
        int* row = matrix[i];
        int* input_row = input_matrix_ptr[i + row_offset];

        for (size_t j = 0; j < n; ++j)
        {
            row[j] = input_row[j + column_offset];
        }
    }

    return *this;
}

Matrix Matrix::operator + (Matrix right_matrix)
{
    const size_t m = rows;
    const size_t n = columns;
    int** right_matrix_ptr = right_matrix.getMatrix();

    for (size_t i = 0; i < m; ++i)
    {
        int* right_row = right_matrix_ptr[i];
        int* left_row = matrix[i];

        for (size_t j = 0; j < n; ++j)
        {
            right_row[j] += left_row[j];
        }
    }

    return right_matrix;
}

Matrix Matrix::operator - (Matrix right_matrix)
{
    const size_t m = rows;
    const size_t n = columns;
    int** right_matrix_ptr = right_matrix.getMatrix();

    for (size_t i = 0; i < m; ++i)
    {
        int* right_row = right_matrix_ptr[i];

        for (size_t j = 0; j < n; ++j)
        {
            right_row[j] = ~right_row[j] + 1;
        }
    }

    return *this + right_matrix;
}

Matrix Matrix::operator * (const int& right_num)
{
    const size_t m = rows;
    const size_t n = columns;

    Matrix left_matrix = *this;
    int** left_matrix_ptr = left_matrix.getMatrix();

    for (size_t i = 0; i < m; ++i)
    {
        int* left_row = left_matrix_ptr[i];

        for (size_t j = 0; j < n; ++j)
        {
            left_row[j] *= right_num;
        }
    }

    return left_matrix;
}

Matrix Matrix::operator * (Matrix& right_matrix)
{
    const size_t m = rows;
    const size_t n = right_matrix.getColumns();
    const size_t k = columns;
    int** right_matrix_ptr = right_matrix.getMatrix();

    Matrix result_matrix(m, n);
    int** result_matrix_ptr = result_matrix.getMatrix();

    for (size_t i = 0; i < m; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            for (size_t s = 0; s < k; ++s)
            {
                result_matrix_ptr[i][j] += matrix[i][s] * right_matrix_ptr[s][j];
            }
        }
    }

    return result_matrix;
}

Matrix& Matrix::operator = (Matrix& right_matrix)
{
    const size_t m = rows;
    const size_t n = columns;
    int** right_matrix_ptr = right_matrix.getMatrix();

    for (size_t i = 0; i < m; ++i)
    {
        int* left_row = matrix[i];
        int* right_row = right_matrix_ptr[i];

        for (size_t j = 0; j < n; ++j)
        {
            left_row[j] = right_row[j];
        }
    }

    return *this;
}

bool Matrix::operator == (Matrix& right_matrix)
{
    const size_t m = rows;
    const size_t n = columns;

    Matrix temp_matrix = *this - right_matrix;
    int** temp_matrix_ptr = temp_matrix.getMatrix();

    for (size_t i = 0; i < m; ++i)
    {
        int* temp_row = temp_matrix_ptr[i];

        for (size_t j = 0; j < n; ++j)
        {
            if (temp_row[j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

Matrix::~Matrix()
{
    for (size_t i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

std::ostream& operator << (std::ostream &os, Matrix& matrix)
{
    const size_t m = matrix.getRows();
    const size_t n = matrix.getColumns();
    int** matrix_ptr = matrix.getMatrix();

    for (size_t i = 0; i < m; ++i)
    {
        int* row = matrix_ptr[i];

        for (size_t j = 0; j < n; ++j)
        {
            os << row[j] << " ";
        }

        os << std::endl;
    }

    return os;
}

std::istream& operator >> (std::istream &is, Matrix& matrix)
{
    const size_t m = matrix.getRows();
    const size_t n = matrix.getColumns();
    int** matrix_ptr = matrix.getMatrix();

    for (size_t i = 0; i < m; ++i)
    {
        int* row = matrix_ptr[i];

        for (size_t j = 0; j < n; ++j)
        {
            is >> row[j];
        }
    }

    return is;
}