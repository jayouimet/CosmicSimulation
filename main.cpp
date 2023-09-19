#include <iostream>
#include "ml/Perceptron.h"
#include "ml/Trainer.h"

int main()
{
    Trainer t = Trainer();
    t.GenerateTestTrainingData();
    Perceptron p = Perceptron(1, Perceptron::Linear);
    int epoch = 100000;


    std::vector<std::vector<float>> inputs = t.getInputs();
    std::vector<float> outputs = t.getOutputs();

    std::cout << p.toString() << std::endl;

    float before = p.Evaluate(inputs, outputs);
    for (int i = 0; i < epoch; i++) 
    {
        p.Train(inputs, outputs, 0.001f);
    }
    float after = p.Evaluate(inputs, outputs);

    std::cout << "Loss before : " << std::to_string(before) << std::endl;
    std::cout << "Loss after (Training data) : " << std::to_string(after) << std::endl;


    t.GenerateTestTestData();

    inputs = t.getInputs();
    outputs = t.getOutputs();

    after = p.Evaluate(inputs, outputs); 
    std::cout << "Loss after : (Test data) " << std::to_string(after) << std::endl;

    std::cout << p.toString() << std::endl;

    return 0;
}