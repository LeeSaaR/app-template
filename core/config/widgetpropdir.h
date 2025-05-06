#ifndef WIDGETPROPDIR_H
#define WIDGETPROPDIR_H

#include <QWidget>

#include "configdata.h"

namespace Ui {
class WidgetPropDir;
}

class WidgetPropDir : public QWidget
{
    Q_OBJECT

private:
    Ui::WidgetPropDir *ui;
    ConfigData *m_config_data;

public:
    explicit WidgetPropDir(ConfigData *config_data, QWidget *parent = nullptr);
    ~WidgetPropDir();

public:
    void setName(const QString &value);
    void setValue(const QString &value);
    QString value()const;

private slots:
    void onClickedButton();

};

#endif // WIDGETPROPDIR_H
