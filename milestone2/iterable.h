#ifndef ITERABLE_H
#define ITERABLE_H

#include "code_draft.cpp"

#include "elasticnet.h"
#include <cmath> // for power: pow()
#include <algorithm> // for max
#include <math.h> // for exp

class Iterable {
public:
    Iterable();
    ~Iterable();

    void apply();
    void updateK(unsigned iteration, double k0); // k = max( pow( 0.99, iteration/50 ) * k0, 0.01 )
    void updateT(); // t=2*pow(k,2)
    vector <vector <double>> getV() {return this->v;}
    void updateV(vector <City > cities, vector <Node> nodes);
private:
    double k;
    double t;
    vector <vector <double>> v; // Cities x Nodes => vector <vector <double>>
};

/* Help functions */
double euclDistance(City city, Node node);

#endif // ITERABLE_H
