#include "iterator.h"

Iterator::Iterator(const unsigned iterMax,
                   const double etaZiel,
                   Iterable iterable)
{
    this->iterMax = iterMax;
    this->etaZiel = etaZiel;
    this->iterable = iterable;
}

void Iterator::solve()
{
    for (unsigned i=0; i < iterMax; i++) {
        double etaN = iterable.apply(i);
        if (etaN <= etaZiel) { // gewuenschte Genauigkeit erfuellt anstatt condition
            break;
        } else {
            updateIter();
        }
    }
}
