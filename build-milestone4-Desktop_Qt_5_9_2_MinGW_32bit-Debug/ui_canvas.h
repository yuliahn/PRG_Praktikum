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
        widget->setGeometry(QRect(440, 90, 293, 90));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
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
        rowsPixel->setValue(50);

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
        columnsPixel->setValue(50);

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
    } // retranslateUi

};

namespace Ui {
    class Canvas: public Ui_Canvas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVAS_H
