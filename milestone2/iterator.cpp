#include "iterator.h"

Iterator::Iterator()
{

}


void Iterator::solve(Iterable object)
{
    for (unsigned i=0; i<iterMax; i++) {
        if (1<0) { // gewuenschte Genauigkeit erfuellt anstatt 1<0
            break;
        } else{
            object.apply();
            updateIter();
        }
    }
}
