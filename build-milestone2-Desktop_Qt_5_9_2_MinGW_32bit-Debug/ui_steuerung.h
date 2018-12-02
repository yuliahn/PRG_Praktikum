/********************************************************************************
** Form generated from reading UI file 'steuerung.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEUERUNG_H
#define UI_STEUERUNG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Steuerung
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *setLayout;
    QHBoxLayout *controlLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *clearButton;
    QLabel *label;
    QSpinBox *iterationInterval;
    QLabel *label_2;
    QDoubleSpinBox *alpha;
    QLabel *label_3;
    QDoubleSpinBox *beta;
    QLabel *label_4;
    QDoubleSpinBox *k0;
    QLabel *label_5;
    QSpinBox *maxIter;
    QLabel *label_6;
    QDoubleSpinBox *cvRatio;
    QLabel *label_7;
    QDoubleSpinBox *radius;
    QLabel *label_8;
    QHBoxLayout *CityLayout;
    QLabel *label_11;
    QDoubleSpinBox *fromCity;
    QLabel *label_12;
    QDoubleSpinBox *toCity;
    QLabel *label_9;
    QHBoxLayout *NodeLayout;
    QLabel *label_13;
    QDoubleSpinBox *fromNode;
    QLabel *label_14;
    QDoubleSpinBox *toNode;
    QLabel *label_10;
    QDoubleSpinBox *etaDestination;
    QSpacerItem *verticalSpacer;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *TSPLayout;

    void setupUi(QWidget *Steuerung)
    {
        if (Steuerung->objectName().isEmpty())
            Steuerung->setObjectName(QStringLiteral("Steuerung"));
        Steuerung->resize(904, 581);
        verticalLayoutWidget = new QWidget(Steuerung);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(536, 0, 352, 563));
        setLayout = new QVBoxLayout(verticalLayoutWidget);
        setLayout->setObjectName(QStringLiteral("setLayout"));
        setLayout->setContentsMargins(0, 0, 0, 0);
        controlLayout = new QHBoxLayout();
        controlLayout->setObjectName(QStringLiteral("controlLayout"));
        startButton = new QPushButton(verticalLayoutWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        controlLayout->addWidget(startButton);

        stopButton = new QPushButton(verticalLayoutWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        controlLayout->addWidget(stopButton);

        clearButton = new QPushButton(verticalLayoutWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        controlLayout->addWidget(clearButton);


        setLayout->addLayout(controlLayout);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        setLayout->addWidget(label);

        iterationInterval = new QSpinBox(verticalLayoutWidget);
        iterationInterval->setObjectName(QStringLiteral("iterationInterval"));
        iterationInterval->setMaximum(999999999);
        iterationInterval->setSingleStep(10);
        iterationInterval->setValue(10);

        setLayout->addWidget(iterationInterval);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        setLayout->addWidget(label_2);

        alpha = new QDoubleSpinBox(verticalLayoutWidget);
        alpha->setObjectName(QStringLiteral("alpha"));
        alpha->setValue(1);

        setLayout->addWidget(alpha);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        setLayout->addWidget(label_3);

        beta = new QDoubleSpinBox(verticalLayoutWidget);
        beta->setObjectName(QStringLiteral("beta"));
        beta->setValue(1);

        setLayout->addWidget(beta);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        setLayout->addWidget(label_4);

        k0 = new QDoubleSpinBox(verticalLayoutWidget);
        k0->setObjectName(QStringLiteral("k0"));
        k0->setValue(0.1);

        setLayout->addWidget(k0);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        setLayout->addWidget(label_5);

        maxIter = new QSpinBox(verticalLayoutWidget);
        maxIter->setObjectName(QStringLiteral("maxIter"));
        maxIter->setMaximum(2000000000);
        maxIter->setSingleStep(1);
        maxIter->setValue(10000);

        setLayout->addWidget(maxIter);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        setLayout->addWidget(label_6);

        cvRatio = new QDoubleSpinBox(verticalLayoutWidget);
        cvRatio->setObjectName(QStringLiteral("cvRatio"));
        cvRatio->setValue(2.5);

        setLayout->addWidget(cvRatio);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        setLayout->addWidget(label_7);

        radius = new QDoubleSpinBox(verticalLayoutWidget);
        radius->setObjectName(QStringLiteral("radius"));
        radius->setValue(0.1);

        setLayout->addWidget(radius);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        setLayout->addWidget(label_8);

        CityLayout = new QHBoxLayout();
        CityLayout->setObjectName(QStringLiteral("CityLayout"));
        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        CityLayout->addWidget(label_11, 0, Qt::AlignRight);

        fromCity = new QDoubleSpinBox(verticalLayoutWidget);
        fromCity->setObjectName(QStringLiteral("fromCity"));

        CityLayout->addWidget(fromCity);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        CityLayout->addWidget(label_12, 0, Qt::AlignRight);

        toCity = new QDoubleSpinBox(verticalLayoutWidget);
        toCity->setObjectName(QStringLiteral("toCity"));

        CityLayout->addWidget(toCity);


        setLayout->addLayout(CityLayout);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        setLayout->addWidget(label_9);

        NodeLayout = new QHBoxLayout();
        NodeLayout->setObjectName(QStringLiteral("NodeLayout"));
        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        NodeLayout->addWidget(label_13, 0, Qt::AlignRight);

        fromNode = new QDoubleSpinBox(verticalLayoutWidget);
        fromNode->setObjectName(QStringLiteral("fromNode"));

        NodeLayout->addWidget(fromNode);

        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        NodeLayout->addWidget(label_14, 0, Qt::AlignRight);

        toNode = new QDoubleSpinBox(verticalLayoutWidget);
        toNode->setObjectName(QStringLiteral("toNode"));

        NodeLayout->addWidget(toNode);


        setLayout->addLayout(NodeLayout);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        setLayout->addWidget(label_10);

        etaDestination = new QDoubleSpinBox(verticalLayoutWidget);
        etaDestination->setObjectName(QStringLiteral("etaDestination"));
        etaDestination->setDecimals(4);
        etaDestination->setValue(0.005);

        setLayout->addWidget(etaDestination);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        setLayout->addItem(verticalSpacer);

        verticalLayoutWidget_2 = new QWidget(Steuerung);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 521, 471));
        TSPLayout = new QVBoxLayout(verticalLayoutWidget_2);
        TSPLayout->setObjectName(QStringLiteral("TSPLayout"));
        TSPLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Steuerung);

        QMetaObject::connectSlotsByName(Steuerung);
    } // setupUi

    void retranslateUi(QWidget *Steuerung)
    {
        Steuerung->setWindowTitle(QApplication::translate("Steuerung", "Form", Q_NULLPTR));
        startButton->setText(QApplication::translate("Steuerung", "Start", Q_NULLPTR));
        stopButton->setText(QApplication::translate("Steuerung", "Stop", Q_NULLPTR));
        clearButton->setText(QApplication::translate("Steuerung", "Clear", Q_NULLPTR));
        label->setText(QApplication::translate("Steuerung", "Iteration Interval (in msec)", Q_NULLPTR));
        label_2->setText(QApplication::translate("Steuerung", "Alpha", Q_NULLPTR));
        label_3->setText(QApplication::translate("Steuerung", "Beta", Q_NULLPTR));
        label_4->setText(QApplication::translate("Steuerung", "K0", Q_NULLPTR));
        label_5->setText(QApplication::translate("Steuerung", "Max. No. Iterations", Q_NULLPTR));
        label_6->setText(QApplication::translate("Steuerung", "CV ratio", Q_NULLPTR));
        label_7->setText(QApplication::translate("Steuerung", "Radius", Q_NULLPTR));
        label_8->setText(QApplication::translate("Steuerung", "City Value Interval", Q_NULLPTR));
        label_11->setText(QApplication::translate("Steuerung", "from:", Q_NULLPTR));
        label_12->setText(QApplication::translate("Steuerung", "to:", Q_NULLPTR));
        label_9->setText(QApplication::translate("Steuerung", "Node Value Interval", Q_NULLPTR));
        label_13->setText(QApplication::translate("Steuerung", "from:", Q_NULLPTR));
        label_14->setText(QApplication::translate("Steuerung", "to:", Q_NULLPTR));
        label_10->setText(QApplication::translate("Steuerung", "Eta Destination", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Steuerung: public Ui_Steuerung {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEUERUNG_H
