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
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    */

    const char* imagesFile = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\training_images\\images.bin";
    const char* labelsFile = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\training_images\\images.labels";

    cout << "Importing data from images..." << endl;
    char* buffer = importFile(imagesFile);

    /*
    for (int i = 0; i < 100; i++) {
        cout << ' ' << to_string(buffer[i]);
    }
    cout << endl;
    */

    cout << "Copying data..." << endl;
    unsigned int iterator = 16;
    vector<vector<vector<unsigned int>>> data;

    for (unsigned int batch = 0; batch < 120; batch++) {
        //cout << "Copying batch " << batch+1 << "..." << endl;
        vector<vector<unsigned int>> batchVec;
        for (unsigned int image = 0; image < 500; image++) {
            //cout << "   Copying image " << image+1 << endl;
            vector<unsigned int> imageVec;
            for (unsigned int pixel = 0; pixel < 784; pixel++) {
                unsigned char newPixel = buffer[iterator++];
                unsigned int px = newPixel;
                //cout << "      Copying pixel " << pixel+1 << ": " << px << endl;
                imageVec.push_back(px);
            }
            batchVec.push_back(imageVec);
        }
        data.push_back(batchVec);
    }

    cout << "Copied batches: " << data.size() << endl;


    cout << "\nImporting data from labels..." << endl;
    char* labelsBuffer = importFile(labelsFile);

    cout << "Copying labels..." << endl;
    unsigned int LabelsIterator = 8;
    vector<vector<unsigned int>> labels;

    for (unsigned int batch = 0; batch < 120; batch++) {
        //cout << "Copying batch " << batch+1 << "..." << endl;
        vector<unsigned int> batchVec;
        for (unsigned int image = 0; image < 500; image++) {
            //cout << "   Copying image " << image+1 << endl;
            unsigned char newImage = labelsBuffer[LabelsIterator++];
            unsigned int img = newImage;
            batchVec.push_back(img);
        }
        labels.push_back(batchVec);
    }
    cout << "Copied labels: " << LabelsIterator-8 << endl;
    cout << "Copied batches: " << labels.size() << endl;

    vector<int> topology = {784,64,10};
    double eta = 10; //0.3
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


    net.setInput(data[0][1]);
    cout << "\nTest " << labels[0][1] << ": ";
    net.printOutput();


    return 0;
    //return a.exec();
}
