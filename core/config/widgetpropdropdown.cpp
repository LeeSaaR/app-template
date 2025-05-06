#include "widgetpropdropdown.h"
#include "ui_widgetpropdropdown.h"

WidgetPropDropDown::WidgetPropDropDown(ConfigData *config_data, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetPropDropDown),
    m_config_data(config_data)
{
    ui->setupUi(this);
    setObjectName(m_config_data->object_name());
    setName(m_config_data->name());
    setValues(config_data->values());
    setValue(config_data->value());
    connect(ui->comboBox, &QComboBox::activated, this, &WidgetPropDropDown::onActivated);
}

WidgetPropDropDown::~WidgetPropDropDown()
{
    delete ui;
}

QString WidgetPropDropDown::value() const
{
    return ui->comboBox->currentData().toString();
}

void WidgetPropDropDown::setName(const QString &propName)
{
    ui->label->setText(propName);
}

void WidgetPropDropDown::setValue(const QString &value)
{
    ui->comboBox->setCurrentText(value);
}

void WidgetPropDropDown::setValues(const QList<QString> &values)
{
    for (int i = 0 ; i < values.size(); i++) {
        ui->comboBox->addItem(values[i]);
        int index = ui->comboBox->count()-1;
        ui->comboBox->setItemData(index, values[i]);
    }
}

void WidgetPropDropDown::onActivated()
{
    m_config_data->setValue(value());
}
