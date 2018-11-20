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
            ElasticNet net,
            Iterable object
            );
    ~Iterator();

    void solve(Iterable object, bool condition);
    void transform(); // calculate delta y
    void updateIter() {this->iteration++;}
private:
    const double k0 = k0;
    const unsigned iterMax = iterMax;
    const double alpha = alpha;
    const double beta = beta;
    unsigned iteration = 0;
};

#endif // ITERATOR_H
