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

NBild image1_overlay;
NBild image2_overlay;
NBild result_overlay;



void overlay_widget::on_import_img1_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Datei öffnen", save_dir);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"Error",file.errorString());
    }
    QTextStream in (&file);
    image1_overlay.importData(fileName.toStdString());
}

void overlay_widget::on_import_img2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Datei öffnen", save_dir);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"Error",file.errorString());
    }
    QTextStream in (&file);
    image2_overlay.importData(fileName.toStdString());
}


void overlay_widget::on_save_overlay_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save image"),
                               save_dir,
                               tr("Text files (*.txt)"));
    QFile file(fileName);
    QTextStream in (&file);
    result_overlay.exportData(fileName.toStdString());
}
