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
    void update();

    void setIterObject(Iterable object) {iterable = object;}
    void setIterMax(int value) {iterMax = value;}
    void setEtaZiel(double value) {etaZiel = value;}

    int getIterMax() {return this->iterMax;}
    Iterable getIterObject() {return this->iterable;}
    double getEtaZiel() {return this->etaZiel;}

private:
    int iterMax;
    unsigned iteration = 0;
    double etaZiel;
    Iterable iterable;
};

#endif // ITERATOR_H
