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
    x.coord = position (y,z);
    cities.push_back(x);
    cityCoordX.push_back(y);
    cityCoordY.push_back(z);
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
    centroid = position (x/counterx, y/countery);

}

void ElasticNet :: addNode(){
    double x = 0;
    double y = 0;
    double gamma = (2 * PI)/numOfNodes;
    // for gamma := rotation angle in radians
    for (int i = numOfNodes;i < numOfNodes; i++){
        if(i == 0){
            Node i;
            x = centroid[0]+radius;
            y= 0;
            i.coord = position(x, y);
            nodes.push_back(i);
            nodeCoordX.push_back(x);
            nodeCoordY.push_back(y);
        }else{
            Node i;
            x += radius * cos(y + gamma);
            y += radius * sin(gamma);
            i.coord = position(x,y);
            nodes.push_back(i);
            nodeCoordX.push_back(x);
            nodeCoordY.push_back(y);
        }
    }
}

void ElasticNet :: setNumOfNodes(){
    numOfNodes = getNumOfCities() * getCvRatio();
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
