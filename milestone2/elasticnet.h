#ifndef ELASTICNET_H
#define ELASTICNET_H

#include <vector>
#include <tuple>
//#include <unordered_set>

using namespace std;


struct City {
    double x;
    double y;
    bool visited = 0;
};


struct Node { // nodes have a graph structure, every node has two neighbors: father->node->child
    double x;
    double y;
    // position delta; ???
};

class ElasticNet {
public:
    typedef tuple <double, double> position;

    ElasticNet();
    ElasticNet(double radius, double cvRatio);
    ~ElasticNet();

    vector <City> getCities() {return this->cities;}
    vector <Node> getNodes() {return this->nodes;}
    position getCentroid() {return this->centroid;}
    double getRadius() {return this->radius;}
    double getCvRatio() {return this->cvRatio;}
    unsigned getNumOfCities() {return this->cities.size();} // unordered_set::size ???
    unsigned getNumOfNodes() {return this->nodes.size();}

    void addCity();
    void addNode();
    void setCentroid(); // (x,y) = ((x1+...+xn)/2, (y1+...+yn)/2) f.a. i in {1,2,...,n} city coordinates
    void setNumOfNodes(); // getNumofCities, getCvRatio => numOfNodes = getNumOfCities*getCvRatio
    void generateNet();

private:
    position centroid;
    double radius = radius;
    double cvRatio = cvRatio;
    vector <City> cities; // data structure to sequentially save all generated nodes: father->node->child
    vector <Node> nodes;
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