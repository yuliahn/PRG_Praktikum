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

private:
    Ui::Canvas *ui;
    vector<vector<double>> canvas;

};

#endif // CANVAS_H
