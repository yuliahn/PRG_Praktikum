#include "neuralnet.h"

NeuralNet::NeuralNet() {}

// Aufgabe 2a)
NeuralNet::NeuralNet(vector <int> topology)
{
    this->topology = topology;
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

        vector <Neuron> * p1 = &layers[i];
        vector <Neuron> * p2 = &layers[i+1];
        Weights weights(p1, p2);

        //Weights weights(layers[i], layers[i+1]);
        net.push_back(weights);
    }

}

void NeuralNet::setTopology(vector <int> topology)
{
    this->topology = topology;
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

        vector <Neuron> * p1 = &layers[i];
        vector <Neuron> * p2 = &layers[i+1];
        Weights weights(p1, p2);

        //Weights weights(layers[i], layers[i+1]);
        net.push_back(weights);
    }

}

// Aufgabe 2c)
void NeuralNet::setInput(vector <unsigned int> input)
{
    for (int i = 0; i < input.size(); i++) {
        layers.front()[i].setValue(input[i]);
    }

    cout << "\nValues set" << endl;

    for (int i = 0; i < net.size(); i++) {
        net[i].updateValues();
    }

    /*
    for (vector<Weights>::iterator it = net.begin(); it != net.end(); ++it) {
        (*it).updateValues();
    }
    */
}

// Aufgabe 2b)
vector <double> NeuralNet::getOutput()
{
    vector <double> output;
    vector <Neuron> outputLayer = layers.back();
    for (int i = 0; i < outputLayer.size(); i++) {
        output.push_back(outputLayer[i].getActivationOutput());
    }
    return output;
}

// Aufgabe 2d)
void NeuralNet::back(double eta, double alpha, vector <double> output)
{
    cout << "back" <<endl;
    outputGradient(eta, output, alpha);
    hiddenGradient(eta, output, alpha);

    cout << "Updating values..." << endl;
    // update values in each layer after weights update
    for (vector<Weights>::iterator it = net.begin(); it != net.end(); ++it) {
        (*it).updateValues();
    }
    //cout << "Weights: " << endl;
    //net[1].printWeights();
}

void NeuralNet::outputGradient(double eta, vector <double> actualValues, double alpha)
{
    for (int m = 0; m < (*net.back().getMatrix()).size(); m++) {
        for (int j = 0; j < net.back().getMatrix()[0].size(); j++) {
            double deltaWeight;
            deltaWeight = eta * 2 * (actualValues[m] - (*net.back().getOutLayer())[m].getActivationOutput()) * (*net.back().getOutLayer())[m].getDerivative() * (*net.back().getInLayer())[j].getActivationOutput();
            //cout << "delta weight " << m << ',' << j << ": " << deltaWeight << endl;
            //cout << "getMatrix old: " << (*net.back().getMatrix())[m][j] << endl;
            (*net.back().getMatrix())[m][j] += (1-alpha) * deltaWeight + alpha * deltaWeight;
            //cout << "getMatrix new: " << (*net.back().getMatrix())[m][j] << endl;
        }
    }
}

void NeuralNet::hiddenGradient(double eta, vector <double> actualValues, double alpha)
{
    // hidden layer calculated for a net with 3 layers only
    for (int n = 0; n < (*net[0].getMatrix()).size(); n++) {
        for (int j = 0; j < (*net[0].getMatrix())[0].size(); j++) {
            double sum;
            for (int p = 0; p < actualValues.size(); p++) {
                sum += (actualValues[p] - (*net.back().getOutLayer())[p].getActivationOutput()) * (*net.back().getOutLayer())[p].getDerivative() * (net.back().getWeight(p,n));
            }
            double deltaWeight;
            deltaWeight = eta * 2 * sum * (*net.front().getOutLayer())[n].getDerivative() * (*net.front().getInLayer())[j].getActivationOutput();
        }
    }
}



vector<string> split(const string& s, char delimiter)
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

