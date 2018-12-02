#include "mainwindow.h"
#include <QApplication>

#include <ctime>
#include <iostream>
#include "elasticnet.h"
#include "iterable.h"
#include "iterator.h"

using namespace std;

int main(int argc, char *argv[])
{

    // /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
    //*/

    /*
    srand(time(NULL));
    const int numOfCities = 5;
    double radius = 0.1;
    double cvRatio = 2.5;
    double alpha = 1, beta = 1, k0 = 0.1, etaZiel = 0.005;
    unsigned int iterMax = 10000;

    ElasticNet net;
    net.setRadius(radius);
    net.setCVRatio(cvRatio);


    for (int i = 0; i < numOfCities; i++) {
        net.addCity(((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)));
        cout << net.getCities()[i].coord[0] << ", " << net.getCities()[i].coord[1] << endl;
    }

    net.setNumOfNodes();
    cout << "NumOfCities: " << net.getNumOfCities() << endl;
    cout << "CV ratio: " << net.getCvRatio() << endl;
    cout << "NumOfNodes: " << net.getNumOfNodes() << endl;

    net.setCentroid();
    net.addNodes();

    for (int i = 0; i < net.getNumOfNodes(); i++) {
        cout << net.getNodes()[i].coord[0] << ", " << net.getNodes()[i].coord[1] << endl;
    }

    Iterable iter(net, k0, alpha, beta);
    cout << "Iterable created" << endl;

    Iterator iterat(iterMax, etaZiel, iter);
    iterat.solve();

    return 0;
    */
}
