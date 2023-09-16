#ifndef ML_PERCEPTRON_H_
#define ML_PERCEPTRON_H_

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

const float LOWER_BOUND = -10.0f;
const float UPPER_BOUND = 10.0f;

class Perceptron 
{
public:
    enum Type 
    {
        Linear,
        ReLu
    };
private:
    std::vector<float> mWeights;
    float mBias;
    Type mActivation;

    float diff(float output, float expected);
    float activate(float input);

    static float activationReLu(float);
public:

    Perceptron(int n, Type activation);
    
    float Predict(std::vector<float> inputs);
    float Evaluate(std::vector<std::vector<float>> inputs, std::vector<float> outputs);
    void Train(std::vector<std::vector<float>> inputs, std::vector<float> outputs, float learningRate);

    std::string toString();
};

#endif