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

    double apply(); // returns etaN

    double getK() {return this->k;}
    double getT() {return this->t;}
    vector <vector <double>> getV() {return this->v;}

    ElasticNet getElasticNet() {return this->net;}

    void setAlpha(double value) {alpha = value;}
    void setBeta(double value) {beta = value;}
    void setK0(double value) {k0 = value;}
    void setElasticNet(ElasticNet object) {net = object;}

    void updateK(unsigned iteration); // k = max( pow( 0.99, iteration/50 ) * k0, 0.01 )
    void updateT(); // t=2*pow(k,2)
    void updateV();

    //void transform(); // replaced with apply()

private:
    double k0;
    ElasticNet net;
    double alpha;
    double beta;
    double k;
    double t;
    vector <vector <double>> v; // Cities x Nodes => vector <vector <double>>
};

/* Help functions */
double euclDistance(City city, Node node);
vector <double> add (vector <double> a, vector <double> b);
vector <double> subtract (vector <double> a, vector <double> b);
vector <double> multiply (double a, vector <double> b);

#endif // ITERABLE_H
