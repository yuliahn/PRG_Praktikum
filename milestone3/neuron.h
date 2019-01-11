#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

class Neuron
{
public:
    Neuron();
    Neuron(double x);

    void setValue(double x);

    // sets both activateValue and derivative, since they are interrelated
    void setActivation(double x);
    void setDerivation(double x);

    double getValue();
    double getActivationOutput();
    double getDerivative();

private:
    double value; // x_j = sum(incoming weights*neurons' values) value
    double activationOutput; // a_j = f(x_j) value
    double derivative; // f(x_j)' value
};

/* Examples of vectors for weights matrix with weights[layer2][layer1]
vector <vector <double>> weights; // matrix of weights between two layers with neurons
vector <Neuron> layer1; // vector of neurons in one layer
vector <Neuron> layer2; // vector of neurons in one layer
*/

// Aufgabe 1b)
//use in main.cpp: neuron.setActivation(activationFct(neuron.getValue), derivation(neuron.getValue))
double activationFct(double x); // calculates activation function value for x
double derivation(double x); // calculates derivative of the activation function for x



#endif // NEURON_H
