#include "canvas.h"
#include "ui_canvas.h"

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
}

Canvas::~Canvas()
{
    delete ui;
}

vector<vector<double>> Canvas::setCanvas(int x, int y)
{
    vector<double> row;

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