void NeuralNet::exportState(string name)
{
    // export topology
    string exportText;

    //export weights
    for (int i = 0; i < topology.size()-1; i++) {

        exportText.append(to_string(topology[i]));
        exportText.append(",");
    }

    exportText.append(to_string(topology.back()));
    exportText.append("#");

    for (int i = 0; i < net.size(); i++) { // for each matrix
        for (int j = 0; j < (*net[i].getMatrix()).size(); j++) { // for each row within a matrix
            for (int k = 0; k < (*net[i].getMatrix())[j].size()-1; k++) { // for each number within a row
                exportText.append(to_string((*net[i].getMatrix())[j][k]));
                exportText.append(",");
            }
            exportText.append(to_string((*net[i].getMatrix())[j].back()));
            exportText.append("*");
        }
        exportText.append("#");
    }

    cout << "\nExported text: " << exportText << endl;

    ofstream myfile;
    myfile.open(name);
    myfile << exportText;
    myfile.close();
}

void NeuralNet::importState(string name)
{
    string line;
    vector<string> tokens;

    vector <int> importTopology;
    NeuralNet neuralNet;

    ifstream myfile(name);
    if(myfile.is_open()) {
        while(getline(myfile, line))
        {
            vector <string> tokens = split(line,'#');

            // import topology
            vector <string> topologies = split(tokens[0],',');
            cout << "Imported topology: ";
            for (int i = 0; i < topologies.size(); i++) {
                importTopology.push_back(stoi(topologies[i]));
                cout << importTopology[i] << ' ';
            }
            cout << endl;

            // generate a new neural net with an imported topology
            //NeuralNet importNeuralNet(importTopology);
            setTopology(importTopology);

            // import weights
            for (int i = 1; i < tokens.size(); i++) { // matrix 1, matrix 2
                vector <string> rows = split(tokens[i],'*');
                cout << "\nrows size:" << rows.size() << endl;
                for (int j = 0; j < rows.size(); j++) {
                    vector <string> weights = split(rows[j],',');

                    // Convert string to double within weights vector
                    vector <double> importWeights;
                    for (int k = 0; k < weights.size(); k++) { // weights within a row
                        importWeights.push_back(stod(weights[k]));
                    }

                    cout << "\nImport weights pushed to ANN: " << endl;
                    for (int l = 0; l < importWeights.size(); l++) {
                        cout << importWeights[l] << ' ';
                    }
                    cout << endl;
                    cout << "i-1, j: " << i-1 << ' ' << j << endl;
                    //replace with pointer:
                    //vector <Weights> *p = (importNeuralNet.getNet()[i-1];
                    net[i-1].setWeights(j, importWeights);
                }
            }
            myfile.close();
        }
    }
}


void NeuralNet::printOutput() {
    vector <double> output = this->getOutput();
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << ' ';
    }
    cout << endl;
}

double NeuralNet::trainBatch(
        vector<vector<vector<unsigned int>>> data,
        vector<vector<unsigned int>> labels,
        double eta,
        double alpha,
        unsigned int batch)
{
    double errorsBatch = 0;
    for (unsigned int image = 0; image < 500; image++) { // 500 images
        cout << "Training image " << image << "..." << endl;
        vector<double> values(10,0);
        values[labels[batch][image]] = 1; //
        setInput(data[batch][image]);
        back(eta, alpha, values);

        cout << "Labeled values: " ;
        for (unsigned int neuron = 0; neuron < values.size(); neuron++) {
            cout << values[neuron] << ' ';
        }
        cout << endl;

        vector <Neuron> outputLayer = layers.back();
        double sum = 0;
        for (unsigned int neuron = 0; neuron < 10; neuron++) {
            //cout << "Expected value: " << values[neuron] << ", actual value: " << (outputLayer)[neuron].getActivationOutput() << endl;
            sum += pow(values[neuron] - (outputLayer)[neuron].getActivationOutput(), 2);
        }
        double error = sqrt(sum/10);
        cout << "Error per image " << image << ": " << error << endl;
        errorsBatch += error;
        cout << "Errors batch " << batch << ": " << errorsBatch << endl;
    }
    errorsBatch = errorsBatch/500;
    return errorsBatch;
}
