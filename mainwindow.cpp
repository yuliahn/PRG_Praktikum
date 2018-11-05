#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "visualcrypt.h"


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

void MainWindow::on_pushButton_2_clicked()
{
    /*

    */

    QString fileName = QFileDialog::getOpenFileName(this, "Open file","C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum");
    //QMessageBox::information(this,"title",fileName);

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"Error",file.errorString());
    }
    QTextStream in (&file);

    ui->textBrowser->setText(in.readAll());

}

/* Draw the image: Transform arrays to pixels:
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::white);
    painter.drawRect(0, 0, 1, 1);
}

Open file directory:*/
void MainWindow::on_pushButton_clicked()
{


}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::white);
    painter.drawRect(0, 0, 1, 1);
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    
}
