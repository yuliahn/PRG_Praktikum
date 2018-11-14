#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include "matrix.h"

using namespace std;
void matrix_creator(), matrix_printer(), matrix_printer2(), interface(), interface_class(matrix old_matrix), timestep(matrix new_matrix);

int * pa = new int[900];

constexpr int dim = 2, size = 29;
double carray[size][dim];


int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    matrix old_Matrix(30,30);

    string task;
    int rows;
    int cols;
    int state;
    string dir;

    cout<<"Wählen sie aus Aufgabe b oder e(Tippe b oder e ein)";
    cin>>task;
    if (task == "b"){ //Asking which Task
        matrix_creator();
        interface(); //Start interface of task a
    }else{
        cout<<"Wollen sie eine Matrix laden?(1 Ja, 0 Nein)"<<endl;
        cin>>state;
        if(state == 1){
            cout<<"Bitte geben sie den Pfad ein:"<<endl;
            cin>>dir;
            interface_class(old_Matrix.importData(dir));
        }else{}
            cout<<"Wie viele Zeilen soll ihre Matrix betragen?"; //Define rows and cols
            cin>>rows;
            cout<<"Wie viele Spalten soll ihre Matrix betragen?";
            cin>>cols;
            matrix old_Matrix(rows,cols);  //create the matrix
            interface_class(old_Matrix);  //start interface of task b
    }

    return a.exec();
}


void matrix_creator(){   //creates the matrix with a for loop
    srand((unsigned)time(NULL));
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++){
            if(j == 29){
                carray[i][j] = (rand() % (10));
            }else{
                carray[i][j] = (rand() % (10));
            }
        }
}

void matrix_printer(){  //prints static matrix
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++){
            if(j==29){
                cout<<carray[i][j]<<endl; //endl after 29th element to show it as a matrix
            }else{
                cout<<carray[i][j]<<(" ");
            }
        }
    interface();  //call interface again to give user the possibility to choose another matrix
    cout<<endl;
}

void matrix_printer2(){  //prints dynamic matrix
    int a = 0;
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++){
            if(j==29){
                pa[a] = carray[i][j];  //copy static matrix into the dynamic matrix
                cout<<pa[a]<<endl;
                a++;
            }else{
                pa[a] = carray[i][j];
                cout<<pa[a]<<(" ");
                a++;
            }
        }
    interface();  //call interface again to give user the possibility to choose another matrix
    cout<<endl;
}

void interface(){   //the interface
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


void interface_class(matrix old_matrix){
    int i = 0;
    int arrayChoice[10];
    int splitNumber;
    string usersChoice;

    cout << "Tippen sie Zeile,Spalte,Zustand ein durch Komma getrennt.[Zeilen(1-"<<old_matrix.getRows()<<"), Reihen(1-"<<old_matrix.getCols()<<") und Zustand (1 = Leben, 0 = Tot)] ";
    cout <<endl<<"--->";
    cin >> usersChoice;

    string item;

    istringstream iss(usersChoice);
    while (getline(iss, item, ',')) {
        splitNumber = stoi(item, nullptr, 10);
        arrayChoice[i] = splitNumber;
        i++;
    }

    if(arrayChoice[0]-1 > old_matrix.getRows() or arrayChoice[1]-1 > old_matrix.getCols()){
        cout<<("Es gibt nur", old_matrix.getRows(),"Zeilen und ", old_matrix.getCols(),"Spalten")<<endl;
        interface_class(old_matrix);  //dont allow to set number outside the matrix
    }else if(arrayChoice[2]==0 or arrayChoice[2]==1){
        old_matrix.setElement(arrayChoice[0]-1,arrayChoice[1]-1, arrayChoice[2]); //set number into matrix
        cout<<("Moechten sie weiter spielen oder speichern und das Spiel verlassen?(1 - Weiterspielen, 0 - Speichern)");
        cin>>i;
        if(i == 1){
            interface_class(old_matrix);
        }else{
            string dir;
            cout<<"______________________________________________________"<<endl;
            cout<<endl;
            cout<<"So sieht ihre erstellte Matrix aus:"<<endl;
            timestep(old_matrix);  //use the timestep function to start game
        }
    }else{
        cout<<"FALSCHE EINGABE!!";
        interface_class(old_matrix);
    }

}

void timestep(matrix new_matrix){  //does one time step of evolution (Game of Life)
    new_matrix.createString();
    string state;
    cout<<endl<<("Geben sie eine 1 ein um einen Zeitschritt durchzufuehren und ENDE um das Spiel zu beenden..")<<endl;
    cout<<"--->";
    cin>>state;
    if (state == "1"){
        new_matrix.evolution();
        new_matrix = new_matrix.evolution();
        timestep(new_matrix);
    }else if(state == "ENDE" or state == "ende"){
        cout<<endl<<"Das Spiel is vorbei! Dies ist ihre finale Matrix."<<endl;
        new_matrix.createString();

    }else{
        timestep(new_matrix);
    }


}
