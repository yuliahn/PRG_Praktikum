/**
 * iterator.cpp
 * Purpose: Iterate recalculation of elastic net until
 * a maximum number of iterations or acceptable distance
 * between nodes and cities is reached.
 *
 * @author Yulia Kim
 */

#include "iterator.h"

Iterator::Iterator(const unsigned iterMax,
                   const double etaZiel,
                   Iterable iterable)
{
    this->iterMax = iterMax;
    this->etaZiel = etaZiel;
    this->iterable = iterable;
}

/**
 * @brief Iterator::solve
 * Iterates recalculation of elastic net.
 */
void Iterator::solve()
{
    for (unsigned i=0; i < iterMax; i++) {
        double etaN = iterable.apply(i);
        if (etaN <= etaZiel) {
            break;
        } else {
            updateIter();
        }
    }
}
