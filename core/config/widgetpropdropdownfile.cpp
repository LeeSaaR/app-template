#include "widgetpropdropdownfile.h"
#include "ui_widgetpropdropdownfile.h"

#include <QFileInfo>

WidgetPropDropDownFile::WidgetPropDropDownFile(ConfigData *config_data, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetPropDropDownFile),
    m_config_data(config_data)
{
    ui->setupUi(this);
    setObjectName(m_config_data->object_name());
    setName(m_config_data->name());
    setValues(m_config_data->values());
    setValue(m_config_data->value());
    connect(ui->comboBox, &QComboBox::activated, this, &WidgetPropDropDownFile::onActivated);
}

WidgetPropDropDownFile::~WidgetPropDropDownFile()
{
    delete ui;
}

QString WidgetPropDropDownFile::value() const
{
    return ui->comboBox->currentData().toString();
}

void WidgetPropDropDownFile::setName(const QString &propName)
{
    ui->label->setText(propName);
}

void WidgetPropDropDownFile::setValue(const QString &value)
{
    QFileInfo fileInfo(value);
    ui->comboBox->setCurrentText(fileInfo.baseName());
}

void WidgetPropDropDownFile::setValues(const QList<QString> &values)
{
    for (const QString &value : values) {
        QFileInfo fileInfo(value);
        ui->comboBox->addItem(fileInfo.baseName());
        int index = ui->comboBox->count()-1;
        ui->comboBox->setItemData(index, value);
    }
}

void WidgetPropDropDownFile::onActivated()
{
    m_config_data->setValue(value());
}
