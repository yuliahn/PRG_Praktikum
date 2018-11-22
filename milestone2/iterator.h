#ifndef ITERATOR_H
#define ITERATOR_H

#include "elasticnet.h"
#include "iterable.h"

class Iterator
{
public:
    Iterator();
    Iterator(
            const unsigned iterMax,
            const double etaZiel,
            Iterable object
            );
    ~Iterator();

    void solve(Iterable object, double etaZiel);
    void updateIter() {this->iteration++;}
private:
    const unsigned iterMax = iterMax;
    unsigned iteration = 0;
    double etaZiel = etaZiel;
};

#endif // ITERATOR_H
