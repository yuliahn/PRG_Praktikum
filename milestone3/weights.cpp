#include "weights.h"

Weights::Weights() {}

Weights::Weights(vector <Neuron> layer1, vector <Neuron> layer2)
{
    this->inLayer = &layer1;
    this->outLayer = &layer2;

    // generate a random weights matrix
    srand(time(NULL));
    vector <vector <double>> weights;
    for (int i = 0; i < outLayer->size(); i++) {
        vector <double> weights_i; // incoming weights for each neuron from layer 2
        for (int j = 0; j < inLayer->size(); j++) {
            weights_i.push_back((double) rand() / (RAND_MAX));
        }
        weights.push_back(weights_i);
    }

    this->matrix = weights;

    // for each m neuron in outLayer: set value, activation output and derivative, based on the inLayer neuron values
    for (int m = 0; m < outLayer->size(); m++) {
        double sum = 0;
        for (int j = 0; j < inLayer->size(); j++) {
            sum += matrix[m][j] * (*inLayer)[j].getValue();
        }
        (*outLayer)[m].setValue(sum);
        (*outLayer)[m].setActivation(activationFct((*outLayer)[m].getValue()));
        (*outLayer)[m].setDerivation(derivation((*outLayer)[m].getValue()));
    }
}

double Weights::getWeight(int m, int j)
{
    return this->matrix[m][j];
}

void Weights::setWeight(int m, int j, double value)
{
    this->matrix[m][j] = value;
}

vector <vector <double>> Weights::getMatrix()
{
    return this->matrix;
}

vector <Neuron> * Weights::getInLayer()
{
    return this->inLayer;
}
vector <Neuron> * Weights::getOutLayer()
{
    return this->outLayer;
}

void Weights::outputGradient(double eta, vector <double> actualValues)
{
    for (int m = 0; m < matrix.size(); m++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            double deltaWeight;
            deltaWeight = eta * 2 * (actualValues[m] - (*outLayer)[m].getActivationOutput()) * (*outLayer)[m].getDerivative() * (*inLayer)[j].getActivationOutput();
            matrix[m][j] += deltaWeight;
        }

    }
}

void Weights::hiddenGradient(double eta)
{

}
