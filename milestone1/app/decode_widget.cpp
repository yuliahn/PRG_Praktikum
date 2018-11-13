#include "decode_widget.h"
#include "ui_decode_widget.h"
#include "mainwindow.h"
#include "visualcrypt.h"

decode_widget::decode_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::decode_widget)
{
    ui->setupUi(this);
}

decode_widget::~decode_widget()
{
    delete ui;
}

void decode_widget::on_import_file_clicked()
{
    graphic->clear();
    graphic->update();

    QString fileName = QFileDialog::getOpenFileName(this, "Datei öffnen", save_dir);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"Error",file.errorString());
    }
    QTextStream in (&file);
    result.importData(fileName.toStdString());

    int rows = result.getRows();
    int cols = result.getCols();
    vector <vector <int>> pixelData = result.getMatrix();

    QImage drawImage;
    drawImage = QImage(cols, rows, QImage::Format_Mono);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            int color = result.getMatrix()[i][j];
            drawImage.setPixel(j,i, color);
        }
    }

    graphic->addPixmap(QPixmap::fromImage(drawImage));
    ui->graphicsView->setScene(graphic);
}

void decode_widget::on_import_key_clicked()
{
    graphic->clear();
    graphic->update();

    QString fileName = QFileDialog::getOpenFileName(this, "Datei öffnen", save_dir);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"Error",file.errorString());
    }
    QTextStream in (&file);
    key.importData(fileName.toStdString());

    int rows = key.getRows();
    int cols = key.getCols();
    vector <vector <int>> pixelData = key.getMatrix();

    QImage drawImage;
    drawImage = QImage(cols, rows, QImage::Format_Mono);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            int color = key.getMatrix()[i][j];
            drawImage.setPixel(j,i, color);
        }
    }

    graphic->addPixmap(QPixmap::fromImage(drawImage));
    ui->graphicsView->setScene(graphic);

}

void decode_widget::on_save_image_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save image"),
                               save_dir,
                               tr("Text files (*.txt)"));
    QFile file(fileName);
    QTextStream in (&file);
    result.exportData(fileName.toStdString());
}

void decode_widget::on_decode_clicked()
{
    graphic->clear();
    graphic->update();

    NBild decImg(decode(result.getMatrix(), key.getMatrix()));
    image = decImg;

    int rows = image.getRows();
    int cols = image.getCols();
    vector <vector <int>> pixelData = image.getMatrix();

    QImage drawImage;
    drawImage = QImage(cols, rows, QImage::Format_Mono);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            int color = image(i,j);
            drawImage.setPixel(j,i, color);
        }
    }

    graphic->addPixmap(QPixmap::fromImage(drawImage));
    ui->graphicsView->setScene(graphic);
}
