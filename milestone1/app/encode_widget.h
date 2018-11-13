#ifndef ENCODE_WIDGET_H
#define ENCODE_WIDGET_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtGui>
#include <QtCore>

#include "visualcrypt.h"

namespace Ui {
class encode_widget;
}

class encode_widget : public QWidget
{
    Q_OBJECT

public:
    explicit encode_widget(QWidget *parent = nullptr);
    ~encode_widget();

private slots:

    void on_import_data_clicked();
    void on_generate_key_clicked();
    void on_encode_clicked();
    void on_export_result_clicked();
    void on_export_key_clicked();

private:
    Ui::encode_widget *ui;
    void drawImage(vector <vector <int>>);
    QGraphicsScene *graphic = new QGraphicsScene();
    NBild image;
    CBild result;
    CBild key;

};

#endif // ENCODE_WIDGET_H
