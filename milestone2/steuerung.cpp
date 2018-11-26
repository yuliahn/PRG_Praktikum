//author: Ischa Tahir (5935200)

#include "steuerung.h"
#include "ui_steuerung.h"

Steuerung::Steuerung(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Steuerung)
{
    ui->setupUi(this);
}

Steuerung::~Steuerung()
{
    delete ui;
}

void Steuerung::on_label_linkActivated(const QString &link)
{

}
