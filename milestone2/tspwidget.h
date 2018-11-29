#ifndef TSPWIDGET_H
#define TSPWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <iostream>
#include "elasticnet.h"
#include "iterable.h"
#include "iterator.h"


class TSPwidget : public QWidget
{
    Q_OBJECT

public:
    explicit TSPwidget(QWidget *parent = nullptr);
    ~TSPwidget();

protected:
    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *e);

    void mouseMoveEvent(QMouseEvent *e) override;

    signals:
    void  environmentChanged(bool ok);

    void TSPends(bool ok);

public slots:
    void startTSP(const int &number = -1);
    void stopTSP();
    void clear();

    int interval(); // interval between iterations
    void setInterval(int msec); // set interval between iterations

    void setAlpha(double value);
    void setBeta(double value);
    void setK0(double value);
    void setMaxIter(int value);
    void setEtaZiel(double value);
    void setRadius(double value);
    void setCVRatio(double value);

private slots:
    void paintField(QPainter &p);
    void paintGrid(QPainter &p);
    void paintFieldNode(QPainter &p);

    void newIteration();

private:
    QTimer *timer;
    int iterations;
    Iterator iterator;
    Iterable iterable;
    ElasticNet net;
    vector <double> citiesValueRange;
    vector <double> nodesValueRange;
};

#endif // TSPWIDGET_H
