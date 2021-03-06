#ifndef NEURALNET_H
#define NEURALNET_H

#include "neuron.h"
#include "weights.h"


class NeuralNet
{
public:
    NeuralNet();
    NeuralNet(vector <int> topology);

    vector <Weights> getNet() {return this->net;}
    vector <vector <Neuron>> getLayers() {return this->layers;}
    vector <int> getTopology() {return this->topology;}

    void setTopology(vector <int> input);
    void setNet(vector <Weights> net);
    void setLayers(vector <vector <Neuron>> layers);
    void setInput(vector <unsigned int> input);
    vector <double> getOutput();
    void back(double eta, double alpha, vector <double> output);
    void exportState(string name);
    void importState(string name);

    void hiddenGradient(double eta, vector <double> actualValues, double alpha = 1);
    void outputGradient(double eta, vector <double> actualValues, double alpha = 1);

    void printOutput();

    double trainBatch(
            vector<vector<vector<unsigned int>>> data,
            vector<vector<unsigned int>>labels,
            double eta,
            double alpha,
            unsigned int batch);

private:
    vector <int> topology;
    vector <Weights> net;
    vector <vector <Neuron>> layers;
};

vector <string> split(const string& s, char delimiter);
NeuralNet importState(string name);

#endif // NEURALNET_H
