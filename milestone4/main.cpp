#include "mainwindow.h"
#include <QApplication>

#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <string.h>
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

    ifstream myFile (imagesFile, ios::in | ios::binary);

    int length;
    myFile.seekg (0, ios::end);
    length = myFile.tellg();
    myFile.seekg (0, ios::beg);

    cout << "File size in Bytes: " << length << endl;

    char * buffer;
    buffer = new char[length];

    myFile.read (buffer, length);

    cout << myFile.gcount() << " Bytes were read." << '\n' << endl;

    // 60 000 labels => 60 000 images

    for (int i = 0; i < 20; i++) {
        cout << ' ' << to_string(buffer[i]);
    }
    cout << endl;

    //int32_t numImages = buffer[7] | buffer[6]<<8 | buffer[5]<<16 | buffer[4]<<24;
    unsigned int numImages = buffer[7] | buffer[6]<<8 | buffer[5]<<16 | buffer[4]<<24;
    cout << "Number of images: " << numImages << endl;

    // from buffer[8] till the end: pixel data

    if (!myFile) {
        // An error occurred!
        // myFile.gcount() returns the number of bytes read.
        // calling myFile.clear() will reset the stream state
        // so it is usable again.
        cout << "Error" << endl;
    }

    return 0;
    //return a.exec();
}
