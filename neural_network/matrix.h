#pragma once

#include <iostream>

class Matrix
{
    public:
    size_t rows;
    size_t columns;
    double** matrix;

    // Конструкторы
    Matrix(const size_t& m, const size_t& n);

    // Конструктор копирования
    Matrix(Matrix& copied_matrix);

    // Перегрузка операторов
    Matrix operator * (Matrix& right_matrix);
    Matrix& operator = (Matrix& right_matrix);

    // Деструктор
    ~Matrix();
};

// Переопределение операторов вывода
std::ostream& operator << (std::ostream& os, Matrix& matrix);
std::istream& operator >> (std::istream& is, Matrix& matrix);