/**
 * elasticnet.cpp
 * Purpose: Generate an elastic net.
 *
 * @author Blerton Osmani
 * @author Zeynep Yavas
 */

#include "elasticnet.h"
#include <istream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <math.h>
#include <iostream>
#define PI 3.14159265


using namespace std;

ElasticNet :: ElasticNet(double radius, double cvRatio) {
    //function to define radius and cv Ratio of the elastic net
    this->radius = radius;
    this->cvRatio = cvRatio;
}


void ElasticNet :: addCity(double y,double z){
    //function to add a city
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
    //function to determine the centroid of the cities (and nodes of the elastic net)
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
    //function to add nodes
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
            i.coord = {x,y};
            nodes.push_back(i);
            nodeCoordX.push_back(x);
            nodeCoordY.push_back(y);
        }
    }
}

void ElasticNet :: setNumOfNodes(){
    //function to calculate the number of nodes
    numOfNodes = getNumOfCities() * getCvRatio();
}

void ElasticNet :: updateCoord(int i, vector <double> values) {
    //function to update the x and y coordinates of nodes
    nodes[i].coord = values;
    nodeCoordX[i] = values[0];
    cout << "NodeCoordX: " << nodeCoordX[i] << endl;
    nodeCoordY[i] = values[1];
    cout << "NodeCoordY: " << nodeCoordY[i] << endl;
}

void ElasticNet :: preprocess(){
    /*function to not recalculate the coordinates of nodes when the distance 
    of the nodes to the nearest city is less than a predetermined limit "nZiel"*/
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

void ElasticNet :: clearCities() {
    //function to clear cities
    cities.clear();
    cityCoordX.clear();
    cityCoordY.clear();
}

void ElasticNet :: clearNodes() {
    //function to clear nodes
    nodes.clear();
    nodeCoordX.clear();
    nodeCoordY.clear();
    numOfNodes = 0;
}
