#include "iterator.h"

Iterator::Iterator()
{

}


void Iterator::solve(Iterable object, bool condition)
{
    for (unsigned i=0; i<iterMax; i++) {
        if (condition) { // gewuenschte Genauigkeit erfuellt anstatt condition
            break;
        } else{
            object.apply();
            updateIter();
        }
    }
}
