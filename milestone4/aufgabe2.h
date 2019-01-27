#ifndef AUFGABE2_H
#define AUFGABE2_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

char * importFile(string fileName);
vector<vector<vector<unsigned int>>> copyData(char * buffer);
vector<vector<unsigned int>> copyLabels(char * buffer);


#endif // AUFGABE2_H
