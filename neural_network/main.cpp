#include <iostream>
#include <math.h>
#include <vector>

#include "matrix.h"
#include "neuro.h"

double sigmoid( const double value )
{
    return 1 / ( 1 + exp( -value ) );
}

void lay_output(const std::vector<double>& lay)
{
    for (size_t i = 0; i < lay.size(); ++i)
    {
        std::cout << lay[i] << " ";
    }

    std::cout << std::endl;

    return;
}

int main()
{
    // Input neurons
    std::vector<double> input(2);

    input[0] = 1;
    input[1] = 0;

    std::cout << "Input neurons:" << std::endl;
    lay_output(input);

    // Input -> Hidden weights
    Matrix input_hidden_weights ( 2 , 2 );

    input_hidden_weights[0][0] = 0.45;
    input_hidden_weights[0][1] = 0.78;
    input_hidden_weights[1][0] = -0.12;
    input_hidden_weights[1][1] = 0.13;

    // Hidden neurons
    std::vector<double> hidden(2);

    try
    {
        std::vector<double> temp = input_hidden_weights * input;
        hidden = temp;
    }
    catch( const char* msg )
    {
        std::cerr << msg << std::endl;
    }

    // Activation function
    hidden[0] = sigmoid( hidden[0] );
    hidden[1] = sigmoid( hidden[1] );

    std::cout << "Hidden neurons:" << std::endl;
    lay_output(hidden);

    // Hidden -> Output weights
    Matrix hidden_output_weights ( 2 , 1 );

    hidden_output_weights[0][0] = 1.5;
    hidden_output_weights[1][0] = -2.3;

    // Output neuron
    std::vector<double> output(1);

    try
    {
        std::vector<double> temp = hidden_output_weights * hidden;
        output = temp;
    }
    catch( const char* msg )
    {
        std::cerr << msg << std::endl;
        
        return 1;
    }

    // Activation fuction
    output[0] = sigmoid( output[0] );

    std::cout << "Output neuron:" << std::endl;
    lay_output(output);

    // Error
    std::cout << "Error:" << std::endl;
    std::cout << pow( 1 - output[0] , 2 ) << std::endl;

    Neuro neuro(1, output[0]);

    neuro.DeltaHidden(1, hidden, hidden_output_weights);
    neuro.DeltaHiddenOutput(hidden_output_weights, hidden, 0.7, 0.3);
    neuro.DeltaHiddenInput(input_hidden_weights, input, 0.7, 0.3);
    
    return 0;
}