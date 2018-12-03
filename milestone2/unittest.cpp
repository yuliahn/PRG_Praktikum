// author: Ischa Tahir (5935200)
/*!
  This program is a unittest ("automatic testing")
  for the part programs "elasticnet", "iterable" and "iterator".
  The principle of a unittest is based on slot signals:
  During running time of the program it is sending signals which
  are captured by slots. These are starting a function.
  In this method it can be proven how the program works, if it works,
  and if there is any problem, it can be find easier with this method.
  */

#include <QtTest/QtTest>
#include "elasticnet.h"
#include "iterable.h"
#include "iterator.h"

QT += testlib // including library
QT -= gui // because no GUI elements included

class TestSalesman: public Qelasticnet, public Qiterable, public Qiterator
        /*! This class tests methods of the files "elasticnet.h",
         * "iterable.h", "iterator.h" */
{
    Q_OBJECT
private: slots:
    // methods of "elasticnet.h"
    vector <City> getCities();
    vector <Node> getNodes();
    double getCentroid();
    double getCvRatio();
    unsigned getNumOfCities();
    double getNumOfNodes();
    double getCoordX(int x);
    double getCoordY(int x);
    double getNodeCoordX(int x);
    double getNodeCoordY(int x);
    void setRadius(double value)
    void setCVRatio(double value)
    void addCity(double y, double z);
    void addNodes();
    void setCentroid();
    void setNumOfNodes(); // getNumofCities, getCvRatio => numOfNodes = getNumOfCities*getCvRatio
    void updateCoord(int i, vector <double> values);
    void preprocess();
    void clearCities();
    void clearNodes();

    //methods of "iterable.h"
    double apply(int currentIteration); // returns etaN
    double getK();
    double getT();
    int getIteration();
    vector <vector <double>> getV();
    double getAlpha();
    double getBeta();
    void setAlpha(double value);
    void setBeta(double value);
    void setK0(double value);
    void setElasticNet(ElasticNet object);
    void updateK(); // k = max( pow( 0.99, iteration/50 ) * k0, 0.01 )
    void updateT(); // t=2*pow(k,2)
    void updateV();
    void updateIteration(int value);
    double euclDistance(City city, Node node);
    vector <double> add (vector <double> a, vector <double> b);
    vector <double> subtract (vector <double> a, vector <double> b);
    vector <double> multiply (double a, vector <double> b);

    // methods of "iterator.h"
    void solve();
    void updateIter()
    void update();
    void setIterObject(Iterable object)
    void setIterMax(int value)
    void setEtaZiel(double value)
    int getIterMax()
    double getEtaZiel()

// testing methods of "elasticnet.h"
void TestSalesman::getCities()
{
    //
}
void TestSalesman::getNodes()
{
    //
}
double TestSalesman::getCentroid()
{
    //
}
double TestSalesman::getCvRatio()
{
    //
}
double TestSalesman::getNumofCities()
{
    //
}
double TestSalesman::getNumofNodes()
{
    //
}
double TestSalesman::getCoordX()
{
    //
}
double TestSalesman::getCoordY()
{
    //
}
void TestSalesman::setRadius(double value)
{
    //
}
void TestSalesman::getCoordX()
{
    //
}
void TestSalesman::setCVRatio()
{
    //
}
void TestSalesman::addCity()
{
    //
}
void TestSalesman::addNodes()
{
    //
}
void TestSalesman::getCoordX()
{
    //
}
void TestSalesman::setCentroid()
{
    //
}
void TestSalesman::setNumOfNodes()
{
    //
}
void TestSalesman::updateCoord(int i, vector <double> values)
{
    //
}
void TestSalesman::preprocess()
{
    //
}
void TestSalesman::clearCities()
{
    //
}
void TestSalesman::clearNodes()
{
    //
}

// testing methods of "iterable.h"
double TestSalesman::apply(int currentIteration)
{
    //
}
double TestSalesman::getK()
{
    //
}
double TestSalesman::getT()
{
    //
}
int TestSalesman::getIteration()
{
    //
}
double TestSalesman::getV()
{
    //
}
double TestSalesman::getAlpha()
{
    //
}
double TestSalesman::getBeta()
{
    //
}
void TestSalesman::setAlpha(double value)
{
    //
}
void TestSalesman::setBeta(double value)
{
    //
}
void TestSalesman::setK0(double value)
{
    //
}
void TestSalesman::setElasticNet(ElasticNet object)
{
    //
}
void TestSalesman::updateK()
{
    //
}
void TestSalesman::updateT()
{
    //
}
void TestSalesman::updateV()
{
    //
}
void TestSalesman::updateIteration(int value)
{
    //
}
double TestSalesman::euclDistance(City city, Node node)
{
    //
}
double TestSalesman::add (vector <double> a, vector <double> b)
{
    //
}
double TestSalesman::subtract (vector <double> a, vector <double> b)
{
    //
}
double TestSalesman::multiply (double a, vector <double> b)
{
    //
}

// testing methods of "iterator.h"
void TestSalesman::solve()
{
    //
}
void TestSalesman::updateIter()
{
    //
}
void TestSalesman::update()
{
    //
}
void TestSalesman::setIterObject(Iterable object)
{
    //
}
void TestSalesman::setIterMax(int value)
{
    //
}
void TestSalesman::setEtaZiel(double value)
{
    //
}
int TestSalesman::getIterMax()
{
    //
}
double TestSalesman::getEtaZiel()
{
    //
}
};

QTEST_MAIN(TestSalesman)
/*! makes the test executable */
#include "testsalesman.moc" // executed moc-file

// benchmark test (with given variables)
benchmark();

class TestSalesman::benchmark()
/*! This is a benchmark test with given variables
 * alpha = 1
 * beta = 1
 * k0 = 0.1
 * iterMax = 10000
 * cvRatio = 2.5
 * rk = 0.1
 * nodeCoordX = [0,1]^2
 * nodeCoordY = [0,1]^2
 * nZiel <= 5*10^(-3)
 */
{

}


/* references:
 * https://de.wikibooks.org/wiki/Qt_f%C3%BCr_C%2B%2B_Anf%C3%A4nger:_Signale_und_Slots/
 * http://doc.qt.io/qt-5/qttestlib-tutorial1-example.html
 * http://doc.qt.io/qt-5/qttestlib-tutorial5-example.html
