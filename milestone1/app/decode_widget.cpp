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

NBild image_decode;
CBild result_decode;
CBild key_decode;

void decode_widget::on_import_file_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Datei öffnen", save_dir);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"Error",file.errorString());
    }
    QTextStream in (&file);
    image_decode.importData(fileName.toStdString());
}
