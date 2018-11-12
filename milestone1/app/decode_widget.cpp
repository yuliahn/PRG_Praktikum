#include "decode_widget.h"
#include "ui_decode_widget.h"

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
