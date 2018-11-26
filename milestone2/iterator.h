#ifndef ITERATOR_H
#define ITERATOR_H

#include "elasticnet.h"
#include "iterable.h"

class Iterator
{
public:
    Iterator() {}
    Iterator(
            const unsigned iterMax,
            const double etaZiel,
            Iterable iterable
            );
    ~Iterator() {}

    void solve();
    void updateIter() {this->iteration++;}

    void setIterObject(Iterable object) {iterable = object;}
    void setIterMax(double value) {iterMax = value;}
    void setEtaZiel(double value) {etaZiel = value;}


private:
    unsigned iterMax;
    unsigned iteration = 0;
    double etaZiel;
    Iterable iterable;
};

#endif // ITERATOR_H
