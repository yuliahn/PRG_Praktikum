#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <vector>

using namespace std;

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();

    vector<vector<double>> setCanvas(int x, int y);
    void setPixel(int i, int j);
    void rowsPixel(double value);
    void columnsPixel(double value);

    unsigned getSizeOfCanvas {this->canvas.size()};

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e) override;
    void createField(QPainter &p);

private slots:
    void on_setButton_clicked();

    void on_clearButton_clicked();
    
private:
    Ui::Canvas *ui;
    vector<vector<double>> canvas;
    int x_pixel_amount;
    int y_pixel_amount;

};

#endif // CANVAS_H
