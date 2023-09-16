#include "Trainer.h"

Trainer::Trainer()
{
}

Trainer::Trainer(std::vector<std::vector<float>> inputs, std::vector<float> outputs)
{
    this->mInputs = inputs;
    this->mOutputs = outputs;
}

std::vector<std::vector<float>> Trainer::getInputs()
{
    return this->mInputs;
}

std::vector<float> Trainer::getOutputs()
{
    return this->mOutputs;
}

void Trainer::GenerateTestTrainingData() {
    this->mInputs = std::vector<std::vector<float>>();
    this->mOutputs = std::vector<float>();
    
    // 2x + 1
    std::vector<float> inputVec1;
    inputVec1.push_back(-0.5f);
    this->mInputs.push_back(inputVec1);
    this->mOutputs.push_back(0.0f);

    std::vector<float> inputVec2;
    inputVec2.push_back(15.0f);
    this->mInputs.push_back(inputVec2);
    this->mOutputs.push_back(31.0f);

    std::vector<float> inputVec3;
    inputVec3.push_back(-20.0f);
    this->mInputs.push_back(inputVec3);
    this->mOutputs.push_back(-39.0f);
}

void Trainer::GenerateTestTestData() {
    this->mInputs = std::vector<std::vector<float>>();
    this->mOutputs = std::vector<float>();

    // 2x + 1
    std::vector<float> inputVec1;
    inputVec1.push_back(1.5f);
    this->mInputs.push_back(inputVec1);
    this->mOutputs.push_back(4.0f);

    std::vector<float> inputVec2;
    inputVec2.push_back(40.0f);
    this->mInputs.push_back(inputVec2);
    this->mOutputs.push_back(81.0f);

    std::vector<float> inputVec3;
    inputVec3.push_back(-50.0f);
    this->mInputs.push_back(inputVec3);
    this->mOutputs.push_back(-99.0f);
}