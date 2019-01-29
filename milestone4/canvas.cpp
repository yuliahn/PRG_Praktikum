#include "canvas.h"
#include "ui_canvas.h"

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <iostream>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
    this->xPixel = ui->rowsPixel->value();
    this->yPixel = ui->columnsPixel->value();

    vector<int> topology = {784,64,10};
    NeuralNet neuralNet(topology);
    this->net = neuralNet;


}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::on_setButton_clicked()
{
    cout << "im here";
    for (int i = 0; i < xPixel; i++) {
        for (int j = 0; j < yPixel; j++) {
            canvas[i][j] = 0;
        }
    }
    this->xPixel = ui->rowsPixel->value();
    this->yPixel = ui->columnsPixel->value();
    setCanvas(xPixel, yPixel);
    cout << "Test2";
    update();
}

void Canvas::on_clearButton_clicked()
{
    cout<<"clear button";
    for (int i = 0; i < xPixel; i++) {
        for (int j = 0; j < yPixel; j++) {
            canvas[i][j] = 0;
        }
    }
    update();
}

vector<vector<double>> Canvas::setCanvas(int x, int y)
{
    vector<double> row;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            double color = 0;
            row.push_back(color);
        }
        canvas.push_back(row);
        row.clear();
    }

    return canvas;
}



void Canvas::setPixel(int i, int j)
{
    canvas[i][j] = 255;
    if (canvas[i][j-1] + 64 <= 255) {
        canvas[i][j-1] += 64;
    } else {
        canvas[i][j-1] = 255;
    }

    if (canvas[i][j+1] + 64 <= 255) {
        canvas[i][j+1] += 64;
    } else {
        canvas[i][j+1] = 255;
    }

    if (canvas[i-1][j] + 64 <= 255) {
        canvas[i-1][j] += 64;
    } else {
        canvas[i-1][j] = 255;
    }

    if (canvas[i+1][j] + 64 <= 255) {
        canvas[i+1][j] += 64;
    } else {
        canvas[i+1][j] = 255;
    }

}

void Canvas::paintEvent(QPaintEvent * event) {
    emit environmentChanged(true);
    QPainter p(this);
    setCanvas(xPixel, yPixel);
    createField(p);
    paintField(p);
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    double cellWidth = 400/xPixel;
    double cellHeight = 400/yPixel;
    int k = floor(event->y()/cellHeight)+1;
    int j = floor(event->x()/cellWidth)+1;

    setPixel(j, k);
    update();
}

/**
 * @brief TSPwidget::mouseMoveEvent
 * Adds cities to the elastic net, when mouse is pressed while moving.
 * @param event
 */
void Canvas::mouseMoveEvent(QMouseEvent *event) {
    double cellWidth = 400/xPixel;
    double cellHeight = 400/yPixel;
    int k = floor(event->y()/cellHeight)+1;
    int j = floor(event->x()/cellWidth)+1;

    setPixel(j, k);
    update();
}

void Canvas::createField(QPainter &p){
    int size = 400;
    QRect borders(0, 0, size, size); // borders of the universe
    QColor gridColor = "#000"; // color of the grid
    gridColor.setAlpha(20); // must be lighter than main color
    p.setPen(gridColor);
    double cellWidth = (double) size / xPixel ; // width of the widget / number of cells at one row
    for (double k = cellWidth; k <= size; k += cellWidth)
        p.drawLine(k, 0, k, size);
    double cellHeight = (double) size / yPixel; // height of the widget / number of cells at one row
    for (double k = cellHeight; k <= size; k += cellHeight)
        p.drawLine(0, k, size, k);
    p.drawRect(borders);
}

void Canvas::paintField(QPainter &p) {
    int size = 400;
    double cellWidth = (double) size / xPixel ;
    double cellHeight = (double) size / yPixel ;
    for (int i = 0; i < xPixel; i++) {
        for (int j = 0; j < yPixel; j++) {
            QRectF r(i*cellWidth, j*cellHeight, cellWidth, cellHeight);
            QColor color;
            p.fillRect(r, color.fromHsv(0,0,255-canvas[i][j]));
        }
    }
}


void Canvas::setPixel(int i, int j, unsigned int value)
{
    canvas[i][j] = value;
}


void Canvas::on_testData_clicked()
{
    this->xPixel = 28;
    this->yPixel = 28;
    setCanvas(xPixel, yPixel);

    // /*
    const char* imagesFile = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\training_images\\images.bin";
    const char* labelsFile = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\training_images\\images.labels";

    cout << "Importing data from images..." << endl;
    char* buffer = importFile(imagesFile);
    vector<vector<vector<unsigned int>>> data = copyData(buffer); // data format: data[batch][image][pixel]

    cout << "\nImporting data from labels..." << endl;
    char* labelsBuffer = importFile(labelsFile);
    vector<vector<unsigned int>> labels = copyLabels(labelsBuffer);
    // */


    vector <unsigned int> testData = data[0][ui->spinBox->value()];
    unsigned int counter = 0;
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) {
            unsigned int value = testData[counter++];
            setPixel(j, i,value);
            cout << value << ' ';
        }
        cout << endl;
    }

    int number = labels[0][ui->spinBox->value()];
    cout << number << endl;
    ui->label->display(number);

    update();
}

