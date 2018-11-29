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

TSPwidget::TSPwidget(QWidget *parent) :
    QWidget(parent),
    timer(new QTimer(this)),
    iterations(-1)
{
    //ca1(),
    //universeSize(50) {
    timer->setInterval(300);
    //ca1.ResetWorldSize(universeSize, universeSize);
    connect(timer, SIGNAL(timeout()), this, SLOT(newIteration()));
    string m_masterColor = "#000";
}

TSPwidget::~TSPwidget()
{
}

void TSPwidget::startTSP(const int &number)  // Start TSP
{
    iterations = number;
    //net.generateNet(); // generate nodes based on the cities input
    iterable.setElasticNet(net); // assign the net to the iterable
    iterator.setIterObject(iterable); // assign the iterable to the iterator
    //??should iterator be created or better run it inside newIteration??
    timer->start();
}

void TSPwidget::stopTSP()  //Stop TSP
{
    timer->stop();
}

void TSPwidget::clear() // Clear TSP field
{
    net.getCities().clear();

    TSPends(true);
    update();

}


int TSPwidget::interval() // Interval between iterations
{
    return timer->interval();
}

void TSPwidget::setInterval(int msec) // Set interval between generations
{
    timer->setInterval(msec);
}

void TSPwidget::setAlpha(double value)
{
    iterable.setAlpha(value);
}

void TSPwidget::setBeta(double value)
{
    iterable.setBeta(value);
}

void TSPwidget::setK0(double value)
{
    iterable.setK0(value);
}

void TSPwidget::setMaxIter(int value)
{
    iterator.setIterMax(value);
}

void TSPwidget::setEtaZiel(double value)
{
    iterator.setEtaZiel(value);
}

void TSPwidget::setRadius(double value)
{
    net.setRadius(1.5);
}
void TSPwidget::setCVRatio(double value)
{
    net.setCVRatio(2.0);
}


void TSPwidget::newIteration()  // Start the Trading Salesman Problem (TSP) and update nodes positions
{
    if (iterations < 0)
        iterations++;

    iterator.solve();

    update();

    iterations--;
    if (iterations == 0) {
        stopTSP();
        TSPends(true);
        QMessageBox::information(this,
                                 tr("TSP finished."),
                                 tr("Iterations finished."),
                                 QMessageBox::Ok,
                                 QMessageBox::Cancel);
    }
}

void TSPwidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    paintGrid(p);
    paintField(p);
    paintFieldNode(p);
}

void TSPwidget::mousePressEvent(QMouseEvent *event) {
    emit environmentChanged(true);
    double k = event->y();
    double j = event->x();
    cout << "imhere" << endl;
    net.addCity(j,k);
    net.setCentroid();
    net.addNodes();
    update();
}

void TSPwidget::mouseMoveEvent(QMouseEvent *event) {
    double k = event->y();
    double j = event->x();

    net.addCity(j,k);
    net.setCentroid();
    net.addNodes();
    update();
}

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

void TSPwidget::paintField(QPainter &p) {
    double cellWidth = 500 / 50;
    double cellHeight = 500 / 50;
    for(int x = 0; x < net.getNumOfCities(); x++){

        double y = net.getCoordX(x) / cellWidth;
        double z = net.getCoordY(x) / cellHeight;
        qreal left = (qreal)(cellWidth * y - cellWidth); // margin from left
        qreal top = (qreal)(cellHeight * z - cellHeight); // margin from top
        QRectF r(left, top, (qreal) cellWidth, (qreal) cellHeight);
        p.fillRect(r, QBrush(Qt::red));
    }
}

void TSPwidget::paintFieldNode(QPainter &p) {
    double cellWidth = 500 / 50;
    double cellHeight = 500 / 50;
    net.addNodes();
    cout <<"here;;;;"<<net.getNumOfNodes();

    for(int a = 0; a < net.getNumOfNodes(); a++){
        double b = net.getNodeCoordX(a) / cellWidth;
        double c = net.getNodeCoordY(a) / cellHeight;
        cout << b << endl << c << "heej";
        qreal left = (qreal)(cellWidth * a - cellWidth); // margin from left
        qreal top = (qreal)(cellHeight * a - cellHeight); // margin from top
        QRectF hi(left, top, (qreal) cellWidth, (qreal) cellHeight);
        p.fillRect(hi, QBrush(Qt::green));
    }
}
