/**
 * tspwidget.cpp
 * Purpose: GUI interface for the traveling salesman problem.
 *
 * @author Blerton Osmani
 * @author Zeynep Yavas
 * @author Yulia Kim
 */

#include "tspwidget.h"
#include "elasticnet.h"
#include "iterable.h"
#include "iterator.h"

#include <QMessageBox>
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>
#include <QRectF>
#include <QPainter>
#include <qmath.h>
#include "QTime"

/**
 * @brief TSPwidget::TSPwidget
 * A new TSP widget declaration with parameters set to
 * alpha=beta=1; k0=0.1; iterMax=10000; etaZiel=0.005;
 * radius=0.1; cvRatio=2.5;
 * @param parent
 */
TSPwidget::TSPwidget(QWidget *parent) :
    QWidget(parent),

    timer(new QTimer(this)),
    citiesValueRange({0,1}),
    nodesValueRange({0,1}),
    iteration(-1)
{
    ElasticNet *net = new ElasticNet();
    iterable.setAlpha(1);
    iterable.setBeta(1);
    iterable.setK0(0.1);
    iterable.setElasticNet(net);

    iterator.setIterMax(10000);
    iterator.setEtaZiel(0.005);
    iterable.getNet()->setRadius(0.1);
    iterable.getNet()->setCVRatio(2.5);
    cout << "CV Ratio: " << iterable.getNet()->getCvRatio() << endl;

    timer->setInterval(300);
    connect(timer, SIGNAL(timeout()), this, SLOT(newIteration()));
    string m_masterColor = "#000";

}

TSPwidget::~TSPwidget()
{
}

/**
 * @brief TSPwidget::startTSP
 * Starts the TSP widget by generating nodes of the elastic net.
 *
 * @param number Set to -1 by default.
 */
void TSPwidget::startTSP(const int &number) // Start TSP
{
    iteration = number;

    iterable.getNet()->addNodes();
    iterator.setIterObject(iterable); // assign the iterable to the iterator
    timer->start();


}

/**
 * @brief TSPwidget::stopTSP
 * Stops the TSP widget, s.t. no further iterations are done.
 */
void TSPwidget::stopTSP()  //Stop TSP
{
    timer->stop();
}

/**
 * @brief TSPwidget::clear
 * Clears the field from cities and nodes; clears the nodes and cities vectors.
 */
void TSPwidget::clear() // Clear TSP field
{
    iterable.getNet()->clearCities();
    iterable.getNet()->clearNodes();

    TSPends(true);
    update();

}

/**
 * @brief TSPwidget::interval
 * @return timer's interval value
 */
int TSPwidget::interval() // Interval between iterations
{
    return timer->interval();
}

/**
 * @brief TSPwidget::setInterval
 * Sets the length of an interval between iterations in msec.
 * @param msec Interval in msec
 */
void TSPwidget::setInterval(int msec) // Set interval between iterations
{
    timer->setInterval(msec);
}

/**
 * @brief TSPwidget::setAlpha
 * Sets the value of alpha.
 * @param value
 */
void TSPwidget::setAlpha(double value)
{
    iterable.setAlpha(value);
}

/**
 * @brief TSPwidget::setBeta
 * Sets the value of beta.
 * @param value
 */
void TSPwidget::setBeta(double value)
{
    iterable.setBeta(value);
}

/**
 * @brief TSPwidget::setK0
 * Sets the value of k0.
 * @param value
 */
void TSPwidget::setK0(double value)
{
    iterable.setK0(value);
}

/**
 * @brief TSPwidget::setMaxIter
 * Sets the maximum number of iterations.
 * @param value
 */
void TSPwidget::setMaxIter(int value)
{
    iterator.setIterMax(value);
}

/**
 * @brief TSPwidget::setEtaZiel
 * Sets the value of minimal eta distance between cities and nodes.
 * @param value
 */
void TSPwidget::setEtaZiel(double value)
{
    iterator.setEtaZiel(value);
}

