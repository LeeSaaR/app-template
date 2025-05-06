#ifndef PROPWGT_H
#define PROPWGT_H

#include <QWidget>

class PropWgt
{
private:
    PropWgt() = delete;

public:
    static void setWidth(QWidget *widget, const int &width);
    static void setHeight(QWidget *widget, const int &height);
    static void setWindowSize(QWidget *widget, const int &width, const int &height);
};

#endif // PROPWGT_H
