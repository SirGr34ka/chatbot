#pragma once
#include <iostream>
#include "matrix.h"
#include <math.h>
#include <vector>

class Neuro
{
    public:
        double delta_output;
        std::vector<std::vector<double>> delta_hidden{0};
        std::vector<std::vector<double>> delta_hidden_output{0};
        std::vector<std::vector<double>> delta_hidden_input{0};

        Neuro(int ideal, double output)
        {
            this->delta_output = (ideal - output)*((ideal - output)*output);
        }

        void DeltaHidden(int ideal, Matrix hidden, Matrix hidden_output)
        {
            for (int i = 0; i < hidden.getRows(); i++)
            {
                for (int j = 0; i < hidden.getColumns(); j++)
                {
                    delta_hidden[i][j] = ((ideal - hidden.matrix[i][j]) * hidden.matrix[i][j])*(hidden_output.matrix[j][i]*delta_output);
                }
            }
        }

        void DeltaHiddenOutput(Matrix hidden_output_weights, Matrix delta_hidden, int E, int alpha)
        {
            for (int i = 0; i < hidden_output_weights.getRows(); i++)
            {
                for (int j = 0; i < hidden_output_weights.getColumns(); j++)
                {
                    int grad = delta_hidden.matrix[i][j]*delta_output;
                    delta_hidden_output[i][j] = E*grad;
                }
            }
        }

};