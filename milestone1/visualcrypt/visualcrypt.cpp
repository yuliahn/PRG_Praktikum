//author: Ischa Tahir (5935200)
//author: Yulia Kim (6289317)



#include "visualcrypt.h"


using namespace std;

/*The following is a procedure that prints a vector.
        Arguments:
        - vector
        Returns:
        - prints out a vector.
*/
void printVector(vector <int> printedVector){
    for (vector<int>::iterator i = printedVector.begin(); i != printedVector.end(); ++i){
        cout << *i;
    }
}

void printMat(vector <vector <int>> printedMat){
    for (unsigned it=0; it < (printedMat).size(); it++){
        for (vector<int>::iterator i = (printedMat)[it].begin(); i != (printedMat)[it].end(); ++i){
            cout << *i;
            }
            cout << endl;
    }
}

/*The following is a function that generates a random matrix of a given size.
        Arguments:
        - x number of rows;
        - y number of columns;
        Returns:
        - 2d vector randMatrix.
*/
vector<vector <int>> genMatrix(unsigned x, unsigned y){
    vector < vector<int> > randMatrix;
    vector <int> helpVec;
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            int a=rand()%2;
            helpVec.push_back(a);
        }
        randMatrix.push_back(helpVec);
        helpVec.clear();
    }
    return randMatrix;
}

bool check(vector <vector <int>> input) {
    //read all lines of input and check that each
    for (unsigned i=0; i<input.size(); i++){
        for (unsigned j=0; j<input[i].size(); j++){
            if ((input[i*2][j*2]==1) && (input[i*2+1][j*2]==0) && (input[i*2][j*2+1]==0) && (input[i*2+1][j*2+1]==1)){ // block a
                return true;
            } else if ((input[i*2][j*2]==0) && (input[i*2+1][j*2]==1) && (input[i*2][j*2+1]==1) && (input[i*2+1][j*2+1]==0)) {
                return true;
            } else {
                return false;
            }
        }
    }
}

/*The following is an encryption function that generates a new slide (folie)
from a given image (bild) and a key (bildVektor).
        Arguments:
        - 2d vector bild;
        - 2d vector bildVektor;
        Returns:
        - 2d vector folie.
*/
vector<vector <int>> encode(
    vector <vector <int> > bild,
    vector <vector <int> > bildVektor){
        // Initialize a vector of folie
        vector < vector<int> > folie;

        for (unsigned i=0; i < bild.size(); i++){
            folie.resize( bild.size()*2 );
            for (unsigned j=0; j < bild[i].size(); j++){

                if ((bild[i][j]==1) && (bildVektor[i*2][j*2] == 1)){

                    folie[i*2].insert( folie[i*2].end(), b[0].begin(), b[0].end());
                    folie[i*2+1].insert( folie[i*2+1].end(), b[1].begin(), b[1].end());

                    //cout << "Block b was inserted in folie " << i*2 << i*2+1 << endl;

                } else if ((bild[i][j]==0) && (bildVektor[i*2][j*2] == 1)){

                    folie[i*2].insert( folie[i*2].end(), a[0].begin(), a[0].end());
                    folie[i*2+1].insert( folie[i*2+1].end(), a[1].begin(), a[1].end());

                } else if ((bild[i][j]==1) && (bildVektor[i*2][j*2] == 0)){

                    folie[i*2].insert( folie[i*2].end(), a[0].begin(), a[0].end());
                    folie[i*2+1].insert( folie[i*2+1].end(), a[1].begin(), a[1].end());

                } else if ((bild[i][j]==0) && (bildVektor[i*2][j*2] == 0)){

                    folie[i*2].insert( folie[i*2].end(), b[0].begin(), b[0].end());
                    folie[i*2+1].insert( folie[i*2+1].end(), b[1].begin(), b[1].end());

                }

            }

        }

        return folie;

    }

