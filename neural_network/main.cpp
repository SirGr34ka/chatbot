#include <iostream>

#include "matrix.h"

int main()
{
    size_t rows , columns;

    // Создание и задание первой матрицы
    std::cout << "Input first matrix rows: ";
    std::cin >> rows;
    std::cout << "Input first matrix columns: ";
    std::cin >> columns;

    Matrix first ( rows , columns );

    std::cout << "Input first matrix: ";
    std::cin >> first;

    std::cout << "First matrix:" << std::endl;
    std::cout << first;

    // Создание и задание второй матрицы
    std::cout << "Input second matrix rows: ";
    std::cin >> rows;
    std::cout << "Input second matrix columns: ";
    std::cin >> columns;

    Matrix second ( rows , columns );

    std::cout << "Input second matrix: ";
    std::cin >> second;

    std::cout << "Second matrix:" << std::endl;
    std::cout << second;

    // Создание и задание результирующей матрицы

    Matrix result = first * second;

    std::cout << "Result:" << std::endl;
    std::cout << result;

    return 0;
}