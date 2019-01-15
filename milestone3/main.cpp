#include <QCoreApplication>
#include "neuralnet.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Hello world" << endl;


    vector <int> topology = {3,2,3};
    NeuralNet neuralNet1(topology);
    vector <double> input = {1,3,1};

    neuralNet1.getNet()[0].getMatrix();
    neuralNet1.setInput(input);



    vector <double> output = neuralNet1.getOutput();

    for (int i = 0; i < output.size(); i++) {
        cout << "Output: " << output[i] << ' ' << endl;
    }


    /*
    vector <double> input = {1,1,1};
    vector <double> actualValues = {1,1,1};
    double eta = 0.1;
    double alpha = 0;

    neuralNet1.setInput(input);

    vector <double> output = neuralNet1.getOutput();
    cout << "Start" << endl;
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << ' ' << endl;
    }

    //neuralNet1.back(eta, alpha, actualValues);

    */
    return a.exec();

}
