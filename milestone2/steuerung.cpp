//author: Ischa Tahir (5935200)

#include "steuerung.h"
#include "ui_steuerung.h"

Steuerung::Steuerung(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Steuerung),
    tsp(new TSPwidget(this))
{
    ui->setupUi(this);

    connect(ui->startButton, SIGNAL(clicked()), tsp,
            SLOT(startTSP()));                    // Start TSP with press the button "Start"
    connect(ui->stopButton, SIGNAL(clicked()), tsp,
            SLOT(stopTSP()));                      // Stop TSP with press the button "Stop"
    connect(ui->clearButton, SIGNAL(clicked()), tsp,
            SLOT(clear()));                        // Clear TSP field with press the button "Clear"
    connect(ui->iterationInterval, SIGNAL(valueChanged(int)), tsp, SLOT(setInterval(
            int)));     // Changing the interval between iteration with press the button "Iteration interval"
    connect(ui->alpha, SIGNAL(clicked()), tsp,
            SLOT();)


    //connect(ui->cellsControl, SIGNAL(valueChanged(int)), tsp,
    //        SLOT(setCellNumber(int)));   // Change the Universe Size  with press the button "Universe Size"

    //connect(tsp, SIGNAL(environmentChanged(bool)), ui->cellsControl,
    //        SLOT(setDisabled(bool))); // When one of the cell has been changed - lock the button "Universe Size"
    //connect(tsp, SIGNAL(TSPEnds(bool)), ui->cellsControl,
    //        SLOT(setEnabled(bool)));            // When game over - activate the button "Universe Size"

    ui->TSPLayout->addWidget(tsp);
}

Steuerung::~Steuerung()
{
    delete ui;
}

void Steuerung::on_label_linkActivated(const QString &link)
{

}
