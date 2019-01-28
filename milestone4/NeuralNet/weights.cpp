#include "weights.h"

Weights::Weights() {}

Weights::Weights(vector <Neuron> * layer1, vector <Neuron> * layer2)
{
    this->inLayer = layer1;
    this->outLayer = layer2;

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

    updateValues();
}

double Weights::getWeight(int m, int j)
{
    return this->matrix[m][j];
}

void Weights::setWeight(int m, int j, double value)
{
    this->matrix[m][j] = value;
}

void Weights::setWeights(int i, vector <double> values)
{
    this->matrix[i] = values;
}
vector <vector <double>> * Weights::getMatrix()
{
    vector <vector <double>> * p = &matrix;
    return p;
}

vector <Neuron> * Weights::getInLayer()
{
    return this->inLayer;
}
vector <Neuron> * Weights::getOutLayer()
{
    return this->outLayer;
}



void Weights::updateValues()
{
    // for each m neuron in outLayer: set value, activation output and derivative, based on the inLayer neuron values
    for (int m = 0; m < outLayer->size(); m++) {
        double sum = 0;
        for (int j = 0; j < inLayer->size(); j++) {
            sum += matrix[m][j] * (*inLayer)[j].getValue();
        }


        // Normalization of values:
        // neurons in hidden layer 65: 8K-16K
        // neurons in output layer 10: 300K-500K
        if (sum > 200000) {
            sum = sum/1400000; // neurons in output layer
        } else if (sum > 1000) {
            sum = sum/500000; // neurons in hidden layer
        }


        (*outLayer)[m].setValue(sum);
        (*outLayer)[m].setActivation(activationFct((*outLayer)[m].getValue()));
        (*outLayer)[m].setDerivation(derivation((*outLayer)[m].getValue()));

        //cout << "Value of neuron " << m << ": " << (*outLayer)[m].getValue() << endl;
        //cout << "Activation of neuron " << m << ": " << (*outLayer)[m].getActivationOutput() << endl;
        //cout << "Derivative of neuron " << m << ": " << (*outLayer)[m].getDerivative() << endl;
    }
    cout << endl;
}

void Weights::printWeights()
{
    for (unsigned k=0; k < matrix.size(); k++){
        for (int l=0; l < matrix[0].size(); l++){
            cout << ' ' << matrix[k][l];
            }
            cout << endl;
    }
}

