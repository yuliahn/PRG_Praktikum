#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "visualcrypt.h"
#include "encode_widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Draw the image: Transform arrays to pixels:
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::white);
    painter.drawRect(0, 0, 1, 1);
}

Open file directory:*/


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::white);
    painter.drawRect(0, 0, 1, 1);
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    // show encode_widget
}
