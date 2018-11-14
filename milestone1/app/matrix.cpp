//author: Blerton Osmani, 6562597
//author: Zeynep Yavas, 6534774

#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include "matrix.h"

using namespace std;

size_t matrix::getRows() const{
    return this->rows;
}

size_t matrix::getCols() const{
    return this->cols;
}

void matrix::setElement(size_t row, size_t col, double value){
    this->data[row][col] = value;
}

double matrix::getElement(size_t row, size_t col) const{
    return this->data[row][col];
}

void matrix::createString(){
    this->str_matrix.clear();
    int a = 0;
    for(int i=0; i<getRows(); i++)
        for(int j=0; j<getCols(); j++){
            if(j == getCols() - 1){
                std::ostringstream strs;
                strs << getElement(i,j);
                std::string str = strs.str();
                this->str_matrix = this->str_matrix + str;
                cout<<this->str_matrix[a]<<endl;
                a++;
            }else{
                std::ostringstream strs;
                strs << getElement(i,j);
                std::string str = strs.str();
                this->str_matrix = this->str_matrix + str;
                cout<<this->str_matrix[a]<<" ";
                a++;
            }
        }
}

matrix matrix::evolution(){
    matrix new_Matrix(getRows(),getCols());
    for(int i=0; i<getRows(); i++)
        for(int j=0; j<getCols(); j++){
            int counter = 0;
            int a;
            if(i-1 < 0){
                a = getRows()-1;
            }else{
                a = (i-1);
            }
            int b;
            if(i+1 > getRows()-1){
                b = 0;
            }else{
                b = (i+1);
            }
            int c;
            if(j-1 < 0){
                c = getCols()-1;
            }else{
                c = j-1;
            }
            int d;
            if(j+1 > getCols()-1){
                d = 0;
            }else{
                d = j+1;
            }
            if(getElement(a,c) == 1){
                counter++;
            }
            if(getElement(a,j) == 1){
                counter++;
            }
            if(getElement(a,d) == 1){
                counter++;
            }
            if(getElement(i,c) == 1){
                counter++;
            }
            if(getElement(i,d) == 1){
                counter++;
            }
            if(getElement(b,c) == 1){
                counter++;
            }
            if(getElement(b,d) == 1){
                counter++;
            }
            if(getElement(b,j) == 1){
                counter++;
            }
            if(getElement(i,j) == 1){
                if(counter<2 or counter>3){
                    new_Matrix.setElement(i, j, 0);
                }else{
                    new_Matrix.setElement(i, j ,1);
                }
            }else{
                if(counter == 3){
                    new_Matrix.setElement(i, j, 1);
                }else{
                    new_Matrix.setElement(i, j ,0);
                }
            }
        }
    return new_Matrix;
}

matrix matrix::importData(string source) {
    string line;
    vector<int> hilfsVektor;
    ifstream myfile(source);
    if(myfile.is_open()) {
        getline(myfile,line);
        int rows = std::stoi(line);
        getline(myfile,line);
        int cols = std::stoi(line);
        vector<vector<int>> new_matrix;
        matrix final_matrix(rows,cols);
        while(getline(myfile, line))
        {
            //cout << line;
            /*! line[i] element goes through loop line by line
             *  and is converted to int with k_convert */
            for (unsigned i = 0; i < line.size(); i++) {
                if (line[i] == '*'){
                    int k_convert = 1;
                    hilfsVektor.push_back(k_convert);
                }else{
                    int k_convert = 0;
                    hilfsVektor.push_back(k_convert);


                }

            }
            new_matrix.push_back(hilfsVektor);
            hilfsVektor.clear();
}
        myfile.close();
        for (int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++){
                final_matrix.setElement(i,j,new_matrix[i][j]);
            }
        return final_matrix;
    }
}


void matrix::exportData(string target) {
    string exportText;
    ofstream myfile;
    myfile.open(target);
    exportText.append(to_string(getRows()) + "\n");
    exportText.append(to_string(getCols()));
    for (int i = 0; i < getRows(); i++){
        exportText.append("\n");
        for(int j = 0; j < getCols(); j++){
            if (getElement(i,j) == 1){
                exportText.append("*");
            }else{
                exportText.append("o");
            }
    }}
    myfile << exportText;
    myfile.close();
    cout << "Data was successfully exported." << endl;
}
matrix::matrix(size_t p_rows, size_t p_cols) : rows(p_rows),cols(p_cols) {
    this->data = std::vector<Vector>(p_rows, Vector(p_cols));
}

matrix::matrix(const matrix &b) : cols(b.cols), rows(b.rows){
    this->data = b.data;
}

matrix::matrix() : matrix(0,0) {}
