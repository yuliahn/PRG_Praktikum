#include "C:\Users\Yulia\Documents\Informatik\WS18-19\PRG_Praktikum\milestones\milestone2\elasticnet.h"
#include <QtTest>

// add necessary includes here

class TestIterator : public QObject
{
    Q_OBJECT

public:
    TestIterator();
    ~TestIterator();

private slots:

    void testAddNodes();
    void testRadiusCVratio();
    void testAddCity();

};

TestIterator::TestIterator()
{

}

TestIterator::~TestIterator()
{

}

void TestIterator::testRadiusCVratio()
{
    double radius = 0.1, cvRatio = 2.5;
    ElasticNet *net = new ElasticNet;
    net->setRadius(radius);
    net->setCVRatio(cvRatio);
    QVERIFY(net->getRadius() == 0.1, "Radius doesn't match.");
    QVERIFY(net->getCVratio() == 2.5, "CV ratio doesn't match.");
}

void TestIterator::testAddCity()
{
    vector <double> city = {0.607, 0.303};
    ElasticNet *net = new ElasticNet;
    net->addCity(city[0], city[1]);

}
void TestIterator::testAddNodes()
{
    //const int numOfCities = 5;
    double radius = 0.1, cvRatio = 2.5;
    double alpha = 1, beta = 1, k0 = 0.1, etaZiel = 0.005;
    unsigned int iterMax = 10000;

    ElasticNet *net = new ElasticNet;
    net->setRadius(radius);
    net->setCVRatio(cvRatio);

    for (int i = 0; i < numOfCities; i++) {
        net->addCity(((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)));
        cout << net->getCities()[i].coord[0] << ", " << net->getCities()[i].coord[1] << endl;
    }

    net->setNumOfNodes();
    cout << "NumOfCities: " << net->getNumOfCities() << endl;
    cout << "CV ratio: " << net->getCvRatio() << endl;
    cout << "NumOfNodes: " << net->getNumOfNodes() << endl;

    net->setCentroid();
    net->addNodes();

    for (int i = 0; i < net->getNumOfNodes(); i++) {
        cout << net->getNodes()[i].coord[0] << ", " << net->getNodes()[i].coord[1] << endl;
    }

    Iterable iter(net, k0, alpha, beta);
    cout << "Iterable created" << endl;

    Iterator iterat(iterMax, etaZiel, iter);
    iterat.solve();
}

QTEST_APPLESS_MAIN(TestIterator)

#include "tst_testiterator.moc"
