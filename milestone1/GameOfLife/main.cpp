#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include "matrix.h"

using namespace std;
void matrix_creator(), matrix_printer(), matrix_printer2(), interface(), interface_class(Matrix old_matrix), timestep(Matrix new_matrix);

int * pa = new int[900];

constexpr int dim = 2, size = 29;
double carray[size][dim];


int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);


    Matrix old_Matrix(30,30);

    interface_class(old_Matrix);



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
    this->str_matrix.clear();
    int a = 0;
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++){
            if(j == 29){
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

void interface_class(Matrix old_matrix){
    int row;
    int col;
    int state = 3;
    //cout<<("Wilkommen bei Game of Life.")<<endl;
    //cout<<("2 - DYNAMISCHE 30x30 MATRIX.")<<endl;
    //cout<<("3 - PROGRAMM SCHLIESSEN")<<endl;
    cout<<("Bitte Zeile eingeben:");
    cin>>row;
    cout<<("Bitte Spalte eingeben:");
    cin>>col;
    cout<<("Bitte geben sie eine 0 für Tod ein oder eine 1 für Leben :");
    cin>>state;
    if(row-1 > old_matrix.getRows() or col-1 > old_matrix.getCols()){
        cout<<("Es gibt nur", old_matrix.getRows(),"Zeilen und ", old_matrix.getCols(),"Spalten")<<endl;
        interface_class(old_matrix);
    }else if(state==0 or state==1){
        old_matrix.setElement(row-1,col-1, state);
        interface_class(old_matrix);
    }else{
        timestep(old_matrix);
    }
}

void timestep(Matrix new_matrix){
    new_matrix.createString();
    string state;
    cout<<("Drücken sie Enter um einen Zeitschritt durchzuführen.");
    cin>>state;
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    if (state == "1"){
        new_matrix.evolution();
        new_matrix = new_matrix.evolution();
        timestep(new_matrix);
    }else if(state == "ENDE" or state == "ende"){
        new_matrix.createString();
        cout<<"Das Spiel is vorbei!";
    }else{
        timestep(new_matrix);
    }


}

Matrix Matrix::evolution(){
    Matrix new_Matrix(getRows(),getCols());
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
                }
            }else{
                if(counter == 3){
                    new_Matrix.setElement(i, j, 1);
                }
            }
        }
    cout<<endl;
    cout<<endl;
    return new_Matrix;
}

Matrix::Matrix(size_t p_rows, size_t p_cols) : rows(p_rows),cols(p_cols) {
    this->data = std::vector<Vector>(p_rows, Vector(p_cols));
}

Matrix::Matrix(const Matrix &b) : cols(b.cols), rows(b.rows){
    this->data = b.data;
}

Matrix::Matrix() : Matrix(0,0) {}
