#include "dialogprojectsettings.h"
#include "./ui_dialogprojectsettings.h"

#include <QDebug>
#include "appdata.h"

DialogProjectSettings::DialogProjectSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogProjectSettings)

{
    ui->setupUi(this);
    initDialog();
}

DialogProjectSettings::~DialogProjectSettings()
{
    delete ui;
}

void DialogProjectSettings::initDialog()
{
    initUI();
    initConnections();
    load();
}

void DialogProjectSettings::initUI()
{
    AppData* appData = AppData::GetInstance();
    setWindowTitle(appData->appName() + " - Project Settings");
    ui->frame_scrollArea->setStyleSheet("QWidget[accessibleName=\"scrollArea\"] {background-color: transparent;}");
}

void DialogProjectSettings::initConnections()
{
    connect(ui->btn_save, &QPushButton::clicked, this, &DialogProjectSettings::onClickedSave);
}

void DialogProjectSettings::load()
{
}

void DialogProjectSettings::save()
{
}

void DialogProjectSettings::onClickedSave()
{
    save();
    this->close();
}