/**
 * @brief TSPwidget::setRadius
 * Sets the radius of a circle, which generates nodes, with a center at centroid.
 * @param value Radius
 */
void TSPwidget::setRadius(double value)
{
    iterable.getNet()->setRadius(value);
}

/**
 * @brief TSPwidget::setCVRatio
 * Sets the CV ratio of cities to nodes.
 * @param value
 */
void TSPwidget::setCVRatio(double value)
{
    iterable.getNet()->setCVRatio(value);
}

/**
 * @brief TSPwidget::newIteration
 * Runs a new iteration and checks whether the distance or maximum iteration condition was satisfied.
 */
void TSPwidget::newIteration()  // Start the Trading Salesman Problem (TSP) and update nodes positions
{
    if (iteration < 0)
        iteration++;

    double etaN = iterable.apply(iteration);

    if (etaN <= iterator.getEtaZiel() or iteration == iterator.getIterMax()) {
        stopTSP();
        TSPends(true);
        QMessageBox::information(this,
                                 tr("TSP finished."),
                                 tr("Iterations finished."),
                                 QMessageBox::Ok,
                                 QMessageBox::Cancel);
    }

    update();

    iteration++;

}

/**
 * @brief TSPwidget::paintEvent
 * Paints the grid, cities and nodes.
 * @param event
 */
void TSPwidget::paintEvent(QPaintEvent * event) {
    QPainter p(this);
    paintGrid(p);
    paintField(p);
    paintLineNode(p);
    paintFieldNode(p);

}

/**
 * @brief TSPwidget::mousePressEvent
 * Adds cities to the elastic net, when mouse is pressed.
 * @param event
 */
void TSPwidget::mousePressEvent(QMouseEvent *event) {
    emit environmentChanged(true);
    double k = event->y();
    double j = event->x();
    iterable.getNet()->addCity(j/500,k/500);
    cout << "Cities: " << iterable.getNet()->getNumOfCities() << endl;
    iterable.getNet()->setCentroid();
    iterable.getNet()->setNumOfNodes();
    cout << "CV ratio: " << iterable.getNet()->getCvRatio() << endl;
    iterable.getNet()->addNodes();
    iterable.getNet()->preprocess();
    cout << "Number of nodes: " << iterable.getNet()->getNumOfNodes()<<endl;
    update();
}

/**
 * @brief TSPwidget::mouseMoveEvent
 * Adds cities to the elastic net, when mouse is pressed while moving.
 * @param event
 */
void TSPwidget::mouseMoveEvent(QMouseEvent *event) {
    double k = event->y();
    double j = event->x();

    iterable.getNet()->addCity(j/500,k/500);
    iterable.getNet()->setNumOfNodes();
    iterable.getNet()->setCentroid();
    iterable.getNet()->addNodes();
    iterable.getNet()->preprocess();
    cout << iterable.getNet()->getNumOfNodes()<<endl;
    update();
}

/**
 * @brief TSPwidget::paintGrid
 * Paints the grid.
 * @param p Painter
 */
void TSPwidget::paintGrid(QPainter &p) {
    int size = 500;
    QRect borders(0, 0, size - 1, size - 1); // borders of the universe
    QColor gridColor = "#000"; // color of the grid
    gridColor.setAlpha(20); // must be lighter than main color
    p.setPen(gridColor);
    double cellWidth = (double) size / 50 ; // width of the widget / number of cells at one row
    for (double k = cellWidth; k <= size; k += cellWidth)
        p.drawLine(k, 0, k, size);
    double cellHeight = (double) size / 50; // height of the widget / number of cells at one row
    for (double k = cellHeight; k <= size; k += cellHeight)
        p.drawLine(0, k, size, k);
    p.drawRect(borders);
}

/**
 * @brief TSPwidget::paintField
 * Paints the cities of the elastic net.
 * @param p Painter
 */
