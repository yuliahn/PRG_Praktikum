#ifndef OVERLAY_WIDGET_H
#define OVERLAY_WIDGET_H

#include <QWidget>

namespace Ui {
class overlay_widget;
}

class overlay_widget : public QWidget
{
    Q_OBJECT

public:
    explicit overlay_widget(QWidget *parent = nullptr);
    ~overlay_widget();

private:
    Ui::overlay_widget *ui;
};

#endif // OVERLAY_WIDGET_H
