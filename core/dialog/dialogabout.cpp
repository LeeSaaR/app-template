#include "dialogabout.h"
#include "./ui_dialogabout.h"

#include "appdata.h"
#include "appimage.h"
#include "apptext.h"

DialogAbout::DialogAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAbout)
{
    ui->setupUi(this);
    initDialog();
    AppData* appData = AppData::GetInstance();
    ui->label_dev_url->setText("<a href=\""+ appData->appDevURL() +"/\">"+ appData->appDevURL() +"</a>");
    ui->label_dev_url->setTextFormat(Qt::RichText);
    ui->label_dev_url->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_dev_url->setOpenExternalLinks(true);
}

DialogAbout::~DialogAbout()
{
    delete ui;
}

void DialogAbout::initDialog()
{
    AppData* appData = AppData::GetInstance();
    setWindowTitle(appData->appName() +" - "+ AppText::title_about());
    setData();
}

void DialogAbout::setData()
{
    AppData* appData = AppData::GetInstance();
    ui->label_about->setText(AppText::title_about());
    ui->label_app_name->setText(appData->appName());
    ui->label_dev_info->setText(AppText::about_dev() +" "+ appData->appDev());
    ui->label_about_text->setText(AppText::about_framework());
    ui->label_logo->setPixmap(AppImage::logo128());
}
