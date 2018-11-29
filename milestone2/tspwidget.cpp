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
}

TSPwidget::~TSPwidget()
{
}

void TSPwidget::startTSP(const int &number)  // Start TSP
{
    iterations = number;
    net.addNodes(); // generate nodes based on the cities input
    iterable.setElasticNet(net); // assign the net to the iterable
    //iterator.setIterObject(iterable); // assign the iterable to the iterator
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
    iterations = value;
}

void TSPwidget::setEtaZiel(double value)
{
    iterator.setEtaZiel(value);
}

void TSPwidget::setRadius(double value)
{
    net.setRadius(value);
}
void TSPwidget::setCVRatio(double value)
{
    net.setCVRatio(value);
}


void TSPwidget::newIteration()  // Start the Trading Salesman Problem (TSP) and update nodes positions
{
    if (iterations < 0)
        iterations++;

    //iterator.solve();
    iterable.apply();

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
    paintField(p);
}

void TSPwidget::mousePressEvent(QMouseEvent *event) {
    emit environmentChanged(true);
    double k = event->y();
    double j = event->x();

    net.addCity(j,k);
    update();
}

void TSPwidget::mouseMoveEvent(QMouseEvent *event) {
    double k = event->y();
    double j = event->x();

    net.addCity(j,k);
    update();
}

void TSPwidget::paintField(QPainter &p) {

}

