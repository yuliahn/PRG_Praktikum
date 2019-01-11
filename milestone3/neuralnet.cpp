#include "neuralnet.h"

NeuralNet::NeuralNet() {}

// Aufgabe 2a)
NeuralNet::NeuralNet(vector <int> topology)
{
    // generate layers of neurons from topology
    for (int i = 0; i < topology.size(); i++) {
        // generate neurons using topology[i] as a number of neurons in each layer
        vector <Neuron> layer;
        for (int j = 0; j < topology[i]; j++) {
            Neuron neuron;
            layer.push_back(neuron);
        }
        layers.push_back(layer);
    }

    // add bias neurons to all layers but output layer
    for (int i = 0; i < layers.size() - 1; i++) {
        Neuron neuron(1); // bias equal to 1
        layers[i].push_back(neuron);
    }

    // connect layers with randomly generated weights
    for (int i = 0; i < layers.size() - 1; i++) {
        Weights weights(layers[i], layers[i+1]);
        net.push_back(weights);
    }
}

// Aufgabe 2c)
void NeuralNet::setInput(vector <double> input)
{
    for (int i = 0; i < input.size(); i++) {
        layers.front()[i].setValue(input[i]);
    }

    for (vector<Weights>::iterator it = net.begin(); it != net.end(); ++it) {
        (*it).updateValues();
    }
}

// Aufgabe 2b)
vector <double> NeuralNet::getOutput()
{
    vector <double> output;
    vector <Neuron> outputLayer = layers.back();
    for (int i = 0; i < outputLayer.size(); i++) {
        output.push_back(outputLayer[i].getValue());
    }
    return output;
}

// Aufgabe 2d)
void NeuralNet::back(double eta, double alpha, vector <double> output)
{
    net.back().outputGradient(eta, output, alpha);
    for (vector<Weights>::reverse_iterator it = net.rbegin()+1; it != net.rend(); ++it) {
        (*it).hiddenGradient(eta, alpha);
    }

    // update values in each layer after weights update
    for (vector<Weights>::iterator it = net.begin(); it != net.end(); ++it) {
        (*it).updateValues();
    }
}

void NeuralNet::exportState(string name)
{
    // export topology
    string exportText;
    for (int i = 0; i < topology.size()-1; i++) {
        exportText.append(to_string(topology[i]));
        exportText.append(",");
    }
    exportText.append(to_string(topology.back()));
    exportText.append("#");

    //export weights
    for (int i = 0; i < net.size()-1; i++) { // for each matrix
        for (int j = 0; j < net[i].getMatrix().size(); j++) { // for each row within a matrix
            for (int k = 0; k < net[i].getMatrix()[j].size()-1; k++) { // for each number within a row
                exportText.append(to_string(net[i].getMatrix()[j][k]));
                exportText.append(",");
            }
            exportText.append(to_string(net[i].getMatrix()[j].back()));
            exportText.append("*");
        }
        exportText.append("#");
    }

    ofstream myfile;
    myfile.open(name);
    myfile << exportText;
    myfile.close();
}

NeuralNet NeuralNet::importState(string name)
{
    string line;
    vector<string> tokens;

    vector <int> importTopology;


    ifstream myfile(name);
    if(myfile.is_open()) {
        while(getline(myfile, line))
        {
            vector <string> tokens = split(line,'#');

            // import topology
            vector <string> topologies = split(tokens[0],',');
            for (int i = 0; i < topologies.size(); i++) {
                importTopology.push_back(stoi(topologies[i]));
            }
            NeuralNet importNeuralNet(importTopology);


            for (int i = 0; i < tokens[0].length(); i++) {
                    importTopology.push_back(line[i]);
                }
            }
            NeuralNet importNeuralNet(importTopology);

            // import weights
            for (int i = 1; i < tokens.size(); i++) {
                vector <string> rows = split(tokens[i],'*');
                for (int j = 0; j < rows.size(); j++) {
                    vector <string> weights = split(rows[j],',');

                    // Convert string to double within weights vector
                    vector <double> importWeights;
                    for (int i = 0; i < weights.size(); i++) {
                        importWeights.push_back(stod(weights[i]));
                    }

                    for (int k = 0; k < net.size(); k++) {
                        for (int l = 0; l < net[k].getMatrix().size(); l++) {
                            net[k].setWeights(l, importWeights);
                        }
                    }
                }

        }
        myfile.close();
    }
}


vector<string> NeuralNet::split(const string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}
