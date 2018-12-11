#include "C:\Users\Yulia\Documents\Informatik\WS18-19\PRG_Praktikum\milestones\milestone2\elasticnet.h"
#include "C:\Users\Yulia\Documents\Informatik\WS18-19\PRG_Praktikum\milestones\milestone2\iterable.h"
#include "C:\Users\Yulia\Documents\Informatik\WS18-19\PRG_Praktikum\milestones\milestone2\iterator.h"
#include <QtTest>

// add necessary includes here

class TestIterator : public QObject
{
    Q_OBJECT

public:
    TestIterator();
    ~TestIterator();

private slots:

    void testSetRadius();
    void testSetCVratio();
    void testAddCity();
    void testSetNumOfNodes();
    void testSetCentroid();
    void testAddNodes();
    void testApply();
    void testSolve();
};

TestIterator::TestIterator()
{

}

TestIterator::~TestIterator()
{

}

void TestIterator::testSetRadius()
{
    double radius = 0.1;
    ElasticNet *net = new ElasticNet;
    net->setRadius(radius);
    QCOMPARE(net->getRadius(), radius);
}

void TestIterator::testSetCVratio()
{
    double cvRatio = 2.5;
    ElasticNet *net = new ElasticNet;
    net->setCVRatio(cvRatio);
    QCOMPARE(net->getCvRatio(), cvRatio);
}

void TestIterator::testAddCity()
{
    double coordX = 0.607, coordY = 0.303;
    ElasticNet *net = new ElasticNet;
    net->addCity(coordX, coordY);
    QCOMPARE(net->getCoordX(0), coordX);
    QCOMPARE(net->getCoordY(0), coordY);
}

void TestIterator::testSetNumOfNodes()
{
    double cvRatio = 2.5;
    double radius = 0.1;
    vector <double> city1 = {0.607, 0.303};
    vector <double> city2 = {0.507, 0.403};
    vector <double> city3 = {0.407, 0.503};

    ElasticNet *net = new ElasticNet;
    net->setRadius(radius);
    net->setCVRatio(cvRatio);
    net->addCity(city1[0], city1[1]);
    net->addCity(city2[0], city2[1]);
    net->addCity(city3[0], city3[1]);
    net->setNumOfNodes();

    int numOfNodes = 2.5*3;
    QVERIFY(net->getNumOfNodes() == numOfNodes);
}

void TestIterator::testSetCentroid()
{
    double radius = 0.1, cvRatio = 2.5;
    vector <double> city1 = {0.607, 0.303};
    vector <double> city2 = {0.507, 0.403};
    vector <double> city3 = {0.407, 0.503};

    ElasticNet *net = new ElasticNet;
    net->setRadius(radius);
    net->setCVRatio(cvRatio);
    net->addCity(city1[0], city1[1]);
    net->addCity(city2[0], city2[1]);
    net->addCity(city3[0], city3[1]);
    net->setNumOfNodes();
    net->setCentroid();

    double centroidX = (city1[0]+city2[0]+city3[0])/3;
    double centroidY = (city1[1]+city2[1]+city3[1])/3;

    //QCOMPARE(net->getCentroid()[0], 0.507);
    //QCOMPARE(net->getCentroid()[1], 0.403);
}

void TestIterator::testAddNodes()
{
    double radius = 0.1, cvRatio = 2.5;
    vector <double> city1 = {0.607, 0.303};
    vector <double> city2 = {0.507, 0.403};
    vector <double> city3 = {0.407, 0.503};

    ElasticNet *net = new ElasticNet;
    net->setRadius(radius);
    net->setCVRatio(cvRatio);
    net->addCity(city1[0], city1[1]);
    net->addCity(city2[0], city2[1]);
    net->addCity(city3[0], city3[1]);
    net->setNumOfNodes();
    net->setCentroid();
    net->addNodes();

    QCOMPARE(net->getNodes()[0].coord[0], 0.507+0.1);
    QCOMPARE(net->getNodes()[0].coord[1], 0.403);
}

void TestIterator::testApply()
{
    double radius = 0.1, cvRatio = 2.5;
    double alpha = 1, beta = 1, k0 = 0.1, etaZiel = 0.005;
    unsigned int iterMax = 10000, iteration = 0;

    vector <double> city1 = {0.607, 0.303};
    vector <double> city2 = {0.507, 0.403};
    vector <double> city3 = {0.407, 0.503};

    ElasticNet *net = new ElasticNet;
    net->setRadius(radius);
    net->setCVRatio(cvRatio);
    net->addCity(city1[0], city1[1]);
    net->addCity(city2[0], city2[1]);
    net->addCity(city3[0], city3[1]);
    net->setNumOfNodes();
    net->setCentroid();
    net->addNodes();

    Iterable iterable(net, k0, alpha, beta);

    QCOMPARE(iterable.apply(iteration), 0.207295);

}

void TestIterator::testSolve()
{
    double radius = 0.1, cvRatio = 2.5;
    double alpha = 1, beta = 1, k0 = 0.1, etaZiel = 0.005;
    unsigned int iterMax = 10;

    vector <double> city1 = {0.607, 0.303};
    vector <double> city2 = {0.507, 0.403};
    vector <double> city3 = {0.407, 0.503};

    ElasticNet *net = new ElasticNet;
    net->setRadius(radius);
    net->setCVRatio(cvRatio);
    net->addCity(city1[0], city1[1]);
    net->addCity(city2[0], city2[1]);
    net->addCity(city3[0], city3[1]);
    net->setNumOfNodes();
    net->setCentroid();
    net->addNodes();

    Iterable iter(net, k0, alpha, beta);

    Iterator iterator(iterMax, etaZiel, iter);
    iterator.solve();

    QVERIFY(iterator.getIteration() == 10);
}

QTEST_APPLESS_MAIN(TestIterator)

#include "tst_testiterator.moc"