/*The following is a decryption function that generates an image (bild) from an
encrypted slide (folie) and a key (bildVektor).
        Arguments:
        - 2d vector folie;
        - 2d vector bildVektor;
        Returns:
        - 2d vector bild.
*/
vector<vector <int>> decode(
    vector <vector <int> > folie,
    vector <vector <int> > bildVektor){
        // Initialize a vector of folie
        vector < vector<int> > bild;

        for (unsigned i=0; i < folie.size(); i+=2){
            bild.resize( folie.size()/2 );

            for (unsigned j=0; j < folie[i].size(); j+=2){

                if ((folie[i][j]==1) && (bildVektor[i][j] == 1)){

                    bild[i/2].insert( bild[i/2].end(), 0);
                    //cout << "Block 0 was inserted in bild " << i/2 << j/2 << endl;

                } else if ((folie[i][j]==1) && (bildVektor[i][j] == 0)){

                    bild[i/2].insert( bild[i/2].end(), 1);

                } else if ((folie[i][j]==0) && (bildVektor[i][j] == 1)){

                    bild[i/2].insert( bild[i/2].end(), 1);

                } else if ((folie[i][j]==0) && (bildVektor[i][j] == 0)){

                    bild[i/2].insert( bild[i/2].end(), 0);

                }

            }

        }

        return bild;

    }

/*The following is a function that overlays two images (bild1, bild2).
        Arguments:
        - 2d vector bild1;
        - 2d vector bild2;
        Returns:
        - 2d vector overlayImage.
*/
vector<vector <int>> overlay(
    vector <vector <int> > bild1,
    vector <vector <int> > bild2){

        // Initialize a vector of overlayImage
        vector < vector<int> > overlayImage;

        // For images of unequal sizes determine maxLength and maxWidth:
        // Resize smaller image and fill missing cells with 0s.
        size_t maxLength;
        if ( bild1.size() > bild2.size() ){ //rows: bild1 > bild2
            maxLength = bild1.size();
            // Add missing rows to smaller image and fill cells with 0s:
            // create a row with bild2[0].size() entries and push_back it maxLength.size times
            vector <int> row;
            row.resize(bild2[0].size(), 0);
            for (unsigned i=0; i < maxLength - bild2.size(); i++){
                bild2.push_back(row);
            }


        } else if ( bild1.size() < bild2.size() ){
            maxLength = bild2.size();
            // Add missing rows to smaller image and fill cells with 0s:
            // create a row with bild2[0].size() entries and push_back it maxLength.size times
            vector <int> row;
            row.resize(bild1[0].size(), 0);
            for (unsigned i=0; i < maxLength - bild1.size(); i++){
                bild1.push_back(row);
            }

        } else {
            maxLength = bild1.size();
        }

        size_t maxWidth;
        if (bild1[0].size() > bild2[0].size() ){
            maxWidth = bild1[0].size();
            // Add missing entries to bild2, row by row
            for (unsigned i=0; i < bild2.size(); i++){
                bild2[i].resize(maxWidth, 0);
            }
        } else {
            maxWidth = bild2[0].size();
            // Add missing entries to bild1, row by row
            for (unsigned i=0; i < bild1.size(); i++){
                bild1[i].resize(maxWidth, 0);
            }
        }

        // Compare images:
        for (unsigned i=0; i<bild1.size(); i++){
            overlayImage.resize( maxLength );
            for (unsigned j=0; j < maxWidth; j++){
                //bool cmp = bild1[i][j] == bild2[i][j];

                if (bild1[i][j] == bild2[i][j]){
                    overlayImage[i].insert( overlayImage[i].end(), bild1[i][j]);

                } else if (bild1[i][j] != bild2[i][j]){
                    overlayImage[i].insert( overlayImage[i].end(), 1);

                }
            }
        }

        return overlayImage;
    }





// Constructor with vector assignment
NBild::NBild(vector <vector <int>> input) {
    this -> bildVektor = new vector <vector <int>>;
    *bildVektor = input;
}

NBild::NBild(){
    this -> bildVektor = new vector <vector <int>>;
}

unsigned NBild::getRows() {
    return (*bildVektor).size();
}
unsigned NBild::getCols() {
    return (*bildVektor)[0].size();
}

// Import text file
void NBild::importData(string source) {
    string line;
    vector<int> hilfsVektor;
    ifstream myfile(source);
    if(myfile.is_open()) {
        while(getline(myfile, line))
        {
            //cout << line;
            /*! line[i] element goes through loop line by line
             *  and is converted to int with k_convert */
            for (unsigned i = 0; i < line.size(); i++) {
                int k_convert = line[i] - 48;
                //put to hilfsVektor and than to bildVektor
                //and delete hilfsVektor
                hilfsVektor.push_back(k_convert);
            }
            (*bildVektor).push_back(hilfsVektor);
            hilfsVektor.clear();
        }
        myfile.close();
    }
}

