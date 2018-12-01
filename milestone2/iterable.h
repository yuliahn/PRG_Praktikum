#ifndef ITERABLE_H
#define ITERABLE_H

#include "code_draft.cpp"

#include "elasticnet.h"
#include <cmath> // for power: pow()
#include <algorithm> // for max
#include <math.h> // for exp

class Iterable {
public:
    Iterable() {}
    Iterable(ElasticNet net, double k0, const double alpha, const double beta);
    ~Iterable() {}

    double apply(int currentIteration); // returns etaN

    double getK() {return this->k;}
    double getT() {return this->t;}
    int getIteration() {return this->iteration;}
    vector <vector <double>> getV() {return this->v;}

    ElasticNet getElasticNet() {return this->net;}
    double getAlpha() {return this->alpha;}
    double getBeta() {return this->beta;}

    void setAlpha(double value) {this->alpha = value;}
    void setBeta(double value) {this->beta = value;}
    void setK0(double value) {this->k0 = value;}
    void setElasticNet(ElasticNet object) {this->net = object;}

    void updateK(); // k = max( pow( 0.99, iteration/50 ) * k0, 0.01 )
    void updateT(); // t=2*pow(k,2)
    void updateV();
    void updateIteration(int value) {this->iteration = value;}

private:
    double k0;
    ElasticNet net;
    double alpha;
    double beta;
    double k;
    double t;
    int iteration = 0;
    vector <vector <double>> v; // Cities x Nodes => vector <vector <double>>
};

/* Help functions */
double euclDistance(City city, Node node);
vector <double> add (vector <double> a, vector <double> b);
vector <double> subtract (vector <double> a, vector <double> b);
vector <double> multiply (double a, vector <double> b);

#endif // ITERABLE_H
