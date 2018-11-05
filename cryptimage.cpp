#include "cryptimage.h"
#include "ui_cryptimage.h"

CryptImage::CryptImage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CryptImage)
{
    ui->setupUi(this);
}

CryptImage::~CryptImage()
{
    delete ui;
}
