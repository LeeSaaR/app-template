#ifndef WIDGETPROPFILE_H
#define WIDGETPROPFILE_H

#include <QWidget>

#include "configdata.h"

namespace Ui {
class WidgetPropFile;
}

class WidgetPropFile : public QWidget
{
    Q_OBJECT
private:
    Ui::WidgetPropFile *ui;
    ConfigData *m_config_data;

public:
    explicit WidgetPropFile(ConfigData *config_data, QWidget *parent = nullptr);
    ~WidgetPropFile();

public:
    void setName(const QString &value);
    void setValue(const QString &value);
    QString value()const;

private slots:
    void onClickedButton();
};

#endif // WIDGETPROPFILE_H
