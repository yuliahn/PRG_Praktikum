#include "mainwindow.h"
#include "NeuralNet/neuralnet.h"
#include "aufgabe2.cpp"

#include <QApplication>

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    // /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // */

     /*
    const char* imagesFile = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\training_images\\images.bin";
    const char* labelsFile = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\training_images\\images.labels";

    cout << "Importing data from images..." << endl;
    char* buffer = importFile(imagesFile);
    vector<vector<vector<unsigned int>>> data = copyData(buffer);

    //for (unsigned int image = 0; image < 0; image++) {
    //    vector <unsigned int> testData = data[0][image];
    //    unsigned int counter = 0;
    //    for (int i = 0; i < 28; i++) {
    //        for (int j = 0; j < 28; j++) {
    //            unsigned int value = testData[counter++];
    //            cout << value << ' ';
    //        }
    //        cout << endl;
    //    }
    //    cout << '\n' << endl;
    //}

    cout << "\nImporting data from labels..." << endl;
    char* labelsBuffer = importFile(labelsFile);
    vector<vector<unsigned int>> labels = copyLabels(labelsBuffer);


    vector<int> topology = {784,64,10};
    double eta = 0.3; //0.3
    double alpha = 0;
    NeuralNet net(topology);

    vector <double> output = net.getOutput();

    double batchError = net.trainBatch(data, labels, eta, alpha, 0);
    for (unsigned int batch = 1; batch < 120; batch++) { //120 batches
        cout << "\nTraining batch " << batch << "..." << endl;
        double curBatchError = net.trainBatch(data, labels, eta, alpha, batch);
        if (curBatchError - batchError <= 0.01) {
            eta = 1.05 * eta;
            batchError = curBatchError;
        } else {
            max(0.01, 0.5*eta);
        }
    }

    unsigned int number = 2; // 0-500 images from batch 0
    test(number, net, data, labels);

    net.exportState("trainedANN.txt"); // start: 11:56 , finish: ~13:02

    return 0;
     */
    return a.exec();
}
