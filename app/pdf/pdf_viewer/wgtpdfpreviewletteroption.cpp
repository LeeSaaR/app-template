#include "wgtpdfpreviewletteroption.h"
#include "ui_wgtpdfpreviewletteroption.h"

#include <QDebug>

WgtPdfPreviewLetterOption::WgtPdfPreviewLetterOption(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WgtPdfPreviewLetterOption)
{
    ui->setupUi(this);
    ui->btn->setCheckable(true);
    connect(ui->btn, &QPushButton::clicked, this, [this](){emit clickedOption();});
}

WgtPdfPreviewLetterOption::~WgtPdfPreviewLetterOption()
{
    delete ui;
}

void WgtPdfPreviewLetterOption::init(const QString &name, const bool &enable)
{
    this->name = name;
    ui->btn->setText(name);
    ui->btn->setChecked(enable);
}

const bool WgtPdfPreviewLetterOption::isChecked() const
{
    return ui->btn->isChecked();
}

void WgtPdfPreviewLetterOption::setChecked(const bool &check)
{
    ui->btn->setChecked(check);
}
