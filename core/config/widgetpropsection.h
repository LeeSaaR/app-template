#ifndef WIDGETPROPSECTION_H
#define WIDGETPROPSECTION_H

#include <QWidget>

namespace Ui {
class WidgetPropSection;
}

class WidgetPropSection : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetPropSection(QWidget *parent = nullptr, const QString &sectionName = "", const bool &isTop = false);
    ~WidgetPropSection();

private:
    Ui::WidgetPropSection *ui;
};

#endif // WIDGETPROPSECTION_H
