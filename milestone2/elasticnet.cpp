#include "elasticnet.h"
#include <istream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <math.h>
#define PI 3.14159265


using namespace std;

ElasticNet :: ElasticNet(double radius, double cvRatio) {
    this->radius = radius;
    this->cvRatio = cvRatio;
}


void ElasticNet :: addCity(double y,double z){
    City x;

    int counter = 0;
    for (int m = 0; m < cities.size(); m++){
            double coordx = cityCoordX[m] - y;
            double coordy = cityCoordY[m] -z;
            double distance = sqrt((coordx * coordx) + (coordy * coordy));
            if ((distance <= 2 * nZiel)){
                counter++;
            }
    }
    if(counter == 0){
        x.coord = {y,z};
        cities.push_back(x);
        cityCoordX.push_back(y);
        cityCoordY.push_back(z);
    }

}

void ElasticNet :: setCentroid(){
    double x = 0,y = 0,counterx = 0,countery = 0, r;

    for(int i = 0; i < cityCoordX.size(); i++){
        x += cityCoordX[i];
        counterx++;
    }

    for(int i = 0;i < cityCoordY.size(); i++){
        y += cityCoordY[i];
        countery++;
    }
    centroid0 = x/counterx;
    centroid1 = y/countery;
    cout << "Centroid: " << centroid0 << ", " << centroid1 << endl;

}

void ElasticNet :: addNodes(){
    double x = 0;
    double y = 0;
    double theta = 0;
    double gamma = (2 * PI)/numOfNodes;
    nodes.clear();
    nodeCoordX.clear();
    nodeCoordY.clear();
    // for gamma := rotation angle in radians
    for (int i = 0; i < numOfNodes; i++){
        if(i == 0){
            Node i;
            x = centroid0 + radius;
            //x = centroid0+radius*100;
            y = centroid1;
            i.coord = {x, y};
            nodes.push_back(i);
            nodeCoordX.push_back(x);
            nodeCoordY.push_back(y);
        }else{
            Node i;
            theta += gamma;
            x += (radius) * cos(theta);
            y += (radius) * sin(theta);
            //x += (radius*100) * cos(theta);
            //y += (radius*100) * sin(theta);
            i.coord = {x,y};
            nodes.push_back(i);
            nodeCoordX.push_back(x);
            nodeCoordY.push_back(y);
        }
    }
}

void ElasticNet :: setNumOfNodes(){
    numOfNodes = getNumOfCities() * getCvRatio();
}

void ElasticNet :: updateCoord(int i, vector <double> values) {
    nodes[i].coord = values;
}

void ElasticNet :: preprocess(){
    for (int n = 0; n < nodes.size(); n++)
        for(int m = 0; m < cities.size(); m++){
            double coordx = cityCoordX[m] - nodeCoordX[n];
            double coordy = cityCoordY[m] - nodeCoordY[n];
            double distance = sqrt((coordx * coordx) + (coordy * coordy));
            if (distance <= nZiel){
                break;
            }
        }
}
