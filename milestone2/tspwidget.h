#ifndef TSPWIDGET_H
#define TSPWIDGET_H

#include <QWidget>
#include <QKeyEvent>

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

    void keyPressEvent(QKeyEvent *event);

    signals:
    void  environmentChanged(bool ok);

    void TSPends(bool ok);

public slots:
    void startTSP();
    void stopTSP();
    void resetTSP();

    int interval(); // interval between iterations
    void setInterval(int msec); // set interval between iterations

private slots:
    void paintGrid(QPainter &p);

    void paintUniverse(QPainter &p);

    void newIteration();

private:
    QTimer *timer;
    int iterations;
    //CAbase ca1;
    //int universeSize;
};

#endif // TSPWIDGET_H
