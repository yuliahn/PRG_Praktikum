#include "iterator.h"

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

void Iterator::update()
{
    // replace an updated iterable object
}
