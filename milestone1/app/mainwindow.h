#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

#include <QPainter>
#include <QPaintEvent>

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QComboBox>
#include <QStackedWidget>

#include "encode_widget.h"
#include "decode_widget.h"
#include "overlay_widget.h"

const QString save_dir = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\sources\\milestone1";

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_activated(const QString &arg1);
    
private:
    Ui::MainWindow *ui;
    encode_widget enc_widg;
    decode_widget dec_widg;
    overlay_widget over_widg;

};

#endif // MAINWINDOW_H
