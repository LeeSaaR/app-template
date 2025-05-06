#include "wgtpdfpreviewdropdownfile.h"
#include "ui_wgtpdfpreviewdropdownfile.h"

WgtPdfPreviewDropDownFile::WgtPdfPreviewDropDownFile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WgtPdfPreviewDropDownFile)
{
    ui->setupUi(this);
}

WgtPdfPreviewDropDownFile::~WgtPdfPreviewDropDownFile()
{
    delete ui;
}

QString WgtPdfPreviewDropDownFile::value() const
{
    return ui->comboBox->currentData().toString();
}

void WgtPdfPreviewDropDownFile::setValue(const QString &value)
{

}

void WgtPdfPreviewDropDownFile::onActivated()
{

}
