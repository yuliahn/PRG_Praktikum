#include "iterable.h"
#include "elasticnet.h"

#include <iostream>

Iterable::Iterable(ElasticNet net, double k0, double alpha, double beta) {
    this->net = net;
    this->k0 = k0;
    this->alpha = alpha;
    this->beta = beta;
}

void Iterable::updateK()
{
    cout << "Iteration: " << iteration << ", *K0: " << pow( 0.99, iteration/50 ) *k0 << endl;
    k = max( pow( 0.99, iteration/50 ) * k0, 0.01 );
}

void Iterable::updateT()
{
    t=2*pow(k,2);
}

void Iterable::updateV()
{
    v.clear();
    for (unsigned i=0; i<net.getNumOfCities(); i++) {     // for each city
        vector <double> distances;                          // saves all euclidian distances between city i and all nodes
        double sum = 0;                                     // saves the sum of all exp(...) in denominator (of city i and all nodes)
        for (unsigned a=0; a<net.getNumOfNodes(); a++) {
            double distance = pow((euclDistance(net.getCities()[i], net.getNodes()[a])),2);
            double expValue = exp( (-1) * distance / t);    // calculate the value of an exponent function for (i,a)
//            cout << "City: " << i << ", Distance: " << distance << ", T: " << t << ", Value: " << expValue << endl;
            distances.push_back(expValue);                  // add the value to the distances vector
            sum += expValue;                                // sum up all exponent values within city i to get denominator
        }

//        cout << "Sum of nodes in v denominator: " << sum << endl;
        vector <double> impact; // a row vector for each city with impact on nodes (column entries)
        for (unsigned j=0; j<distances.size(); j++) {
            // add impact of city i to the v matrix
            impact.push_back((double) distances[j]/sum);
//            cout << "Impact of City " << i << " on node " << j << ": " << (double) distances[j]/sum << endl;
            if (isnan((double) distances[j]/sum)) {break;}
        }
        v.push_back(impact);
    }
}


double Iterable::apply(int currentIteration)
{
    updateIteration(currentIteration);
    updateK();
    updateT();
    cout << "K: " << k << ", T: " << t << endl;
    updateV();
    for (unsigned a=0; a < net.getNodes().size(); a++) {
//        cout << "Iteration " << a << ". Cities: " << net.getCities().size() << endl;
        vector <double> deltaA;                             // new delta generated in a loop for each node a
        vector <double> sum = {0, 0};                       // sum in the delta term that gets multiplied with alpha
        for (unsigned i=0; i < net.getCities().size(); i++) {

            sum = add (sum, multiply( getV()[i][a], subtract(net.getCities()[i].coord, net.getNodes()[a].coord)));
        }

//        cout << "Sum: " << sum[0] << ", " << sum[1] << endl;

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
        cout << "delta x: " << deltaA[0] << ", delta y: " << deltaA[1] << endl;
        // Update coordinates:
        cout << "Old node coords, x: " << net.getNodes()[a].coord[0] << ", y: " << net.getNodes()[a].coord[1] << endl;
        vector <double> values = {net.getNodes()[a].coord[0] + deltaA[0], net.getNodes()[a].coord[1] + deltaA[1]};
        net.updateCoord(a, values);
        cout << "New node coords, x: " << net.getNodes()[a].coord[0] << ", y: " << net.getNodes()[a].coord[1] << '\n' << endl;
//        cout << "NodeCoordX: " << net.getNodeCoordX(a) << endl;
//        cout << "NodeCoordX: " << net.getNodeCoordY(a) << endl;
    }

    //find etaN:
    double etaN = 0; // find max (minDistance) across all cities, set minDistance to 0
    for (unsigned i=0; i < net.getCities().size(); i++) {
        double minCity = INFINITY; // find min within each city, set minCity as infinity
        for (unsigned a=0; a < net.getNodes().size(); a++) {
            double distance = euclDistance(net.getCities()[i], net.getNodes()[a]);
//            cout << "Node: " << a << ", Distance: " << distance << endl;
            if (isnan(distance)) break;
            minCity = (distance < minCity) ? (distance) : (minCity);
//            cout << "minCity: " << minCity << endl;
            etaN = (etaN < minCity) ? (minCity) : (etaN);
        }
    }
    cout << "Eta n: " << etaN << '\n' << endl;
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
    //cout << "City X coord: " << city.coord[0]  << ", Y coords: " << city.coord[1] << endl;
    //cout << "Node X coord: " << node.coord[0] << ", Y coords: " << node.coord[1] << endl;
    double distance = pow ((pow ((city.coord[0] - node.coord[0]), 2) + pow ((city.coord[1] - node.coord[1]), 2)), 0.5);
    //cout << "Euclidian distance: " << distance << endl;
    return distance;
}
