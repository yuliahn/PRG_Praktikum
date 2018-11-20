#include "iterable.h"

Iterable::Iterable()
{

}

void Iterable::apply()
{

}

void Iterable::updateK(unsigned iteration)
{
    k = max( pow( 0.99, iteration/50 ) * k0, 0.01 );
}

void Iterable::updateT()
{
    t=2*pow(k,2);
}

void Iterable::updateV()
{
    getV().clear();
    for (unsigned i=0; i<net.getCities().size(); i++) {
        vector <double> distances; // saves all euclidian distances between city i and all nodes
        double sum = 0; // saves the sum of all exp(...) in denominator
        for (unsigned j=0; j<net.getNodes().size(); j++) {
            double distance = euclDistance(net.getCities()[i], net.getNodes()[j]);
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


void Iterable::transform()
{
    for (unsigned a=0; a < net.getNodes().size(); a++) {
        vector <double> deltaA;
        vector <double> sum = {0, 0};
        for (unsigned i=0; i < net.getCities().size(); i++) {
            sum = add (sum, multiply( getV()[i][a], subtract(net.getCities()[i].coord, net.getNodes()[a].coord)));
        }
        vector <double> distance = subtract ( add ( net.getNodes()[a-1].coord, net.getNodes()[a+1].coord ), multiply ( 2, net.getNodes()[a].coord) );
        deltaA = add ( multiply (alpha, sum), multiply (k*beta, distance));
        // Update coordinates:
        net.getNodes()[a].coord = deltaA;
    }
}


vector <double> add (vector <double> a, vector <double> b)
{
    vector <double> result;
    result.push_back(a[0]+b[0]);
    result.push_back(a[1]+b[1]);
    return result;
}

vector <double> subtract (vector <double> a, vector <double> b)
{
    vector <double> result;
    result.push_back(a[0]-b[0]);
    result.push_back(a[1]-b[1]);
    return result;
}

vector <double> multiply (double a, vector <double> b)
{
    vector <double> result;
    result.push_back(a*b[0]);
    result.push_back(a*b[1]);
    return result;
}


double euclDistance(City city, Node node)
{
    double distance = pow ((city.coord[0] - node.coord[0]), 2) + pow ((city.coord[1] - node.coord[1]), 2);
    return distance;
}
