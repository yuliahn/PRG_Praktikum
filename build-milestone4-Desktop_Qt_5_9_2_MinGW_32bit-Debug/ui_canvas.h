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
    QWidget *layoutWidget;
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
    QPushButton *testData;
    QLCDNumber *label;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *importDataButton;
    QPushButton *importLabelsButton;

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
        layoutWidget = new QWidget(Canvas);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(440, 90, 293, 90));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pixelLayout = new QVBoxLayout();
        pixelLayout->setObjectName(QStringLiteral("pixelLayout"));
        pixelDimensionsLabel = new QLabel(layoutWidget);
        pixelDimensionsLabel->setObjectName(QStringLiteral("pixelDimensionsLabel"));

        pixelLayout->addWidget(pixelDimensionsLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rowsDimension = new QHBoxLayout();
        rowsDimension->setObjectName(QStringLiteral("rowsDimension"));
        rowsLabel = new QLabel(layoutWidget);
        rowsLabel->setObjectName(QStringLiteral("rowsLabel"));

        rowsDimension->addWidget(rowsLabel);

        rowsPixel = new QSpinBox(layoutWidget);
        rowsPixel->setObjectName(QStringLiteral("rowsPixel"));
        rowsPixel->setValue(28);

        rowsDimension->addWidget(rowsPixel);


        horizontalLayout->addLayout(rowsDimension);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        columnsDimension = new QHBoxLayout();
        columnsDimension->setObjectName(QStringLiteral("columnsDimension"));
        columnsLabel = new QLabel(layoutWidget);
        columnsLabel->setObjectName(QStringLiteral("columnsLabel"));

        columnsDimension->addWidget(columnsLabel);

        columnsPixel = new QSpinBox(layoutWidget);
        columnsPixel->setObjectName(QStringLiteral("columnsPixel"));
        columnsPixel->setValue(28);

        columnsDimension->addWidget(columnsPixel);


        horizontalLayout->addLayout(columnsDimension);


        pixelLayout->addLayout(horizontalLayout);


        verticalLayout->addLayout(pixelLayout);

        controlLayout = new QHBoxLayout();
        controlLayout->setObjectName(QStringLiteral("controlLayout"));
        setButton = new QPushButton(layoutWidget);
        setButton->setObjectName(QStringLiteral("setButton"));

        controlLayout->addWidget(setButton);

        clearButton = new QPushButton(layoutWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        controlLayout->addWidget(clearButton);


        verticalLayout->addLayout(controlLayout);

        testData = new QPushButton(Canvas);
        testData->setObjectName(QStringLiteral("testData"));
        testData->setGeometry(QRect(440, 260, 161, 28));
        label = new QLCDNumber(Canvas);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(440, 300, 161, 121));
        label->setFrameShape(QFrame::NoFrame);
        label->setDigitCount(1);
        layoutWidget1 = new QWidget(Canvas);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(440, 200, 291, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        importDataButton = new QPushButton(layoutWidget1);
        importDataButton->setObjectName(QStringLiteral("importDataButton"));

        horizontalLayout_2->addWidget(importDataButton);

        importLabelsButton = new QPushButton(layoutWidget1);
        importLabelsButton->setObjectName(QStringLiteral("importLabelsButton"));

        horizontalLayout_2->addWidget(importLabelsButton);


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
        testData->setText(QApplication::translate("Canvas", "Test binary data", Q_NULLPTR));
        importDataButton->setText(QApplication::translate("Canvas", "Import data", Q_NULLPTR));
        importLabelsButton->setText(QApplication::translate("Canvas", "Import labels", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Canvas: public Ui_Canvas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVAS_H
