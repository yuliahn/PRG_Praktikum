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

void TSPwidget::startTSP(const int &number) // Start TSP
{
    iteration = number;

    //iterable.setElasticNet(net); // assign the net to the iterable
    iterable.getNet()->addNodes();
    iterator.setIterObject(iterable); // assign the iterable to the iterator
    timer->start();


}

void TSPwidget::stopTSP()  //Stop TSP
{
    timer->stop();
}

void TSPwidget::clear() // Clear TSP field
{
    iterable.getNet()->clearCities();
    iterable.getNet()->clearNodes();

    TSPends(true);
    update();

}


int TSPwidget::interval() // Interval between iterations
{
    return timer->interval();
}

void TSPwidget::setInterval(int msec) // Set interval between iterations
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
    iterable.getNet()->setRadius(value);
}
void TSPwidget::setCVRatio(double value)
{
    iterable.getNet()->setCVRatio(value);
}


void TSPwidget::newIteration()  // Start the Trading Salesman Problem (TSP) and update nodes positions
{
    if (iteration < 0)
        iteration++;

    iterable.apply(iteration);
    //update();

    /*
    if (etaN <= iterator.getEtaZiel() or iteration == iterator.getIterMax()) {
        stopTSP();
        TSPends(true);
        QMessageBox::information(this,
                                 tr("TSP finished."),
                                 tr("Iterations finished."),
                                 QMessageBox::Ok,
                                 QMessageBox::Cancel);
    }
    */


    iteration++;

    // /*
    if (iteration == iterator.getIterMax()) {
        stopTSP();
        TSPends(true);
        QMessageBox::information(this,
                                 tr("TSP finished."),
                                 tr("Iterations finished."),
                                 QMessageBox::Ok,
                                 QMessageBox::Cancel);
    }
    update();
    //*/
}

void TSPwidget::paintEvent(QPaintEvent * event) {
    QPainter p(this);
    paintGrid(p);
    paintField(p);
    paintLineNode(p);
    paintFieldNode(p);

}

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
    double cellWidth = 500 / 40;
    double cellHeight = 500 / 40;
    for(int x = 0; x < iterable.getNet()->getNumOfCities(); x++){
        double y = iterable.getNet()->getCoordX(x) * 500 / cellWidth;
        double z = iterable.getNet()->getCoordY(x) * 500 / cellHeight;
        qreal left = (qreal)(cellWidth * y - (cellWidth)); // margin from left
        qreal top = (qreal)(cellHeight * z - (cellHeight)); // margin from top
        QRectF r(left, top, (qreal) cellWidth, (qreal) cellHeight);
        p.fillRect(r, QBrush(Qt::blue));
    }
}

void TSPwidget::paintLineNode(QPainter &p) {
    double cellSize = 500 / 60;

        for(int a = 0; a < iterable.getNet()->getNumOfNodes(); a++){
                if (a > 0){
                    double q = iterable.getNet()->getNodes()[a-1].coord[0] * 500 - (cellSize/2);
                    double r = iterable.getNet()->getNodes()[a-1].coord[1] * 500 - (cellSize/2);
                    double s = iterable.getNet()->getNodes()[a].coord[0] * 500 - (cellSize/2);
                    double t = iterable.getNet()->getNodes()[a].coord[1] * 500 - (cellSize/2);
                    p.setPen(QPen(Qt::darkGray, 1, Qt::SolidLine));
                    p.drawLine(q, r, s, t);

                }
                if(a == (iterable.getNet()->getNumOfNodes()-1)){
                    double q = iterable.getNet()->getNodes()[0].coord[0] * 500 - (cellSize/2);
                    double r = iterable.getNet()->getNodes()[0].coord[1] * 500 - (cellSize/2);
                    double s = iterable.getNet()->getNodes()[a].coord[0] * 500 - (cellSize/2);
                    double t = iterable.getNet()->getNodes()[a].coord[1] * 500 - (cellSize/2);
                    p.setPen(QPen(Qt::darkGray, 1, Qt::SolidLine));
                    p.drawLine(q, r, s, t);
                }
            }
    }




void TSPwidget::paintFieldNode(QPainter &p) {
    double cellWidth = 500 / 60;
    double cellHeight = 500 / 60;


        for(int a = 0; a < iterable.getNet()->getNumOfNodes(); a++){
            double b = iterable.getNet()->getNodes()[a].coord[0] * 500 / cellWidth;
            double c = iterable.getNet()->getNodes()[a].coord[1] * 500 / cellWidth;
            cout <<"Iteration: " << iteration << ", Node coords: " << b/50 << ", " << c/50 << endl;
            qreal left = (qreal)(cellWidth * b - cellWidth); // margin from left
            qreal top = (qreal)(cellHeight * c - cellHeight); // margin from top
            QRectF hi(left, top, (qreal) cellWidth, (qreal) cellHeight);
            p.fillRect(hi, QBrush(Qt::red));
        }
    }
