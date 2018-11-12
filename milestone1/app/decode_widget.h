#ifndef DECODE_WIDGET_H
#define DECODE_WIDGET_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <QFileDialog>
#include <QGraphicsScene>
#include <QtGui>
#include <QtCore>

namespace Ui {
class decode_widget;
}

class decode_widget : public QWidget
{
    Q_OBJECT

public:
    explicit decode_widget(QWidget *parent = nullptr);
    ~decode_widget();

private slots:
    void on_import_file_clicked();

private:
    Ui::decode_widget *ui;
};

#endif // DECODE_WIDGET_H
