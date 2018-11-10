#ifndef CRYPTIMAGE_H
#define CRYPTIMAGE_H

#include <QWidget>

namespace Ui {
class CryptImage;
}

class CryptImage : public QWidget
{
    Q_OBJECT

public:
    explicit CryptImage(QWidget *parent = nullptr);
    ~CryptImage();

private:
    Ui::CryptImage *ui;
};

#endif // CRYPTIMAGE_H
