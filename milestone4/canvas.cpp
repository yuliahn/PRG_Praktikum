#include "canvas.h"
#include "ui_canvas.h"

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <iostream>

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
    this->xPixel = ui->rowsPixel->value();
    this->yPixel = ui->columnsPixel->value();


}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::on_setButton_clicked()
{
    cout << "im here";
    setCanvas(xPixel, yPixel);
    cout << "Test2";
    //update();
}

void Canvas::on_clearButton_clicked()
{
    cout<<"clear button";
    setCanvas(xPixel, yPixel);
}

vector<vector<double>> Canvas::setCanvas(int x, int y)
{
    vector<double> row;
    cout << "Test3";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            double color = 0;
            row.push_back(color);
        }
        canvas.push_back(row);
        row.clear();
    }

    return canvas;
}



void Canvas::setPixel(int i, int j)
{
    canvas[i][j] = 1;
    canvas[i][j-1], canvas[i][j+1], canvas[i-1][j], canvas[i+1][j] += 0.25;
}

void Canvas::paintEvent(QPaintEvent * event) {
    emit environmentChanged(true);
    QPainter p(this);
    setCanvas(xPixel, yPixel);
    createField(p);
    paintField(p);
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    double x = event->x();
    double y = event->y();
    setPixel(x/xPixel, y/yPixel);
    update();
}

/**
 * @brief TSPwidget::mouseMoveEvent
 * Adds cities to the elastic net, when mouse is pressed while moving.
 * @param event
 */
void Canvas::mouseMoveEvent(QMouseEvent *event) {
    double x = event->x();
    double y = event->y();
    setPixel(x/xPixel, y/yPixel);
    update();
}

void Canvas::createField(QPainter &p){
    int size = 400;
    QRect borders(0, 0, size, size); // borders of the universe
    QColor gridColor = "#000"; // color of the grid
    gridColor.setAlpha(20); // must be lighter than main color
    p.setPen(gridColor);
    double cellWidth = (double) size / xPixel ; // width of the widget / number of cells at one row
    for (double k = cellWidth; k <= size; k += cellWidth)
        p.drawLine(k, 0, k, size);
    double cellHeight = (double) size / yPixel; // height of the widget / number of cells at one row
    for (double k = cellHeight; k <= size; k += cellHeight)
        p.drawLine(0, k, size, k);
    p.drawRect(borders);
}

void Canvas::paintField(QPainter &p) {
    int size = 400;
    double cellWidth = (double) size / xPixel ;
    double cellHeight = (double) size / yPixel ;
    for (int i = 0; i < xPixel; i++) {
        for (int j = 0; j < yPixel; j++) {
            if (canvas[i][j]==1){
                QRectF r(i*cellWidth, j*cellHeight, cellWidth, cellHeight);
                p.fillRect(r, QBrush("#1e1b18"));
            }else if (canvas[i][j]==0.75){
                QRectF r(i*cellWidth, j*cellHeight, cellWidth, cellHeight);
                p.fillRect(r, QBrush("#868482"));
            }else if (canvas[i][j]==0.5){
                QRectF r(i*cellWidth, j*cellHeight, cellWidth, cellHeight);
                p.fillRect(r, QBrush("#aeadac"));
            }else if (canvas[i][j]==0.25){
                QRectF r(i*cellWidth, j*cellHeight, cellWidth, cellHeight);
                p.fillRect(r, QBrush("#d7d6d5"));
            }

        }
    }
}




