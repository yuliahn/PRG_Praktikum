/********************************************************************************
** Form generated from reading UI file 'canvas.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANVAS_H
#define UI_CANVAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Canvas
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *canvas;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *pixelLayout;
    QLabel *pixelDimensionsLabel;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *rowsDimension;
    QLabel *rowsLabel;
    QSpinBox *rowsPixel;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *columnsDimension;
    QLabel *columnsLabel;
    QSpinBox *columnsPixel;
    QHBoxLayout *controlLayout;
    QPushButton *setButton;
    QPushButton *clearButton;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *exportWeightsButton;
    QPushButton *importWeightsButton;
    QHBoxLayout *importExportLayout;
    QPushButton *importDataButton;
    QPushButton *importLabelsButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *trainButton;
    QPushButton *stopButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *trainImageLabel;
    QSpinBox *labelImageInput;
    QPushButton *feedImage;
    QHBoxLayout *horizontalLayout_4;
    QLCDNumber *label;
    QVBoxLayout *verticalLayout_2;
    QPushButton *predictNumberButton;
    QSpinBox *spinBox;
    QPushButton *testData;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Canvas)
    {
        if (Canvas->objectName().isEmpty())
            Canvas->setObjectName(QStringLiteral("Canvas"));
        Canvas->resize(778, 598);
        verticalLayoutWidget = new QWidget(Canvas);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 90, 381, 331));
        canvas = new QVBoxLayout(verticalLayoutWidget);
        canvas->setObjectName(QStringLiteral("canvas"));
        canvas->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Canvas);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(440, 90, 297, 411));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pixelLayout = new QVBoxLayout();
        pixelLayout->setObjectName(QStringLiteral("pixelLayout"));
        pixelDimensionsLabel = new QLabel(widget);
        pixelDimensionsLabel->setObjectName(QStringLiteral("pixelDimensionsLabel"));

        pixelLayout->addWidget(pixelDimensionsLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rowsDimension = new QHBoxLayout();
        rowsDimension->setObjectName(QStringLiteral("rowsDimension"));
        rowsLabel = new QLabel(widget);
        rowsLabel->setObjectName(QStringLiteral("rowsLabel"));

        rowsDimension->addWidget(rowsLabel);

        rowsPixel = new QSpinBox(widget);
        rowsPixel->setObjectName(QStringLiteral("rowsPixel"));
        rowsPixel->setValue(28);

        rowsDimension->addWidget(rowsPixel);


        horizontalLayout->addLayout(rowsDimension);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        columnsDimension = new QHBoxLayout();
        columnsDimension->setObjectName(QStringLiteral("columnsDimension"));
        columnsLabel = new QLabel(widget);
        columnsLabel->setObjectName(QStringLiteral("columnsLabel"));

        columnsDimension->addWidget(columnsLabel);

        columnsPixel = new QSpinBox(widget);
        columnsPixel->setObjectName(QStringLiteral("columnsPixel"));
        columnsPixel->setValue(28);

        columnsDimension->addWidget(columnsPixel);


        horizontalLayout->addLayout(columnsDimension);


        pixelLayout->addLayout(horizontalLayout);


        verticalLayout->addLayout(pixelLayout);

        controlLayout = new QHBoxLayout();
        controlLayout->setObjectName(QStringLiteral("controlLayout"));
        setButton = new QPushButton(widget);
        setButton->setObjectName(QStringLiteral("setButton"));

        controlLayout->addWidget(setButton);

        clearButton = new QPushButton(widget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        controlLayout->addWidget(clearButton);


        verticalLayout->addLayout(controlLayout);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        exportWeightsButton = new QPushButton(widget);
        exportWeightsButton->setObjectName(QStringLiteral("exportWeightsButton"));

        horizontalLayout_5->addWidget(exportWeightsButton);

        importWeightsButton = new QPushButton(widget);
        importWeightsButton->setObjectName(QStringLiteral("importWeightsButton"));

        horizontalLayout_5->addWidget(importWeightsButton);


        verticalLayout_3->addLayout(horizontalLayout_5);

        importExportLayout = new QHBoxLayout();
        importExportLayout->setObjectName(QStringLiteral("importExportLayout"));
        importDataButton = new QPushButton(widget);
        importDataButton->setObjectName(QStringLiteral("importDataButton"));

        importExportLayout->addWidget(importDataButton);

        importLabelsButton = new QPushButton(widget);
        importLabelsButton->setObjectName(QStringLiteral("importLabelsButton"));

        importExportLayout->addWidget(importLabelsButton);


        verticalLayout_3->addLayout(importExportLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        trainButton = new QPushButton(widget);
        trainButton->setObjectName(QStringLiteral("trainButton"));

        horizontalLayout_2->addWidget(trainButton);

        stopButton = new QPushButton(widget);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        horizontalLayout_2->addWidget(stopButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        trainImageLabel = new QLabel(widget);
        trainImageLabel->setObjectName(QStringLiteral("trainImageLabel"));

        horizontalLayout_3->addWidget(trainImageLabel);

        labelImageInput = new QSpinBox(widget);
        labelImageInput->setObjectName(QStringLiteral("labelImageInput"));
        labelImageInput->setMaximum(9);

        horizontalLayout_3->addWidget(labelImageInput);

        feedImage = new QPushButton(widget);
        feedImage->setObjectName(QStringLiteral("feedImage"));

        horizontalLayout_3->addWidget(feedImage);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLCDNumber(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::NoFrame);
        label->setDigitCount(1);

        horizontalLayout_4->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        predictNumberButton = new QPushButton(widget);
        predictNumberButton->setObjectName(QStringLiteral("predictNumberButton"));

        verticalLayout_2->addWidget(predictNumberButton);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(499);

        verticalLayout_2->addWidget(spinBox);

        testData = new QPushButton(widget);
        testData->setObjectName(QStringLiteral("testData"));

        verticalLayout_2->addWidget(testData);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalSpacer = new QSpacerItem(20, 148, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        retranslateUi(Canvas);

        QMetaObject::connectSlotsByName(Canvas);
    } // setupUi

    void retranslateUi(QWidget *Canvas)
    {
        Canvas->setWindowTitle(QApplication::translate("Canvas", "Form", Q_NULLPTR));
        pixelDimensionsLabel->setText(QApplication::translate("Canvas", "Pixel dimensions", Q_NULLPTR));
        rowsLabel->setText(QApplication::translate("Canvas", "rows", Q_NULLPTR));
        rowsPixel->setSuffix(QApplication::translate("Canvas", " pixel", Q_NULLPTR));
        columnsLabel->setText(QApplication::translate("Canvas", "columns", Q_NULLPTR));
        columnsPixel->setSuffix(QApplication::translate("Canvas", " pixel", Q_NULLPTR));
        setButton->setText(QApplication::translate("Canvas", "Set canvas", Q_NULLPTR));
        clearButton->setText(QApplication::translate("Canvas", "Clear canvas", Q_NULLPTR));
        exportWeightsButton->setText(QApplication::translate("Canvas", "Export weights", Q_NULLPTR));
        importWeightsButton->setText(QApplication::translate("Canvas", "Import weights", Q_NULLPTR));
        importDataButton->setText(QApplication::translate("Canvas", "Import data", Q_NULLPTR));
        importLabelsButton->setText(QApplication::translate("Canvas", "Import labels", Q_NULLPTR));
        trainButton->setText(QApplication::translate("Canvas", "Train", Q_NULLPTR));
        stopButton->setText(QApplication::translate("Canvas", "Stop", Q_NULLPTR));
        trainImageLabel->setText(QApplication::translate("Canvas", "Label image", Q_NULLPTR));
        feedImage->setText(QApplication::translate("Canvas", "Feed image", Q_NULLPTR));
        predictNumberButton->setText(QApplication::translate("Canvas", "Predict number from input", Q_NULLPTR));
        testData->setText(QApplication::translate("Canvas", "Test binary data", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Canvas: public Ui_Canvas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVAS_H
