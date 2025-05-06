#include "widgetpropdir.h"
#include "ui_widgetpropdir.h"

#include <QFileDialog>
#include "appio.h"

WidgetPropDir::WidgetPropDir(ConfigData *config_data, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetPropDir),
    m_config_data(config_data)
{
    ui->setupUi(this);
    setObjectName(m_config_data->object_name());
    setName(m_config_data->name());
    setValue(m_config_data->value());
    connect(ui->btn, &QPushButton::clicked, this, &WidgetPropDir::onClickedButton);
}

WidgetPropDir::~WidgetPropDir()
{
    delete ui;
}

void WidgetPropDir::setName(const QString &value)
{
    ui->label->setText(value);
}

void WidgetPropDir::setValue(const QString &value)
{
    ui->btn->setText(value);
}

QString WidgetPropDir::value() const
{
    return ui->btn->text();
}

void WidgetPropDir::onClickedButton()
{
    QString dir = ui->btn->text();
    if (dir.isEmpty() || !AppIO::fileExists(dir)) {
        dir = QDir::homePath();
    }

    const QString directory = QFileDialog::getExistingDirectory(this, "Select A Dir", dir);
    if (!directory.isEmpty()) {
        ui->btn->setText(directory);
        m_config_data->setValue(directory);
    }
}
