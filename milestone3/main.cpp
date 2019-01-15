#include <QCoreApplication>
#include "neuralnet.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Hello world" << endl;

    vector <int> topology = {3,2,3};
    NeuralNet neuralNet1(topology);

    vector <double> input = {2,3,1};

    neuralNet1.getNet()[0].getMatrix();
    neuralNet1.setInput(input);

    vector <double> actualValues = {1,3,2};
    double eta = 0.1;
    double alpha = 0;

    vector <double> output = neuralNet1.getOutput();

    for (int i = 0; i < neuralNet1.getNet().size(); i++) {
        cout << "Weights " << i << endl;
        neuralNet1.getNet()[i].printWeights();
    }

    cout << "Output: ";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << ' ';
    }
    cout << endl;

    neuralNet1.back(eta, alpha, actualValues);

    output = neuralNet1.getOutput();

    cout << "Output new: ";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < neuralNet1.getNet().size(); i++) {
        cout << "Weights " << i << endl;
        neuralNet1.getNet()[i].printWeights();
    }

    return a.exec();

}
