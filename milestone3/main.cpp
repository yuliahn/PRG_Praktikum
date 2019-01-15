#include "neuralnet.h"

int main(int argc, char *argv[])
{
    vector <int> topology = {5,2,4};
    NeuralNet neuralNet1(topology);

    vector <double> input = {2,3,1};

    neuralNet1.getNet()[0].getMatrix();
    neuralNet1.setInput(input);

    vector <double> actualValues = {1,3,2};
    double eta = 0.1;
    double alpha = 0;

    vector <double> output = neuralNet1.getOutput();

    cout << "Generated neural net with random weights: " << endl;
    for (int i = 0; i < neuralNet1.getNet().size(); i++) {
        cout << "Weights between layers " << i << " and " << i+1 << ": " << endl;
        neuralNet1.getNet()[i].printWeights();
    }

    cout << "\nOutput: ";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << ' ';
    }
    cout << '\n' << endl;

    neuralNet1.back(eta, alpha, actualValues);

    output = neuralNet1.getOutput();

    cout << "Neural net after backpropagation: " << endl;
    for (int i = 0; i < neuralNet1.getNet().size(); i++) {
        cout << "Weights between layers " << i << " and " << i+1 << ": " << endl;
        neuralNet1.getNet()[i].printWeights();
    }

    cout << "\nOutput new: ";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << ' ';
    }
    cout << '\n' << endl;

    neuralNet1.exportState("testState.txt");
    cout << "State exported.\n" << endl;

    NeuralNet neuralNet2 = importState("C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone3-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\testState.txt");

    for (int i = 0; i < neuralNet2.getNet().size(); i++) {
        cout << "Imported weights between layers " << i << " and " << i+1 << ": " << endl;
        neuralNet2.getNet()[i].printWeights();
    }

    return 0;

}