// Export text file
void NBild::exportData(string target) {
    string exportText;
    for (unsigned i=0; i < (*bildVektor).size(); i++) {
           for (vector<int>::iterator j = (*bildVektor)[i].begin(); \
                j != (*bildVektor)[i].end(); ++j){
               exportText.append(to_string(*j));
               }
           exportText.append("\n");
           ofstream myfile;
           myfile.open(target);
           myfile << exportText;
           myfile.close();
    }
    cout << "Data was successfully exported." << endl;
}

// Print the image
void NBild::print(){
    for (unsigned it=0; it < (*bildVektor).size(); it++){
        for (vector<int>::iterator i = (*bildVektor)[it].begin(); i != (*bildVektor)[it].end(); ++i){
            cout << *i;
            }
            cout << endl;
    }
}

vector <vector <int>> NBild::getMatrix(){
    return (*bildVektor);
}



CBild::CBild(){
        this -> bildVektor = new vector <vector <int>> ;
}

CBild::CBild(vector <vector <int>> input){
    if (check(input)){
        this -> bildVektor = new vector <vector <int>> ;
        *bildVektor = input;
    } else {
        cout << "Wrong format: The image should contain a and b blocks." ;
    }
}

CBild::CBild(unsigned rows, unsigned cols) {
    this -> bildVektor = new vector <vector <int>>;
    (*bildVektor).resize(rows*2);

    //NBild randomMatrix(genMatrix(rows, cols));
    vector < vector<int> > randomMatrix = genMatrix(rows, cols);

    for (unsigned i=0; i < randomMatrix.size(); i++){
        for (unsigned j=0; j < randomMatrix[0].size(); j++){

            if (randomMatrix[i][j]==1){

                (*bildVektor)[i*2].insert( (*bildVektor)[i*2].end(), b[0].begin(), b[0].end());
                (*bildVektor)[i*2+1].insert( (*bildVektor)[i*2+1].end(), b[1].begin(), b[1].end());

            } else if (randomMatrix[i][j]==0){

                (*bildVektor)[i*2].insert( (*bildVektor)[i*2].end(), a[0].begin(), a[0].end());
                (*bildVektor)[i*2+1].insert( (*bildVektor)[i*2+1].end(), a[1].begin(), a[1].end());

            }
        }
    }
}



// Import text file
void CBild::importData(string source) {
    string line;
    vector <vector <int>> tempMatrix;
    vector<int> hilfsVektor;
    ifstream myfile(source);
    if(myfile.is_open()) {
        while(getline(myfile, line))
        {
            /*! line[i] element goes through loop line by line
             *  and is converted to int with k_convert */
            for (unsigned i = 0; i < line.size(); i++) {
                int k_convert = line[i] - 48;
                //put to hilfsVektor and than to bildVektor
                //and delete hilfsVektor
                hilfsVektor.push_back(k_convert);
            }
            tempMatrix.push_back(hilfsVektor);
            hilfsVektor.clear();
        }
        myfile.close();
    }

    if (check(tempMatrix)==1) {
        for (unsigned i = 0; i < tempMatrix.size(); i++) {
            (*bildVektor).push_back(tempMatrix[i]);
        }

    } else {
        cout << "Wrong format: The image should contain a and b blocks." ;
    }
}


// Export text file
void CBild::exportData(string target) {
    string exportText;
    for (unsigned i=0; i < (*bildVektor).size(); i++) {
           for (vector<int>::iterator j = (*bildVektor)[i].begin(); \
                j != (*bildVektor)[i].end(); ++j){
               exportText.append(to_string(*j));
               }
           exportText.append("\n");
           ofstream myfile;
           myfile.open(target);
           myfile << exportText;
           myfile.close();
    }
    cout << "Data was successfully exported." << endl;
}

// Print the image
void CBild::print(){
    for (unsigned it=0; it < (*bildVektor).size(); it++){
        for (vector<int>::iterator i = (*bildVektor)[it].begin(); i != (*bildVektor)[it].end(); ++i){
            cout << *i;
            }
            cout << endl;
    }
}

vector <vector <int>> CBild::getMatrix(){
    return (*bildVektor);
}


/* references:
 * http://www.cplusplus.com/doc/tutorial/files/
 * https://www.geeksforgeeks.org/converting-strings-numbers-cc/
 * https://www.perforce.com/resources/qac/high-integrity-cpp-coding-standard
 */
