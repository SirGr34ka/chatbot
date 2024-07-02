#include "neuro.h"

Neuro::Neuro(int ideal, double output)
{
    this->delta_output = (ideal - output) * ((1 - output) * output);
}

void Neuro::DeltaHidden(int ideal, std::vector<double>& hidden, Matrix& hidden_output)
{
    for (int j = 0; j < hidden_output.getColumns(); j++)
    {
        for (int f = 0; f < hidden.size(); f++)
            delta_hidden_[0][f] = ((ideal - hidden[f]) * hidden[f]) * (hidden_output[f][j] * delta_output);
    }
}

void Neuro::DeltaHiddenOutput(Matrix& hidden_output_weights, std::vector<double>& delta_hidden, double E, double alpha)
{
    for (int i = 0; i < hidden_output_weights.getRows(); i++)
    {
        for (int j = 0; j < hidden_output_weights.getColumns(); j++)
        {
            delta_hidden_output[i][j] = hidden_output_weights[i][j] + E * delta_hidden[i] * delta_output + alpha * delta_hidden_output[i][j];
        }
    }
}

void Neuro::DeltaHiddenInput(Matrix& input_hidden_weights, std::vector<double>& input, double E, double alpha)
{
    for (int i = 0; i < input_hidden_weights.getRows(); i++)
    {
        for (int f = 0; f < input_hidden_weights.getColumns(); f++)
        {
            delta_hidden_input[i][f] = input_hidden_weights[i][f] + E * input[i] * delta_hidden_[0][f] + delta_hidden_input[i][f] * alpha;
        }
    }
}

void Neuro::deltsOutput()
{
    std::cout << "Output neuron delta: " << std::endl;
    std::cout << "O1 = " << delta_output << std::endl;

    std::cout << "Hidden neuron delts: " << std::endl;
    std::cout << "H1 = " << delta_hidden_[0][0] << std::endl;
    std::cout << "H2 = " << delta_hidden_[0][1] << std::endl;

    std::cout << "Hidden to output delts of weighs:" << std::endl;
    std::cout << "wH1 = " << delta_hidden_output[0][0] << std::endl;
    std::cout << "wH2 = " << delta_hidden_output[1][0] << std::endl;

    std::cout << "Input to hidden delts of weighs:" << std::endl;
    std::cout << "wI1_1 = " << delta_hidden_input[0][0] << std::endl;
    std::cout << "wI1_2 = " << delta_hidden_input[0][1] << std::endl;
    std::cout << "wI2_1 = " << delta_hidden_input[1][0] << std::endl;
    std::cout << "wI2_2 = " << delta_hidden_input[1][1] << std::endl;

    return;
}