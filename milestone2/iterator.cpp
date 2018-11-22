#include "iterator.h"

Iterator::Iterator()
{

}


void Iterator::solve(Iterable object, double etaZiel)
{
    for (unsigned i=0; i < iterMax; i++) {
        double etaN = object.apply();
        if (etaN <= etaZiel) { // gewuenschte Genauigkeit erfuellt anstatt condition
            break;
        } else {
            updateIter();
        }
    }
}

