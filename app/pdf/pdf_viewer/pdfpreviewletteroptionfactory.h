#ifndef PDFPREVIEWLETTEROPTIONFACTORY_H
#define PDFPREVIEWLETTEROPTIONFACTORY_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QList>

class PdfPreviewLetterOptionFactory
{

public:
    PdfPreviewLetterOptionFactory();
    QWidget* optionSimple(const QString &name, const bool& enable, QWidget* parent = nullptr);
};

#endif // PDFPREVIEWLETTEROPTIONFACTORY_H
