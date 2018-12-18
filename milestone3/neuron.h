#ifndef NEURON_H
#define NEURON_H

#include <vector>

using namespace std;

class Neuron
{
public:
    Neuron();

    // sets both activateValue and derivative, since they are interrelated
    void setActivate(double x, double y) {
        this->value = x;
        this->derivative = y;
    }

private:
    double value; // x_j = sum(incoming weights*neurons' values) value
    double activateValue; // a_j = f(x_j) value
    double derivative; // f(x_j)' value
};

vector <vector <double>> weights; // matrix of weights between two layers with neurons
vector <Neuron> layer1; // vector of neurons in one layer
vector <Neuron> layer2; // vector of neurons in one layer

double activateFct(double x); // calculates activation function value for x
double derivation(double x); // calculates derivative of the activation function for x

// generate/update the matrix with weights between neurons across layers
void setWeights(vector <Neuron> layer1, vector <Neuron> layer2);

// get weight of neuron i from layer1 to neuron j from layer2
double getWeight(int i, int j, vector <vector <double>> weights);

// returns a matrix with hidden layer gradients (weights between hiddenLayer1 and hiddenLayer2)
vector <vector <double>> hiddenGradient(double eta, vector <vector <double>> weights, vector <Neuron> hiddenLayer1, vector <Neuron> hiddenLayer2);

// returns a matrix with output layer gradients (weights between hiddenLayer and outputLayer)
vector <vector <double>> outputGradient(double eta, vector <vector <double>> weights, vector <Neuron> hiddenLayer, vector <Neuron> outputLayer);

#endif // NEURON_H
