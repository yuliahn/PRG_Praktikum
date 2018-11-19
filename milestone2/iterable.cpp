#include "iterable.h"

Iterable::Iterable()
{

}

void Iterable::apply()
{

}

void Iterable::updateK(unsigned iteration, double k0)
{
    k = max( pow( 0.99, iteration/50 ) * k0, 0.01 );
}

void Iterable::updateT()
{
    t=2*pow(k,2);
}

double euclDistance(City city, Node node)
{
    double distance = pow ((city.x - node.x), 2) + pow ((city.y - node.y), 2);
    return distance;
}


void Iterable::generateV(vector <City> cities, vector <Node> nodes)
{
    getV().resize(cities.size());
    for (unsigned i=0; i<cities.size(); i++) {
        getV()[i].resize(nodes.size());
        for (unsigned j=0; j<nodes.size(); j++) {
            double numerator = exp( euclDistance(cities[i], nodes[j]) ) / t;
            //double denominator = exp ( - ()) / t;

        }
    }
}


void Iterable::updateV(City city, Node node)
{

}
