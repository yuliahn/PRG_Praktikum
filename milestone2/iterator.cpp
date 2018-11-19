#include "iterator.h"

Iterator::Iterator()
{

}


void Iterator::solve(Iterable object)
{
    for (unsigned i=0; i<iterMax; i++) {
        object.apply();
        updateIter();
    }
}
