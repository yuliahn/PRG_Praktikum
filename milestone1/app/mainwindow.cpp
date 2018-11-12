#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "visualcrypt.h"
#include "encode_widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(0, &enc_widg);
    ui->stackedWidget->insertWidget(1, &dec_widg);
    ui->stackedWidget->insertWidget(2, &over_widg);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_activated(const QString &arg1)
{
    ui->stackedWidget->setCurrentIndex(ui->comboBox->currentIndex());
}

