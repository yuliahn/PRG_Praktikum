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

NBild image;
CBild result;
CBild key;

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
    drawImage = QImage(rows, cols, QImage::Format_Mono);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            int color = image(i,j);
            cout << image(i,j);
            drawImage.setPixel(i,j, color);
        }
    }

    QGraphicsScene *graphic = new QGraphicsScene(this);

    graphic->addPixmap(QPixmap::fromImage(drawImage));
    ui->graphicsView->setScene(graphic);




    // result.exportData(targetDir.append(fileName));


    /*
        string source = string(argv[2]); // set the source name to import the image to encrypt
        NBild image; // create a new instance of NBild
        image.importData(source); // import the contents
        cout << '\n' << "Image to encrypt:" << endl;
        image.print();

        //CBild result(1,2);
        CBild result(image.getRows(), image.getCols()); // generate a random key1 using sizes of the imported image
        fileName = "result.txt";
        result.exportData(targetDir.append(fileName)); // save the random key1 (encrypted image)
        targetDir = save_dir;
        cout << '\n' << "Encrypted image:" << endl;
        result.print();

        CBild key(encode(image.getMatrix(), result.getMatrix())); // generate a new key2 (key) by encoding image with key1 (result)
        cout << '\n' << "Generated key:" << endl;
        key.print();
        fileName = "key.txt";
        result.exportData(targetDir.append(fileName));
        targetDir = save_dir;
    */

}

void encode_widget::on_generate_key_clicked()
{
    CBild newImage(image.getRows(), image.getCols());
    result = newImage;

    int rows = result.getRows();
    int cols = result.getCols();
    vector <vector <int>> pixelData = result.getMatrix();

    QImage drawImage;
    drawImage = QImage(rows, cols, QImage::Format_Mono);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            int color = result(i,j);
            cout << result(i,j);
            drawImage.setPixel(i,j, color);
        }
    }

}

void encode_widget::on_encode_clicked()
{
    CBild newKey(encode(image.getMatrix(), result.getMatrix()));
    key = newKey;
}

void encode_widget::on_export_result_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Ergebnis speichern"),
                               save_dir,
                               tr("Text files (*.txt)"));
    result.exportData(fileName.toStdString());
}

void encode_widget::on_export_key_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Schlüssel speichern"),
                               save_dir,
                               tr("Text files (*.txt)"));
    key.exportData(fileName.toStdString());
}


