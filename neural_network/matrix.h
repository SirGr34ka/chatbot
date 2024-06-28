#pragma once

#include <iostream>

class Matrix
{
    size_t rows;
    size_t columns;

    public:
    
    double** matrix;

    // Конструкторы
    Matrix(const int m, const int n);

    // Конструктор копирования
    Matrix(Matrix& copied_matrix);

    // Гетеры
    size_t getRows() const;
    size_t getColumns() const;

    // Перегрузка операторов
    Matrix operator * (Matrix& right_matrix);
    Matrix& operator = (Matrix& right_matrix);

    // Деструктор
    ~Matrix();
};

// Переопределение операторов вывода
std::ostream& operator << (std::ostream& os, Matrix& matrix);
std::istream& operator >> (std::istream& is, Matrix& matrix);