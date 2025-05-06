#include "pdfletter.h"

#include <QDebug>

void PdfLetter::generate()
{
    qDebug() << __FUNCTION__;
    // DO CHECKS, IF DATA IS AVAILABLE
    if (!isValid()) return;

    // INIT DOCUMENT
    PDF->setFileName(data->fileName());
    PDF->setDocumentName(data->docName());

    // START PAINTER
    PDF->paintBegin();

    // STATIC ELEMENTS
    drawBackground();
    drawLogo();
    drawMarks();
    drawPageNumber(1);
    drawFooter();

    // DYNAMIC ELEMENTS
    drawSender();
    drawReceiver();
    drawInfo();

    // ACTUAL CONTENT
    drawSubjectLine();
    for (int i = 0; i < data->pageCount(); i++)
    {
        const int html_page_index = i;
        const int html_page_number = i+1;
        drawPageContent(html_page_index, html_page_number);
    }

    // END PAINTER
    PDF->painter.end();
    data = nullptr;
}

bool PdfLetter::isValid()
{
    if (data == nullptr)
        return false;

    if (data->pageCount() == 0)
        return false;
    return true;
}

