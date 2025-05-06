#include "pdfletterpreview.h"

#include "appdata.h"
#include "appwindow.h"
#include <QTextEdit>

void PdfLetterPreview::generate()
{
    // DO CHECKS, IF DATA IS AVAILABLE
    if (!isValid()) return;
    testData();


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
}

void PdfLetterPreview::testData()
{
    if (!data->sen->nameFirst().isEmpty()) return; // skip if data allready set

    QTextEdit* te = new QTextEdit(AppWindow::get());
    te->setHtml(
        "Lorem ipsum dolor sit amet, <b>consetetur</b> sadipscing elitr, "
        "sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, "
        "sed diam voluptua.<br><br>At vero eos et accusam et justo duo dolores et ea rebum."
        "<br><br>Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. "
        "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor "
        "invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua.<br><br>At vero eos et "
        "accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus "
        "est Lorem ipsum dolor sit amet.");
    QStringList m_pages = {te->toHtml()};
    delete te;

    AppData * appData = AppData::GetInstance();
    const QString preview_file = appData->dir_temp()+"/test_preview.pdf";

    data->initDocument( preview_file, "Preview" );
    data->sen->institution("Deine Firma GmbH");
    data->sen->gender("female");
    data->sen->title("Frau");
    data->sen->nameFirst("Kim");
    data->sen->nameLast("Mustermann");
    data->sen->address1("Sonntagsstraße 1");
    data->sen->address2("54321 Städtchen");
    data->sen->website("www.deine-webseite.de");
    data->sen->email("info@deine-webseite.de");
    data->sen->mobile("+49 123 00 11 22 33");
    data->sen->telephone("+49 1234 22 00 11");

    data->sen->bank("Test Bank");
    data->sen->iban("DE00 0000 0000 0000 0000 00");
    data->sen->bic("ADHAIEOAD");
    data->sen->contact->setData(
        "",
        "",
        "Frau Müller",
        "müller@müllers.de",
        "+49 1234 000 00 - 1",
        "");

    data->sen->vat("987654129");

    data->rec->isPrivate(true);
    data->rec->opt->useAccount(true);
    data->rec->account("Kunden-Nr.", "718 541 678");

    data->rec->opt->useReference(true);
    data->rec->reference("Vertrags-Nr.", "B25-035-C15");

    // INSTITUTION DATA
    data->rec->institution("Eine Firma GmbH");
    data->rec->opt->useDirect(true);
    data->rec->opt->useDepartment(true);
    data->rec->department("Personalabteilung");
    data->rec->opt->useRepresentative(true);
    data->rec->direct("Mark Mayer");

    // PRIVATE DATA
    data->rec->nameFirst("Max");
    data->rec->nameLast("Schmidt");
    data->rec->address("An der Teststraße 15", "12345 Testdorf");

    data->subject("Betreffzeile Teil 1\nBetreffzeile Teil 2");
    data->htmlPages(m_pages);
}

bool PdfLetterPreview::isValid()
{
    if (data == nullptr)
        return false;
    return true;
}
