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
