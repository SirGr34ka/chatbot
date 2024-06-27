#pragma once

#include <iostream>

class Matrix
{
    size_t rows;
    size_t columns;
    int** matrix;

    public:

    // Конструкторы
    Matrix();
    Matrix(const int& m, const int& n);

    // Конструктор копирования
    Matrix(Matrix& copied_matrix);

    // Гетеры
    int** getMatrix();
    int getRows();
    int getColumns();

    // Поиск максимального значения
    int max();

    // Скалярное произведение матриц
    int dotProduct(Matrix& right_matrix, const size_t& row_offset, const size_t& column_offset);

    // Часть матрицы
    Matrix getPatch(Matrix& input_matrix, const size_t& row_offset, const size_t& column_offset);

    // Перегрузка операторов
    Matrix operator + (Matrix right_matrix);
    Matrix operator - (Matrix right_matrix);
    Matrix operator * (const int& right_num);
    Matrix operator * (Matrix& right_matrix);
    Matrix& operator = (Matrix& right_matrix);
    bool operator == (Matrix& right_matrix);

    // Деструктор
    ~Matrix();
};

// Переопределение операторов вывода
std::ostream& operator << (std::ostream& os, Matrix& matrix);
std::istream& operator >> (std::istream& is, Matrix& matrix);