void Canvas::on_importDataButton_clicked()
{
    QString save_dir = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\training_images\\";
    QString fileName = QFileDialog::getOpenFileName(this, "Import data", save_dir);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"Error",file.errorString());
    }
    QTextStream in (&file);

    QByteArray ba = fileName.toLocal8Bit();
    const char* imagesFile = ba.data();

    cout << "Importing data from images..." << endl;
    char* buffer = importFile(imagesFile);
    data = copyData(buffer); // data format: data[batch][image][pixel]
}

void Canvas::on_importLabelsButton_clicked()
{
    QString save_dir = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\training_images\\";
    QString fileName = QFileDialog::getOpenFileName(this, "Import labels", save_dir);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"Error",file.errorString());
    }
    QTextStream in (&file);

    QByteArray ba = fileName.toLocal8Bit();
    const char* labelsFile = ba.data();

    cout << "Importing data from labels..." << endl;
    char* buffer = importFile(labelsFile);
    labels = copyLabels(buffer); // labels format: labels[batch][imageLabel]
}


void Canvas::on_feedImage_clicked()
{
    cout << "test" << endl;
    double eta = 0.3; //0.3
    double alpha = 0;
    vector <unsigned int> input;

    for (unsigned int i = 0; i < 28; i++) {
        for (unsigned int j = 0; j < 28; j++) {
            input.push_back(canvas[i][j]);
            cout << canvas[i][j] << ' ';
        }
        cout << endl;
    }

    vector<double> values(10,0);
    cout << ui->labelImageInput->value() << endl;
    values[ui->labelImageInput->value()] = 1; //

    cout << "Input size: " << input.size() << endl;
    cout << "Input: ";
    for (unsigned int i = 0; i < input.size(); i++) {
        cout << input[i] << ' ';
    }
    net.setInput(input);
    cout << "Input was set" << endl;
    net.back(eta, alpha, values);

    cout << "Image feeded." << endl;
}

void Canvas::on_trainButton_clicked()
{
    double eta = 0.3;
    double alpha = 0;
    double batchError = net.trainBatch(data, labels, eta, alpha, 0);
    for (unsigned int batch = 1; batch < 10; batch++) { //120 batches
        cout << "\nTraining batch " << batch << "..." << endl;
        double curBatchError = net.trainBatch(data, labels, eta, alpha, batch);
        if (curBatchError - batchError <= 0.01) {
            eta = 1.05 * eta;
            batchError = curBatchError;
        } else {
            max(0.01, 0.5*eta);
        }
    }

    vector <unsigned int> testData = data[0][3];
    unsigned int counter = 0;
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) {
            unsigned int value = testData[counter++];
            setPixel(j, i, value);
            cout << value << ' ';
        }
        cout << endl;
    }

    int number = labels[0][3];
    cout << number << endl;
    ui->label->display(number);

    update();

}

void Canvas::on_predictNumberButton_clicked()
{
    net.importState("C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\trainedANN.txt");

    // read data from canvas as input
    vector <unsigned int> input;
    for (int i = 0; i < canvas.size(); i++) {
        for (int j = 0; j < canvas[0].size(); j++) {
            input.push_back(canvas[i][j]);
        }
    }

    net.setInput(input);

    // find max from net.getOutput() and display number on QLCD display
    vector <double> output = net.getOutput();
    double max = output[0];
    int number = 0;
    for (unsigned int i = 1; i < output.size(); i++) {
        if (output[i] > max) {
            max = output[i];
            number = i;
        }
    }
    ui->label->display(number);

    update();
}

void Canvas::on_exportWeightsButton_clicked()
{
    QString save_dir = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\training_images\\";
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save key"),
                               save_dir,
                               tr("Text files (*.txt)"));
    QFile file(fileName);
    QTextStream in (&file);
    net.exportState(fileName.toStdString());

}

void Canvas::on_importWeightsButton_clicked()
{
    QString save_dir = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestones\\build-milestone4-Desktop_Qt_5_9_2_MinGW_32bit-Debug\\training_images\\";

    QString fileName = QFileDialog::getOpenFileName(this, "Import labels", save_dir);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"Error",file.errorString());
    }
    QTextStream in (&file);

    net.importState(fileName.toStdString());
}
