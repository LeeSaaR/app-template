#ifndef WIDGETPROPDROPDOWNFILE_H
#define WIDGETPROPDROPDOWNFILE_H

#include <QWidget>

#include "configdata.h"

namespace Ui {
class WidgetPropDropDownFile;
}

class WidgetPropDropDownFile : public QWidget
{
    Q_OBJECT
private:
    Ui::WidgetPropDropDownFile *ui;
    ConfigData *m_config_data;

public:
    explicit WidgetPropDropDownFile(ConfigData *config_data, QWidget *parent = nullptr);
    ~WidgetPropDropDownFile();

public:
    QString value() const;
    void setName(const QString &propName);
    void setValue(const QString &value);
    void setValues(const QList<QString> &values);

private slots:
    void onActivated();
};

#endif // WIDGETPROPDROPDOWNFILE_H
