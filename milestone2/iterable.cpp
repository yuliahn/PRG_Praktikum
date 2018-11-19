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


void Iterable::updateV(vector <City> cities, vector <Node> nodes)
{
    getV().clear();
    for (unsigned i=0; i<cities.size(); i++) {
        vector <double> distances; // saves all euclidian distances between city i and all nodes
        double sum = 0; // saves the sum of all exp(...) in denominator
        for (unsigned j=0; j<nodes.size(); j++) {
            double distance = euclDistance(cities[i], nodes[j]);
            distances.push_back(exp(distance / t));
            sum += exp( (-1) * distance / t);
        }

        vector <double> impact;
        for (unsigned j=0; j<distances.size(); j++) {
            // remove the current node from the sum, add impact of city i to the v matrix
            impact.push_back(distances[j]/(sum - distances[j]));
        }
        getV().push_back(impact);
    }
}


