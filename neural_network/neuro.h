#pragma once

#include <iostream>
#include <math.h>
#include <vector>

#include "matrix.h"

class Neuro
{
    public:
        double delta_output;
        std::vector<double> delta_hidden_{ 2, 0 };
        Matrix delta_hidden_output{ 2, 1 };
        Matrix delta_hidden_input{ 2, 2 };

        Neuro(int ideal, double output);

        void DeltaHidden(int ideal, std::vector<double>& hidden, Matrix& hidden_output);

        void DeltaHiddenOutput(Matrix& hidden_output_weights, std::vector<double>& delta_hidden, double E, double alpha);

        void DeltaHiddenInput(Matrix& input_hidden_weights, std::vector<double>& input, double E, double alpha);

        // Вывод всех рассчитанных дельт
        void deltsOutput();
};