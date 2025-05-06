#include "widgetpropfile.h"
#include "ui_widgetpropfile.h"

#include <QFileDialog>
#include "appio.h"

WidgetPropFile::WidgetPropFile(ConfigData *config_data, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetPropFile),
    m_config_data(config_data)
{
    ui->setupUi(this);
    setObjectName(m_config_data->object_name());
    setName(m_config_data->name());
    setValue(m_config_data->value());
    connect(ui->btn, &QPushButton::clicked, this, &WidgetPropFile::onClickedButton);
}

WidgetPropFile::~WidgetPropFile()
{
    delete ui;
}

void WidgetPropFile::setName(const QString &value)
{
    ui->label->setText(value);
}

void WidgetPropFile::setValue(const QString &value)
{
    ui->btn->setText(value);
}

QString WidgetPropFile::value() const
{
    return ui->btn->text();
}

void WidgetPropFile::onClickedButton()
{
    QString file = ui->btn->text();
    QString dir = "";
    if (file.isEmpty() || !AppIO::fileExists(file)) {
        dir = QDir::homePath();
    }

    if (AppIO::fileExists(file)) {
        dir = QFileInfo(file).absolutePath();
    }

    const QString newFile = QFileDialog::getOpenFileName(this, "Select A File", dir);
    if (!newFile.isEmpty()) {
        ui->btn->setText(newFile);
        m_config_data->setValue(newFile);
    }
}

