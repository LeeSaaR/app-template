#ifndef WIDGETPROPDROPDOWN_H
#define WIDGETPROPDROPDOWN_H

#include <QWidget>

#include "configdata.h"

namespace Ui {
class WidgetPropDropDown;
}

class WidgetPropDropDown : public QWidget
{
    Q_OBJECT

private:
    Ui::WidgetPropDropDown *ui;
    ConfigData *m_config_data;

public:
    explicit WidgetPropDropDown(ConfigData *config_data, QWidget *parent = nullptr);
    ~WidgetPropDropDown();

public:
    QString value() const;
    void setName(const QString &propName);
    void setValue(const QString &value);
    void setValues(const QList<QString> &values);

private slots:
    void onActivated();
};

#endif // WIDGETPROPDROPDOWN_H
