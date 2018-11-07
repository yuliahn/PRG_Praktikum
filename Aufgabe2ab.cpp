//author: Ischa Tahir (5935200)

#include <iostream>
#include <vector>
#include <fstream> // for import/export in 2ab
#include <string>
#include <sstream>
#include <cstdint> // for 2a index access
#include <random> // for 2c

using namespace std;

/*! Aufgabe 2a
 * class NBild which imports data by using vectors bildVektor
 * and hilfsVektor, reading from line to line through loops,
 * exports data,
 * read and write through index access with operator overload
 * with const and non-const version,
 * black-white-code set in 2b
 */
class NBild{
    // attribute names
    vector<vector<int>> bildVektor;
    vector<int> hilfsVektor;

    // index access read & write
    int operator[] (int bildVektor) const { // const version
    return bildVektor;
    }
    int &operator[](int bildVektor) { // non-const version
    return bildVektor;
    }

    public:
    NBild();
    // Import text file
    int import_data() {
        string line;
        ifstream myfile("bild.txt");
        if(myfile.is_open()) {
            while(getline(myfile, line))
            {
                /*! line[i] element goes through loop line by line
                 *  and is converted to int with k_convert */
                for (int i = 0; i < line.size(); i++) {
                    stringstream k_to_int(line);
                    int k_convert;
                    k_to_int >> k_convert;
                    //put to hilfsVektor and than to bildVektor
                    //and delete hilfsVektor
                    hilfsVektor.push_back(k_convert);
                    }
                    for (vector<int>::iterator j = hilfsVektor.begin(); \
                         j != hilfsVektor.end(); ++j)
                        bildVektor.push_back(hilfsVektor);
                    hilfsVektor.clear();
            }
            myfile.close();
        }
    }
    // Export text file
    int export_data() {
        string exportText;
        for (int i=0; i < bildVektor.size(); i++) {
               for (vector<int>::iterator j = bildVektor[i].begin(); \
                    j != bildVektor[i].end(); ++j){
                   exportText.append(to_string(*j));
                   }
               exportText.append("\n");
               ofstream myfile;
               myfile.open("write_file.txt");
               myfile << exportText;
               myfile.close();
        }
    }
};

/*!
 * \brief The CBild class represents Block A and B
 * in visual cryptography pixel point system
 * and imports and exports data with the same
 * system as in 2a.
 * initialization with '1' for black, '0' for white
 */

class CBild {
    // initialize '1' for black, '0' for white
    vector<vector<int>> Bild_A = {{1,0}, {0,1}};
    vector<vector<int>> Bild_B = {{0,1}, {1,0}};
    vector<int> hilfsVektorA;
    vector<int> hilfsVektorB;

    CBild();
    int import_blocks() {
        string line_blocks;
        ifstream myfile("bild.txt");
        if(myfile.is_open()) {
            while(getline(myfile, line_blocks))
            {
                /*! line_blocks[i] element goes through loop line by line
                 *  and is converted to int with k_convert */
                for (int i = 0; i < line_blocks.size(); i++) {
                    stringstream kb_to_int(line_blocks);
                    int k_convert_block;
                    kb_to_int >> k_convert_block;
                    /* put to hilfsVektorA and than to Block_A
                    put to hilfsVektorB and than to Block_B
                    than delete hilfsVektorA and hilfsVektorB */
                    if(line_blocks == "1 0 0 1") {
                        hilfsVektorA.push_back(k_convert_block);
                    }
                    if(line_blocks == "0 1 1 0") {
                        hilfsVektorB.push_back(k_convert_block);
                    }
                }
                    for (vector<int>::iterator a = hilfsVektorA.begin(); \
                         a != hilfsVektorA.end(); ++a)
                        Bild_A.push_back(hilfsVektorA);
                    hilfsVektorA.clear();

                    for (vector<int>::iterator b = hilfsVektorB.begin(); \
                         b != hilfsVektorB.end(); ++b)
                        Bild_B.push_back(hilfsVektorB);
                    hilfsVektorB.clear();
            }
            myfile.close();
        }
    }

    // exports blocks A and B
    int export_blocks() {
        string exportblockTextA;
        string exportblockTextB;
        // Export Block A
        for (int i=0; i < Bild_A.size(); i++) {
               for (vector<int>::iterator a = Bild_A[i].begin(); \
                    a != Bild_A[i].end(); ++a){
                   exportblockTextA.append(to_string(*a));
                   }
               exportblockTextA.append("\n");
               ofstream myfile;
               myfile.open("write_file.txt");
               myfile << exportblockTextA;
               myfile.close();
        }
        // Export Block B
        for (int i=0; i < Bild_B.size(); i++) {
               for (vector<int>::iterator b = Bild_B[i].begin(); \
                    b != Bild_B[i].end(); ++b){
                   exportblockTextB.append(to_string(*b));
                   }
               exportblockTextB.append("\n");
               ofstream myfile;
               myfile.open("write_file.txt");
               myfile << exportblockTextB;
               myfile.close();
        }
    }
};

/* references:
 * http://www.cplusplus.com/doc/tutorial/files/
 * https://www.geeksforgeeks.org/converting-strings-numbers-cc/
 * https://www.perforce.com/resources/qac/high-integrity-cpp-coding-standard
 */
