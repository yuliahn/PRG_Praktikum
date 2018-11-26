#include "iterable.h"
#include "elasticnet.h"


Iterable::Iterable(ElasticNet net, double k0, double alpha, double beta) {
    this->net = net;
    this->k0 = k0;
    this->alpha = alpha;
    this->beta = beta;
}

void Iterable::updateK(unsigned iteration)
{
    k = max( pow( 0.99, iteration/50 ) * k0, 0.01 );
}

void Iterable::updateT()
{
    t=2*pow(k,2);
}

void Iterable::updateV() // b was treated as all nodes other than a
{
    getV().clear();
    for (unsigned i=0; i<net.getCities().size(); i++) {     // for each city
        vector <double> distances;                          // saves all euclidian distances between city i and all nodes
        double sum = 0;                                     // saves the sum of all exp(...) in denominator (of city i and all nodes)
        for (unsigned a=0; a<net.getNodes().size(); a++) {
            double distance = euclDistance(net.getCities()[i], net.getNodes()[a]);
            double expValue = exp( (-1) * distance / t);    // calculate the value of an exponent function for (i,a)
            distances.push_back(expValue);                  // add the value to the distances vector
            sum += expValue;                                // sum up all exponent values within city i to get denominator
        }

        vector <double> impact; // a row vector for each city with impact on nodes (column entries)
        for (unsigned j=0; j<distances.size(); j++) {
            // add impact of city i to the v matrix
            impact.push_back(distances[j]/sum);
        }
        getV().push_back(impact);
    }
}


double Iterable::apply()
{    
    for (unsigned a=0; a < net.getNodes().size(); a++) {
        vector <double> deltaA;                             // new delta generated in a loop for each node a
        vector <double> sum = {0, 0};                       // sum in the delta term that gets multiplied with alpha
        for (unsigned i=0; i < net.getCities().size(); i++) {
            sum = add (sum, multiply( getV()[i][a], subtract(net.getCities()[i].coord, net.getNodes()[a].coord)));
        }
        vector <double> distance = subtract (               // difference in the delta term that gets multiplied with beta and K
                    add (
                        net.getNodes()[(a-1)%net.getNodes().size()].coord,
                        net.getNodes()[(a+1)%net.getNodes().size()].coord
                    ),
                    multiply (
                        2, net.getNodes()[a].coord
                    )
        );
        deltaA = add ( multiply (alpha, sum), multiply (k*beta, distance));
        // Update coordinates:
        net.getNodes()[a].coord = add(net.getNodes()[a].coord, deltaA);
    }

    //find etaN:
    double etaN = 0; // find max (minDistance) across all cities, set minDistance to 0
    for (unsigned i=0; i < net.getCities().size(); i++) {
        double minCity = net.getRadius() * 2; // find min within each city, set minCity as diameter of the circle in ElasticNet
        for (unsigned a=0; a < net.getNodes().size(); a++) {
            double distance = euclDistance(net.getCities()[i],net.getNodes()[a]);
            minCity = (distance < minCity) ? (distance) : (minCity);
        }
        etaN = (etaN < minCity) ? (minCity) : (etaN);
    }
    return etaN;
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
