#ifndef VISUALCRYPT_H
#define VISUALCRYPT_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>
#include <typeinfo>

#include <fstream> // for import/export in 2ab
#include <string>
#include <sstream>
#include <cstdint> // for 2a index access
#include <random> // for 2c

using namespace std;

const vector <vector <int> > a = {{1,0},{0,1}};
const vector <vector <int> > b = {{0,1},{1,0}};

/*This file (visualcrypt) includes the following functions and procedures:
 * encode();
 * decode();
 * overlay();
 * genMatrix();
 * genKey();
 * printMat();
*/

/*! Aufgabe 2a
 * class NBild which imports data by using vectors bildVektor
 * and hilfsVektor, reading from line to line through loops,
 * exports data,
 * read and write through index access with operator overload
 * with const and non-const version,
 * black-white-code set in 2b
 */
class NBild{
    private:
        vector<vector<int>> * bildVektor;
    public:
        NBild(vector<vector<int>>); // constructor with vector assignment
        NBild(); // empty constructor
        ~NBild(){} // destructor
        NBild operator= (const vector<vector<int>>& n) {
            *bildVektor = n;
            return (*bildVektor);
        }

        int operator() (unsigned row, unsigned col) const {
            return (*bildVektor)[row][col];
        }
        int &operator() (unsigned row, unsigned col) {
            return (*bildVektor)[row][col];
        }

        unsigned getRows();
        unsigned getCols();
        vector <vector <int>> getMatrix();
        void importData(string);
        void exportData(string);
        void print();
};


/*!
 * \brief The CBild class represents Block A and B
 * in visual cryptography pixel point system
 * and imports and exports data with the same
 * system as in 2a.
 * initialization with '1' for black, '0' for white
 */

class CBild : public NBild { // CBild reuses NBild functions but checks first whether they adhere to a CBild structure with a and b blocks
    private:
        vector<vector<int>> * bildVektor;
    public:
        CBild(vector<vector<int>>); // constructor will be overwritten checking first for the structure
        CBild();
        CBild(unsigned, unsigned); // constructor generating a random key with dimensions from input
        void print();
        void importData(string); // first check if the imported file has a correct structure with a and b blocks
        void exportData(string);
        vector <vector <int>> getMatrix();
};

/*! The following is a procedure that prints a vector.
        Arguments:
        - vector
        Returns:
        - prints out a vector.
*/
void printVector(vector <int> printedVector);

/*! A function printing a 2d matrix. */
void printMat(vector <vector <int>> printedMat);

/*! The following is a function that generates a random matrix of a given size.
        Arguments:
        - x number of rows;
        - y number of columns;
        Returns:
        - 2d vector randMatrix.
*/
vector<vector <int>> genMatrix(unsigned x, unsigned y);

/*! A function that checks if a vector in the input consists of a and b blocks. */
bool check(vector <vector <int>> input);

/*! The following is an encryption function that generates a new slide (folie)
from a given image (bild) and a key (bildVektor).
        Arguments:
        - 2d vector bild;
        - 2d vector bildVektor;
        Returns:
        - 2d vector folie.
*/
vector<vector <int>> encode(
    vector <vector <int> > bild,
    vector <vector <int> > bildVektor);

/*! The following is a decryption function that generates an image (bild) from an
encrypted slide (folie) and a key (bildVektor).
        Arguments:
        - 2d vector folie;
        - 2d vector bildVektor;
        Returns:
        - 2d vector bild.
*/
vector<vector <int>> decode(
    vector <vector <int> > folie,
    vector <vector <int> > bildVektor);

/*! The following is a function that overlays two images (bild1, bild2).
        Arguments:
        - 2d vector bild1;
        - 2d vector bild2;
        Returns:
        - 2d vector overlayImage.
*/
vector<vector <int>> overlay(
    vector <vector <int> > bild1,
    vector <vector <int> > bild2);

#endif // VISUALCRYPT_H

