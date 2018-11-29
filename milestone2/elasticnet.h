#ifndef ELASTICNET_H
    #define ELASTICNET_H

//#endif // ELASTICNET_H
#include <vector>
#include <tuple>
#include <unordered_set>
#include <math.h>
#define PI 3.14159265


using namespace std;


struct City {
    vector <double> coord;
    bool visited = 0;
};


struct Node { // nodes have a graph structure, every node has two neighbors: father->node->child
    vector <double> coord;
    // position delta; ???
};

class ElasticNet {
public:
    typedef vector <double> position;

    ElasticNet() {}
    ElasticNet(double radius, double cvRatio);
    ~ElasticNet() {}

    vector <City> getCities() {return this->cities;}
    vector <Node> getNodes() {return this->nodes;}
    position getCentroid() {return this->centroid;}
    double getRadius() {return this->radius;}
    double getCvRatio() {return this->cvRatio;}
    unsigned getNumOfCities() {return this->cities.size();} // unordered_set::size ???
    unsigned getNumOfNodes() {return this->nodes.size();}

    void setRadius(double value) {this->radius = value;}
    void setCVRatio(double value) {this->cvRatio = value;}

    void addCity(double y, double z);
    void addNodes();
    void setCentroid(); // (x,y) = ((x1+...+xn)/2, (y1+...+yn)/2) f.a. i in {1,2,...,n} city coordinates
    void setNumOfNodes(); // getNumofCities, getCvRatio => numOfNodes = getNumOfCities*getCvRatio
    void preprocess();

private:
    position centroid;
    double radius;
    double cvRatio;
    double nZiel = 0.005;
    vector <City> cities; // data structure to sequentially save all generated nodes: father->node->child
    vector <Node> nodes;
    vector <double> cityCoordX;
    vector <double> cityCoordY;
    vector <double> nodeCoordX;
    vector <double> nodeCoordY;
    int numOfNodes;
/*
gamma = (2*pi)/numOfNodes // for gamma := rotation angle in radians
for loop with i=0 to i<numOfNodes:
=> first node with coordinates (x,y) = (centroid) + (0, radius), theta = 0;
=> next node should be created with coordinates: (x + radius*cos(theta + gamma), y + radius*sin(theta + gamma));
all nodes should be pushed (push_back) to "nodes" (vector <Node>);
https://math.stackexchange.com/questions/266832/x-and-y-coordinates-of-circle-giving-a-center-radius-and-angle
*/
};

#endif // ELASTICNET_H