void TSPwidget::paintField(QPainter &p) {
    double cellWidth = 500 / 40;
    double cellHeight = 500 / 40;
    for(int x = 0; x < iterable.getNet()->getNumOfCities(); x++){
        double y = iterable.getNet()->getCoordX(x) * (500/(citiesValueRange[1]-citiesValueRange[0])) / cellWidth;
        double z = iterable.getNet()->getCoordY(x) * (500/(citiesValueRange[1]-citiesValueRange[0])) / cellHeight;
        qreal left = (qreal)(cellWidth * y - (cellWidth)); // margin from left
        qreal top = (qreal)(cellHeight * z - (cellHeight)); // margin from top
        QRectF r(left, top, (qreal) cellWidth, (qreal) cellHeight);
        p.fillRect(r, QBrush(Qt::blue));
    }
}


/**
 * @brief TSPwidget::paintLineNode
 * Paints the lines connecting nodes of the elastic net.
 * @param p Painter
 */
void TSPwidget::paintLineNode(QPainter &p) {
    double cellSize = 500 / 60;

        for(int a = 0; a < iterable.getNet()->getNumOfNodes(); a++){
                if (a > 0){
                    double q = iterable.getNet()->getNodes()[a-1].coord[0] * (500/(nodesValueRange[1]-nodesValueRange[0])) - (cellSize/2);
                    double r = iterable.getNet()->getNodes()[a-1].coord[1] * (500/(nodesValueRange[1]-nodesValueRange[0])) - (cellSize/2);
                    double s = iterable.getNet()->getNodes()[a].coord[0] * (500/(nodesValueRange[1]-nodesValueRange[0])) - (cellSize/2);
                    double t = iterable.getNet()->getNodes()[a].coord[1] * (500/(nodesValueRange[1]-nodesValueRange[0])) - (cellSize/2);
                    p.setPen(QPen(Qt::darkGray, 1, Qt::SolidLine));
                    p.drawLine(q, r, s, t);

                }
                if(a == (iterable.getNet()->getNumOfNodes()-1)){
                    double q = iterable.getNet()->getNodes()[0].coord[0] * (500/(nodesValueRange[1]-nodesValueRange[0])) - (cellSize/2);
                    double r = iterable.getNet()->getNodes()[0].coord[1] * (500/(nodesValueRange[1]-nodesValueRange[0])) - (cellSize/2);
                    double s = iterable.getNet()->getNodes()[a].coord[0] * (500/(nodesValueRange[1]-nodesValueRange[0])) - (cellSize/2);
                    double t = iterable.getNet()->getNodes()[a].coord[1] * (500/(nodesValueRange[1]-nodesValueRange[0])) - (cellSize/2);
                    p.setPen(QPen(Qt::darkGray, 1, Qt::SolidLine));
                    p.drawLine(q, r, s, t);
                }
            }
    }

/**
 * @brief TSPwidget::paintFieldNode
 * Paints the nodes of the elastic net.
 * @param p Painter
 */
void TSPwidget::paintFieldNode(QPainter &p) {
    double cellWidth = 500 / 60;
    double cellHeight = 500 / 60;

        for(int a = 0; a < iterable.getNet()->getNumOfNodes(); a++){
            double b = iterable.getNet()->getNodes()[a].coord[0] * (500/(nodesValueRange[1]-nodesValueRange[0])) / cellWidth;
            double c = iterable.getNet()->getNodes()[a].coord[1] * (500/(nodesValueRange[1]-nodesValueRange[0])) / cellWidth;
            cout <<"Iteration: " << iteration << ", Node coords: " << b/50 << ", " << c/50 << endl;
            qreal left = (qreal)(cellWidth * b - cellWidth); // margin from left
            qreal top = (qreal)(cellHeight * c - cellHeight); // margin from top
            QRectF hi(left, top, (qreal) cellWidth, (qreal) cellHeight);
            p.fillRect(hi, QBrush(Qt::red));
        }
    }
