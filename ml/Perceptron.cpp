#include "Perceptron.h"

float Perceptron::diff(float output, float expected) 
{
    return 2 * (expected - output);
    /*if (output == expected)
        return 0;

    float divider = (float) Math.sqrt(output * output + expected * expected);
    float normalizedOutput = output / divider;
    float normalizedExpected = expected / divider;
    return 2 * (normalizedExpected - normalizedOutput);*/
}

float Perceptron::activate(float input)
{
    switch (this->mActivation)
    {
    case ReLu:
        return Perceptron::activationReLu(input);
    default:
        return input;
    }
}

float Perceptron::activationReLu(float input) 
{
    if (input > 0)
        return input;
    return 0;
}

Perceptron::Perceptron(int n, Perceptron::Type activation) 
{
    srand(static_cast <unsigned> (time(0)));
    
    for (int i = 0; i < n; i++) 
    {
        float random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(UPPER_BOUND - LOWER_BOUND))) + LOWER_BOUND;
        this->mWeights.push_back(random);
    }

    this->mBias = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(UPPER_BOUND - LOWER_BOUND))) + LOWER_BOUND;
    this->mActivation = activation;
}

float Perceptron::Predict(std::vector<float> inputs) 
{
    if (inputs.size() != this->mWeights.size())
        throw;

    float result = this->mBias;
    for (int i = 0; i < this->mWeights.size(); i++) 
    {
        result += this->mWeights[i] * inputs[i];
    }
    return result;
}

float Perceptron::Evaluate(std::vector<std::vector<float>> inputs, std::vector<float> outputs)
{
    /*float evaluation = 1;

    float goods = 0;
    float bads = 0;

    for (int i = 0; i < outputs.size(); i++) 
    {
        float o = this->Predict(inputs[i]);
        if (o == outputs[i])
            goods++;
        else
            bads++;
    }

    if (goods + bads == 0)
        return evaluation;

    evaluation = goods / (goods + bads);

    return evaluation;*/

    if (outputs.size() == 0)
        return 0;

    float loss = 0;

    for (int i = 0; i < outputs.size(); i++) 
    {
        float o = this->Predict(inputs[i]);
        loss += this->diff(o, outputs[i]);
    }

    return std::abs(loss / outputs.size());
}

void Perceptron::Train(std::vector<std::vector<float>> inputs, std::vector<float> outputs, float learningRate)
{
    for (int i = 0; i < outputs.size(); i++) 
    {
        float sum_of_inputs = 1;
        for (float in : inputs[i])
            sum_of_inputs += in;

        float prediction = this->Predict(inputs[i]);
        float diff = std::abs(this->diff(prediction, outputs[i]));
        int dirr = 1;
        if (prediction > outputs[i])
            dirr = -1;

        for (int j = 0; j < this->mWeights.size(); j++) 
        {
            // float norm = this.variance(diff, this.weights[j]);
            this->mWeights[j] += dirr * diff * (std::abs(inputs[i][j]) / sum_of_inputs) * learningRate;
            // this.weights[j] += norm * dirr * diff * learningRate;
        }
        // float norm = this.variance(diff, this.bias);
        this->mBias += dirr * diff * (1 / sum_of_inputs) * learningRate;
        // this.bias += norm * dirr * diff * learningRate;
    }
}

std::string Perceptron::toString()
{
    std::string str;

    str += "Weights : [ ";
    for (float f : this->mWeights) 
    {
        str += std::to_string(f);
        str += " ";
    }
    str += "]\n";
    str += "Bias : ";
    str += std::to_string(this->mBias);

    return str;
}