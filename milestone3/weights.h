#ifndef WEIGHTS_H
#define WEIGHTS_H

#include "neuron.h"

// Aufgabe 1c)
class Weights
{
public:
    Weights();
    Weights(vector <Neuron> layer1, vector <Neuron> layer2);
    double getWeight(int i, int j);
    void setWeight(int i, int j, double value);
    void setWeights(int i, vector <double> values);
    vector <vector <double>> getMatrix();
    vector <Neuron> * getInLayer();
    vector <Neuron> * getOutLayer();
    void updateValues();


private:
    vector <vector <double>> matrix;
    vector <Neuron> * inLayer;
    vector <Neuron> * outLayer;
};




// returns a matrix with hidden layer gradients (weights between hiddenLayer1 and hiddenLayer2)
vector <vector <double>> hiddenGradient(
        double eta,
        Weights weights
        );

// returns a matrix with output layer gradients (weights between hiddenLayer and outputLayer)
vector <vector <double>> outputGradient(
        double eta,
        Weights weights,
        vector <double> actualValues
        );

#endif // WEIGHTS_H
