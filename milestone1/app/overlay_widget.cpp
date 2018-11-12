#include "overlay_widget.h"
#include "ui_overlay_widget.h"

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
