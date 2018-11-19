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
    void updateV(City city, Node node); // exp()
private:
    double k;
    double t;
    double v;
};


#endif // ITERABLE_H
