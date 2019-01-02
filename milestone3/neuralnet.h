#ifndef NEURALNET_H
#define NEURALNET_H

#include "neuron.h"
#include "weights.h"

class NeuralNet
{
public:
    NeuralNet();
    NeuralNet(vector <int> topology);

    void setInput(vector <double> input);
    vector <double> getOutput();
    void back(double eta, double alpha, vector <double> output);

private:
    vector <int> topology;
    vector <Weights> net;
    vector <vector <Neuron>> layers;
};

#endif // NEURALNET_H
