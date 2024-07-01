#pragma once
#include <iostream>
#include "matrix.h"
#include <math.h>
#include <vector>

class Neuro
{
    public:
        double delta_output;
        std::vector<std::vector<double>> delta_hidden_{1, std::vector<double>(2, 0)};
        std::vector<std::vector<double>> delta_hidden_output{2, std::vector<double>(1, 0)};
        std::vector<std::vector<double>> delta_hidden_input{2, std::vector<double>(2, 0)};

        Neuro(int ideal, double output)
        {
            this->delta_output = (ideal - output)*( ( 1 - output ) * output );
        }

        void DeltaHidden(int ideal, std::vector<double>& hidden, Matrix& hidden_output)
        {
            for (int j = 0; j < hidden_output.getColumns(); j++)
            {
                for (int f = 0; f < hidden.size(); f++)
                    delta_hidden_[0][f] = ((ideal - hidden[f]) * hidden[f]) * (hidden_output[f][j] * delta_output);
            }
        }

        void DeltaHiddenOutput(Matrix& hidden_output_weights, std::vector<double>& delta_hidden, double E, double alpha)
        {
            for (int i = 0; i < hidden_output_weights.getRows(); i++)
            {
                for (int j = 0; j < hidden_output_weights.getColumns(); j++)
                {
                    delta_hidden_output[i][j] = hidden_output_weights[i][j]+E*delta_hidden[i]*delta_output+alpha*delta_hidden_output[i][j];
                }
            }
        }

        void DeltaHiddenInput(Matrix& input_hidden_weights, std::vector<double>& input, double E, double alpha)
        {
            for (int i = 0; i < input_hidden_weights.getRows(); i++)
            {
                for (int f = 0; f < input_hidden_weights.getColumns(); f++)
                {
                    delta_hidden_input[i][f] = input_hidden_weights[i][f]+E*input[i]*delta_hidden_[0][f]+delta_hidden_input[i][f]*alpha;
                }
            }
        }
};