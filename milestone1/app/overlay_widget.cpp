#include "overlay_widget.h"
#include "ui_overlay_widget.h"
#include "mainwindow.h"
#include "visualcrypt.h"

overlay_widget::overlay_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::overlay_widget)
{
    ui->setupUi(this);
}

overlay_widget::~overlay_widget()
{
    delete ui;
}


void overlay_widget::on_import_img1_clicked()
{
    graphic->clear();
    graphic->update();

    QString fileName = QFileDialog::getOpenFileName(this, "Datei öffnen", save_dir);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"Error",file.errorString());
    }
    QTextStream in (&file);
    image1.importData(fileName.toStdString());

    int rows = image1.getRows();
    int cols = image1.getCols();
    vector <vector <int>> pixelData = image1.getMatrix();

    QImage drawImage;
    drawImage = QImage(cols, rows, QImage::Format_Mono);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            int color = image1(i,j);
            drawImage.setPixel(j,i, color);
        }
    }

    graphic->addPixmap(QPixmap::fromImage(drawImage));
    ui->graphicsView->setScene(graphic);

}

void overlay_widget::on_import_img2_clicked()
{
    graphic->clear();
    graphic->update();

    QString fileName = QFileDialog::getOpenFileName(this, "Datei öffnen", save_dir);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"Error",file.errorString());
    }
    QTextStream in (&file);
    image2.importData(fileName.toStdString());

    int rows = image2.getRows();
    int cols = image2.getCols();
    vector <vector <int>> pixelData = image2.getMatrix();

    QImage drawImage;
    drawImage = QImage(cols, rows, QImage::Format_Mono);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            int color = image2(i,j);
            drawImage.setPixel(j,i, color);
        }
    }

    graphic->addPixmap(QPixmap::fromImage(drawImage));
    ui->graphicsView->setScene(graphic);
}


void overlay_widget::on_save_overlay_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save image"),
                               save_dir,
                               tr("Text files (*.txt)"));
    QFile file(fileName);
    QTextStream in (&file);
    result.exportData(fileName.toStdString());
}

void overlay_widget::on_overlay_clicked()
{
    graphic->clear();
    graphic->update();

    NBild newResult(overlay(image1.getMatrix(), image2.getMatrix()));
    result = newResult;

    int rows = result.getRows();
    int cols = result.getCols();
    vector <vector <int>> pixelData = result.getMatrix();

    QImage drawImage;
    drawImage = QImage(cols, rows, QImage::Format_Mono);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            int color = result(i,j);
            drawImage.setPixel(j,i, color);
        }
    }

    graphic->addPixmap(QPixmap::fromImage(drawImage));
    ui->graphicsView->setScene(graphic);
}
