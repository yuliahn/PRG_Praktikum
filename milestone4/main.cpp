#include "mainwindow.h"
#include <QApplication>

#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    vector <int> test = {};
    cout << test.size() << endl;

    const char* imagesFile = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\training_images\\images.bin";
    const char* labelsFile = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\training_images\\images.labels";

    // http://courses.cs.vt.edu/~cs2604/fall00/binio.html
    struct stat results;

    if (stat(labelsFile, &results) == 0)
        // The size of the file in bytes is in results.st_size
        cout << results.st_size << endl;
    else
        // An error occurred
        cout << "Error" << endl;

    char* buffer;
    buffer = new char[101];


    ifstream myFile (imagesFile, ios::in | ios::binary);
    myFile.read (buffer, 101);
    cout << myFile.gcount() << " Bytes were read." << '\n' << endl;

    /*
    for (int i = 0; i < 101; i++) {
        cout << ' ' << buffer[i];
    }
    cout << endl;
    */

    for (int i = 0; i < 101; i++) {
        cout << ' ' << to_string(buffer[i]);
    }
    cout << endl;

    if (!myFile) {
        // An error occurred!
        // myFile.gcount() returns the number of bytes read.
        // calling myFile.clear() will reset the stream state
        // so it is usable again.
        cout << "Error" << endl;
    }
    //cout << to_string(buffer[2]) << endl;

    //return 0;
    return a.exec();
}
