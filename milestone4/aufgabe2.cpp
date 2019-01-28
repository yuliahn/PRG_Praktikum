#include "aufgabe2.h"

char * importFile(string fileName) {
    ifstream dataFile (fileName, ios::in | ios::binary);

    int length;
    dataFile.seekg (0, ios::end);
    length = dataFile.tellg();
    dataFile.seekg (0, ios::beg);

    cout << "File size in Bytes: " << length << endl;

    char * buffer;
    buffer = new char[length];

    dataFile.read (buffer, length);
    cout << dataFile.gcount() << " Bytes were read." << '\n' << endl;

    if (!dataFile) {
        cout << "Error" << endl;
    }

    return buffer;
}

vector<vector<vector<unsigned int>>> copyData(char * buffer)
{
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
                imageVec.push_back(px/100000000); // data scaled from 0-255 to 0-0.0000255
            }
            batchVec.push_back(imageVec);
        }
        data.push_back(batchVec);
    }

    cout << "Copied batches: " << data.size() << endl;

    return data;
}

vector<vector<unsigned int>> copyLabels(char * buffer)
{
    cout << "Copying labels..." << endl;
    unsigned int iterator = 8;
    vector<vector<unsigned int>> labels;

    for (unsigned int batch = 0; batch < 120; batch++) {
        //cout << "Copying batch " << batch+1 << "..." << endl;
        vector<unsigned int> batchVec;
        for (unsigned int image = 0; image < 500; image++) {
            //cout << "   Copying image " << image+1 << endl;
            unsigned char newImage = buffer[iterator++];
            unsigned int img = newImage;
            batchVec.push_back(img);
        }
        labels.push_back(batchVec);
    }
    cout << "Copied labels: " << iterator-8 << endl;
    cout << "Copied batches: " << labels.size() << endl;

    return labels;
}
