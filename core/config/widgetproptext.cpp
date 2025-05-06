#include "widgetproptext.h"
#include "ui_widgetproptext.h"

WidgetPropText::WidgetPropText(ConfigData *config_data, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetPropText),
    m_config_data(config_data)
{
    ui->setupUi(this);
    setObjectName(m_config_data->object_name());
    setName(m_config_data->name());
    setValue(m_config_data->value());
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &WidgetPropText::onTextChanged);
}

WidgetPropText::~WidgetPropText()
{
    delete ui;
}

void WidgetPropText::setName(const QString &name)
{
    ui->label->setText(name);
}

void WidgetPropText::setValue(const QString &value)
{
    ui->lineEdit->setText(value);
}

QString WidgetPropText::value() const
{
    return ui->lineEdit->text();
}

void WidgetPropText::onTextChanged()
{
    m_config_data->setValue(value());
}
