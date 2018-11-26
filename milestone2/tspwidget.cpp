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

void TSPwidget::startTSP(const int &number)  // Start Game
{
    iterations = number;
    timer->start();
}

void TSPwidget::stopTSP()  //Stop Game
{
    timer->stop();
}

void TSPwidget::clear() // Clear game field
{
    net.getCities().clear();

    TSPends(true);
    update();

}


int TSPwidget::interval() // Interval between generations
{
    return timer->interval();
}

void TSPwidget::setInterval(int msec) // Set interval between generations
{
    timer->setInterval(msec);
}

void TSPwidget::newIteration()  // Start the evolution of universe and update the game field
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
    paintUniverse(p);
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

void TSPwidget::paintGrid(QPainter &p) {

}

void TSPwidget::paintUniverse(QPainter &p) {

}
