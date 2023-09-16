#ifndef ML_TRAINER_H_
#define ML_TRAINER_H_

#include <vector>

class Trainer 
{
private:
    std::vector<std::vector<float>> mInputs;
    std::vector<float> mOutputs;
public:
    Trainer();
    Trainer(std::vector<std::vector<float>> inputs, std::vector<float> outputs);
    std::vector<std::vector<float>> getInputs();
    std::vector<float> getOutputs();
    void GenerateTestTrainingData();
    void GenerateTestTestData();
};

#endif