#ifndef NEURON_H
#define NEURON_H

#include <vector>

using namespace std;

class Neuron
{
public:
    Neuron();

    // sets both activateValue and differential, since they are interrelated
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

void activateFct();
void derivation();

// generate/update the matrix with weights between neurons across layers
void setWeights(vector <Neuron> layer1, vector <Neuron> layer2);

// get weight of neuron i from layer1 to neuron j from layer2
double getWeight(int i, int j, vector <vector <double>> weights);

// returns the matrix with hidden layer gradients (generates a matrix of weights between input layers inbetween)
vector <vector <double>> hiddenGradient(vector <Neuron> hiddenLayer1, vector <Neuron> hiddenLayer2);

// returns the matrix with output layer gradients (generates a matrix of weights between input layers inbetween)
vector <vector <double>> outputGradient(vector <Neuron> hiddenLayer, vector <Neuron> outputLayer);

#endif // NEURON_H
