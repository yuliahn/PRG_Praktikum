#ifndef OVERLAY_WIDGET_H
#define OVERLAY_WIDGET_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <QFileDialog>
#include <QGraphicsScene>
#include <QtGui>
#include <QtCore>

namespace Ui {
class overlay_widget;
}

class overlay_widget : public QWidget
{
    Q_OBJECT

public:
    explicit overlay_widget(QWidget *parent = nullptr);
    ~overlay_widget();

private slots:
    void on_pushButton_4_clicked();

    void on_import_img1_clicked();

    void on_import_img2_clicked();

    void on_save_overlay_clicked();

private:
    Ui::overlay_widget *ui;
};

#endif // OVERLAY_WIDGET_H
