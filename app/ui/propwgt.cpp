#include "propwgt.h"

void PropWgt::setWidth(QWidget *widget, const int &width)
{
    widget->setMinimumWidth(width);
    widget->setMaximumWidth(width);
}

void PropWgt::setHeight(QWidget *widget, const int &height)
{
    widget->setMinimumHeight(height);
    widget->setMaximumHeight(height);
}

void PropWgt::setWindowSize(QWidget *widget, const int &width, const int &height)
{
    setWidth(widget, width);
    setHeight(widget, height);
}
