#include "elasticnet.h"
#include <istream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <math.h>
#define PI 3.14159265


using namespace std;


void ElasticNet :: addCity(double y,double z){
    City x;
    x.coord = position (y,z);
    cities.push_back(x);
    first_coord.push_back(y);
    second_coord.push_back(z);

}


void ElasticNet :: setCentroid(){
    int x = 0,y = 0,counterx = 0,countery = 0, r;
    vector<int>::iterator it;

    for(it = first_coord.begin();it != first_coord.end(); it++){
        x += *it;
        counterx++;
        r = *it;
    }

    for(it = second_coord.begin();it != second_coord.end(); it++){
        y += *it;
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
        }else{
            Node i;
            x += radius * cos(y + gamma);
            y += radius * sin(gamma);
            i.coord = position(x,y);
            nodes.push_back(i);
        }
    }
}

void ElasticNet :: setNumOfNodes(){
    numOfNodes = getNumOfCities() * getCvRatio();
}

ElasticNet::ElasticNet()
{


}
