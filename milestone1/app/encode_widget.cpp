#include "encode_widget.h"
#include "ui_encode_widget.h"
#include "mainwindow.h"
#include "visualcrypt.h"

encode_widget::encode_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::encode_widget)
{
    ui->setupUi(this);
}

encode_widget::~encode_widget()
{
    delete ui;
}


void encode_widget::on_import_data_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Datei öffnen", save_dir);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"Error",file.errorString());
    }
    QTextStream in (&file);
    image.importData(fileName.toStdString());

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

void encode_widget::on_generate_key_clicked()
{

    graphic->clear();
    graphic->update();

    CBild newImage(image.getRows(), image.getCols());
    result = newImage;

    int rows = result.getMatrix().size();
    int cols = result.getMatrix()[0].size();

    vector <vector <int>> pixelData = result.getMatrix();

    QImage genKey;
    genKey = QImage(cols, rows, QImage::Format_Mono);

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            int color = result.getMatrix()[i][j];
            genKey.setPixel(j,i, color);
        }
    }

    graphic->addPixmap(QPixmap::fromImage(genKey));
    ui->graphicsView->setScene(graphic);

}


void encode_widget::on_encode_clicked()
{
    graphic->clear();
    graphic->update();

    CBild newKey(encode(image.getMatrix(), result.getMatrix()));
    key = newKey;

    int rows = key.getMatrix().size();
    int cols = key.getMatrix()[0].size();

    vector <vector <int>> pixelData = key.getMatrix();

    QImage encImg;
    encImg = QImage(cols, rows, QImage::Format_Mono);

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            int color = key.getMatrix()[i][j];
            encImg.setPixel(j,i, color);
        }
    }

    graphic->addPixmap(QPixmap::fromImage(encImg));
    ui->graphicsView->setScene(graphic);
}

void encode_widget::on_export_result_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save image"),
                               save_dir,
                               tr("Text files (*.txt)"));
    QFile file(fileName);
    QTextStream in (&file);
    result.exportData(fileName.toStdString());
}

void encode_widget::on_export_key_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save key"),
                               save_dir,
                               tr("Text files (*.txt)"));
    QFile file(fileName);
    QTextStream in (&file);
    key.exportData(fileName.toStdString());
}


