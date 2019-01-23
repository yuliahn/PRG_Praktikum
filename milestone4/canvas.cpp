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
    this->x_pixel_amount = ui->rowsPixel->value();
    this->y_pixel_amount = ui->columnsPixel->value();


}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::on_setButton_clicked()
{
    cout << "im here";
    //setCanvas(x_pixel_amount, y_pixel_amount);
    cout << "Test2";
    //update();
}

void Canvas::on_clearButton_clicked()
{
    cout<<"clear button";
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
    QPainter p(this);
    createField(p);
}

void Canvas::mousePressEvent(QMouseEvent *event) {

    update();
}

/**
 * @brief TSPwidget::mouseMoveEvent
 * Adds cities to the elastic net, when mouse is pressed while moving.
 * @param event
 */
void Canvas::mouseMoveEvent(QMouseEvent *event) {

    update();
}

void Canvas::createField(QPainter &p){
    int size = 500;
    QRect borders(0, 0, size, size); // borders of the universe
    QColor gridColor = "#000"; // color of the grid
    gridColor.setAlpha(20); // must be lighter than main color
    p.setPen(gridColor);
    double cellWidth = (double) size / 100 ; // width of the widget / number of cells at one row
    for (double k = cellWidth; k <= size; k += cellWidth)
        p.drawLine(k, 0, k, size);
    double cellHeight = (double) size / 100; // height of the widget / number of cells at one row
    for (double k = cellHeight; k <= size; k += cellHeight)
        p.drawLine(0, k, size, k);
    p.drawRect(borders);
}




