#include "iterator.h"

void Iterator::solve()
{
    for (unsigned i=0; i < iterMax; i++) {
        double etaN = iterable.apply();
        if (etaN <= etaZiel) { // gewuenschte Genauigkeit erfuellt anstatt condition
            break;
        } else {
            updateIter();
        }
    }
}

