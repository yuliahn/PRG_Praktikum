#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include "matrix.h"

using namespace std;
void matrix_creator(), matrix_printer(), matrix_printer2(), interface();

int * pa = new int[900];

constexpr int dim = 2, size = 29;
double carray[size][dim];

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    Matrix old_Matrix(30,30);
    Matrix new_Matrix(30,30);


    old_Matrix.setElement(0,0, 7);
    old_Matrix.setElement(0,1, 7);
    old_Matrix.setElement(1,0, 7);


    cout<<old_Matrix.getElement(1,0);
    cout<<old_Matrix.getElement(29,3)<<endl;
    cout<<old_Matrix.getElement(29,2)<<endl;

    old_Matrix.createString();



    matrix_creator();
    //interface();
    return a.exec();
}


void matrix_creator(){
    srand((unsigned)time(NULL));
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++){
            if(j==29){
                carray[i][j]=(rand()%(10));
            }else{
                carray[i][j]=(rand()%(10));
            }
        }
}

void matrix_printer(){
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++){
            if(j==29){
                cout<<carray[i][j]<<endl;
            }else{
                cout<<carray[i][j]<<(" ");
            }
        }
    interface();
    cout<<endl;
}

void matrix_printer2(){
    int a = 0;
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++){
            if(j==29){
                pa[a] = carray[i][j];
                cout<<pa[a]<<endl;
                a++;
            }else{
                pa[a] = carray[i][j];
                cout<<pa[a]<<(" ");
                a++;
            }
        }
    interface();
    cout<<endl;
}

void interface(){
    int wahl_matrix;
    cout<<("1 - STATISCHE 30x30 MATRIX.")<<endl;
    cout<<("2 - DYNAMISCHE 30x30 MATRIX.")<<endl;
    cout<<("3 - PROGRAMM SCHLIESSEN")<<endl;
    cout<<("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")<<endl;;
    cout<<("IHRE EINGABE :");
    cin>>wahl_matrix;
    if(wahl_matrix == 1){
        cout<<("STATISCHE MATRIX 30x30 :")<<endl;
        matrix_creator();
        matrix_printer();
    }else if(wahl_matrix == 2){
        cout<<("DYNAMISCHE MATRIX 30x30 :")<<endl;
        matrix_printer2();
    }else if(wahl_matrix == 3){
        exit(0);
    }else{
        interface();
    }
}

size_t Matrix::getRows() const{
    return this->rows;
}

size_t Matrix::getCols() const{
    return this->cols;
}

void Matrix::setElement(size_t row, size_t col, double value){
    this->data[row][col] = value;
}

double Matrix::getElement(size_t row, size_t col) const{
    return this->data[row][col];
}

void Matrix::createString(){
    int a = 0;
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++){
            if(a % 29 == 0 and a != 0){
                std::ostringstream strs;
                strs << getElement(i,j);
                std::string str = strs.str();
                this->old_matrix = this->old_matrix + str;
                cout<<this->old_matrix[a]<<endl;
                a++;
            }else{
                std::ostringstream strs;
                strs << getElement(i,j);
                std::string str = strs.str();
                this->old_matrix = this->old_matrix + str;
                cout<<this->old_matrix[a]<<" ";
                a++;
            }
        }
}

Matrix::Matrix(size_t p_rows, size_t p_cols) : rows(p_rows),cols(p_cols) {
    this->data = std::vector<Vector>(p_rows, Vector(p_cols));
}

Matrix::Matrix(const Matrix &b) : cols(b.cols), rows(b.rows){
    this->data = b.data;
}

Matrix::Matrix() : Matrix(0,0) {}
