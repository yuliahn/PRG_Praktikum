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
            const double k0,
            const double alpha,
            const double beta,
            Iterable object
            );
    ~Iterator();

    void solve(Iterable object, bool condition);
    void updateIter() {this->iteration++;}
private:
    const double k0 = k0;
    const unsigned iterMax = iterMax;
    unsigned iteration = 0;
};

#endif // ITERATOR_H
