#include "widgetprop.h"

#include <QApplication>
#include <QScreen>

void WidgetProp::showMaximized(QDialog *widget)
{
    widget->setWindowFlag(Qt::WindowMaximizeButtonHint, true);
    widget->setWindowFlag(Qt::WindowMinimizeButtonHint, true);
    QSize screen_size = QApplication::primaryScreen()->size();
    widget->setGeometry(0,0, screen_size.width(), screen_size.height()-80);
    widget->showMaximized();
}
