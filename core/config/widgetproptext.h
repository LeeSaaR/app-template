#ifndef WIDGETPROPTEXT_H
#define WIDGETPROPTEXT_H

#include <QWidget>

#include "configdata.h"

namespace Ui {
class WidgetPropText;
}

class WidgetPropText : public QWidget
{
    Q_OBJECT

private:
    Ui::WidgetPropText *ui;
    ConfigData *m_config_data;

public:
    explicit WidgetPropText(ConfigData *config_data, QWidget *parent = nullptr);
    ~WidgetPropText();

public:
    void setName(const QString &name);
    void setValue(const QString &value);
    QString value() const;

private slots:
    void onTextChanged();
};

#endif // WIDGETPROPTEXT_H
