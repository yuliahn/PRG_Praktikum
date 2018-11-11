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
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);
    
private:
    Ui::MainWindow *ui;

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
