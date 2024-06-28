#include <iostream>
#include <math.h>

#include "matrix.h"
#include "neuro.h"

double sigmoid( const double value )
{
    return 1 / ( 1 + exp( -value ) );
}

int main()
{
    // Input neurons
    Matrix input ( 1 , 2 );

    input.matrix[0][0] = 1;
    input.matrix[0][1] = 0;

    std::cout << "Input neurons:" << std::endl;
    std::cout << input;

    // Input -> Hidden weights
    Matrix input_hidden_weights ( 2 , 2 );

    input_hidden_weights.matrix[0][0] = 0.45;
    input_hidden_weights.matrix[0][1] = 0.78;
    input_hidden_weights.matrix[1][0] = -0.12;
    input_hidden_weights.matrix[1][1] = 0.13;

    // Hidden neurons
    Matrix hidden ( 1 , 2 );

    try
    {
        Matrix temp = input * input_hidden_weights;
        hidden = temp;
    }
    catch( const char* msg )
    {
        std::cerr << msg << std::endl;
    }

    // Activation function
    hidden.matrix[0][0] = sigmoid( hidden.matrix[0][0] );
    hidden.matrix[0][1] = sigmoid( hidden.matrix[0][1] );

    std::cout << "Hidden neurons:" << std::endl;
    std::cout << hidden;

    // Hidden -> Output weights
    Matrix hidden_output_weights ( 2 , 1 );

    hidden_output_weights.matrix[0][0] = 1.5;
    hidden_output_weights.matrix[1][0] = -2.3;

    // Output neuron
    Matrix output ( 1 , 1 );

    try
    {
        Matrix temp = hidden * hidden_output_weights;
        output = temp;
    }
    catch( const char* msg )
    {
        std::cerr << msg << std::endl;
        
        return 1;
    }

    // Activation fuction
    output.matrix[0][0] = sigmoid( output.matrix[0][0] );

    std::cout << "Output neuron:" << std::endl;
    std::cout << output;

    // Error
    std::cout << "Error:" << std::endl;
    std::cout << pow( 1 - output.matrix[0][0] , 2 ) << std::endl;
    Neuro neuro(1, output.matrix[0][0]);
    neuro.DeltaHidden(1, hidden, hidden_output_weights);
    neuro.DeltaHiddenOutput(hidden_output_weights, hidden, 0.7, 0.3);
    neuro.DeltaHiddenInput(input_hidden_weights, input, 0.7, 0.3);
    return 0;
}