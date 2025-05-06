#include "wgtpdfpreviewfileselect.h"
#include "appstates.h"
#include "ui_wgtpdfpreviewfileselect.h"

#include "appdata.h"
#include <QDir>
#include <QFileDialog>

WgtPdfPreviewFileSelect::WgtPdfPreviewFileSelect(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WgtPdfPreviewFileSelect)
{
    ui->setupUi(this);
    connect(ui->btn, &QPushButton::clicked, this, &WgtPdfPreviewFileSelect::onClickedButton);
}

WgtPdfPreviewFileSelect::~WgtPdfPreviewFileSelect()
{
    delete ui;
}

QString WgtPdfPreviewFileSelect::filePath() const
{
    return m_value;
}

void WgtPdfPreviewFileSelect::onClickedButton()
{
    AppData * appData = AppData::GetInstance();

    const QString file_name = QFileDialog::getOpenFileName(this, appData->appName()+" - "+m_default_text, m_default_path, "*.png");
    if (!file_name.isEmpty()) {
        selected_file = file_name;
        emit selectedFile();
    }
}

void WgtPdfPreviewFileSelect::setText(const QString &file_path)
{
    QFileInfo file_info(file_path);
    ui->btn->setText(file_info.fileName());
}

void WgtPdfPreviewFileSelect::setValue(const QString &file_path)
{
    m_value = file_path;
    setText(file_path);
}

void WgtPdfPreviewFileSelect::setDefaultPath(const QString &path)
{
    m_default_path = path;
}

void WgtPdfPreviewFileSelect::setDefaultText(const QString &text)
{
    m_default_text = text;
}

void WgtPdfPreviewFileSelect::setTooltipText(const QString &text)
{
    ui->btn->setToolTipDuration(5000);
    ui->btn->setToolTip(text);
}

