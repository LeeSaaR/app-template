#include "pdfpreviewletteroptionfactory.h"

PdfPreviewLetterOptionFactory::PdfPreviewLetterOptionFactory() {}

QWidget *PdfPreviewLetterOptionFactory::optionSimple(const QString &name, const bool& enable, QWidget* parent)
{
    QPushButton *btn = new QPushButton(parent);
    btn->setText(name);
    btn->setChecked(enable);
    return new QWidget(parent);
}
