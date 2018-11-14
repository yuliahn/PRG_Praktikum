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


void MainWindow::on_comboBox_activated(const QString &arg1)
{
    ui->stackedWidget->setCurrentIndex(ui->comboBox->currentIndex());
}


void MainWindow::on_export_data_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Datei öffnen", save_dir);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"Error",file.errorString());
    }
    QTextStream in (&file);
    //add import function
}

void MainWindow::on_start_evo_clicked()
{
    QTime time = ui->timeEdit->time(); // set the duration of evolution using time

    // Set the size of the world matrix
    int rows = 2;//ui->spinBox_rows->value();
    int cols = 2;//ui->spinBox_cols->value();

    vector <vector <int>> matrix = {{0,0},{1,1}};

    QColor border = Qt::black;
    QColor fill;

    for (int i=0; i<rows*20; i+=20) {
        for (int j=0; j<cols*20; j+=20) {
            QRectF rect = QRectF(j,i,20,20);
            if (matrix[i/20][j/20] == 0) {fill = Qt::white;}
            else {fill = Qt::black;}
            graphic->addRect(rect, border, fill);
        }
    }

    //graphic->addRect(rect, border, fill);
    ui->graphicsView->setScene(graphic);

}
