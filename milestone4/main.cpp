#include "mainwindow.h"
#include "NeuralNet/neuralnet.h"
#include "aufgabe2.cpp"

#include <QApplication>

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*
    const char* imagesFile = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\training_images\\images.bin";
    const char* labelsFile = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\training_images\\images.labels";

    cout << "Importing data from images..." << endl;
    char* buffer = importFile(imagesFile);
    vector<vector<vector<unsigned int>>> data = copyData(buffer);

    cout << "\nImporting data from labels..." << endl;
    char* labelsBuffer = importFile(labelsFile);
    vector<vector<unsigned int>> labels = copyLabels(labelsBuffer);

    vector<int> topology = {784,64,10};
    double eta = 0.3; //0.3
    double alpha = 0;
    NeuralNet net(topology);
    vector<double> values(10,0);

    vector <double> output = net.getOutput();

    // Train the network with batch 1:
    for (unsigned int image = 0; image < 500; image++) { // 500 images
        values[labels[0][image]] = 1000000; // rescale from 1 to 1000000
        net.setInput(data[0][image]);
        net.back(eta, alpha, values);

        output = net.getOutput();
        //cout << "\nOutput: ";
        //net.printOutput();
    }

    // Testing output after mini-batch 1
    net.setInput(data[0][5]);
    cout << "\nTest " << labels[0][5] << ": ";
    net.printOutput();

    return 0;
    */
    return a.exec();
}
