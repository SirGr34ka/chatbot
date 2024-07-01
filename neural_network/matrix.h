#pragma once

#include <iostream>
#include <vector>

class Matrix
{
    size_t rows;
    size_t columns;
    double** matrix;

    public:

    // Конструкторы
    Matrix( const int m , const int n );

    // Конструктор копирования
    Matrix( Matrix& copied_matrix );

    // Гетеры
    size_t getRows() const;
    size_t getColumns() const;

    // Перегрузка операторов
    Matrix operator * ( Matrix& right_matrix );
    std::vector<double> operator * (std::vector<double>& right_vector);
    Matrix& operator = ( Matrix& right_matrix );
    double*& operator [] ( const size_t index );

    // Деструктор
    ~Matrix();
};

// Переопределение операторов вывода
std::ostream& operator << ( std::ostream& os , Matrix& matrix );
std::istream& operator >> ( std::istream& is , Matrix& matrix );