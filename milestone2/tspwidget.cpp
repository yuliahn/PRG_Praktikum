#include "tspwidget.h"

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
