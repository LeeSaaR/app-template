#include "pdfbill.h"

#include <QDebug>
#include <QDate>

#include "billnumber.h"

void PdfBill::generate()
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
    drawTable();

    // END PAINTER
    PDF->painter.end();

    data = nullptr;
}

bool PdfBill::isValid()
{
    if (data == nullptr)
        return false;

    return true;
}

void PdfBill::drawInfo(int line_num)
{
    qDebug() << __FUNCTION__;
    // Info is the upper right information under the Logo
    PDF->setFont("default small", "black");

    SenderData* sen = data->sen;
    ReceiverData* rec = data->rec;
    ReceiverOptions* rec_opt = data->rec->opt;
    //int line_num = 1;

    infoYT = info_y_start + infoH * (line_num-1);
    infoYB = infoYT + infoH;
    PDF->drawText(x1Left, infoYT, x2Right, infoYB, sen->institution(), Qt::AlignLeft);
    line_num++;

    if (sen->hasEmail()){
        drawInfoLine(line_num, "Email:");
        drawInfoLine(line_num++, sen->email(), true);
    }
    if (sen->hasTelephone()){
        drawInfoLine(line_num, "Telefon:");
        drawInfoLine(line_num++, m_tel_symb+sen->telephone(), true);
    }
    if (sen->hasMobile()) {
        drawInfoLine(line_num, "Mobil:");
        drawInfoLine(line_num++, m_mob_symb+sen->mobile(), true);
    }

    if (sen->hasWebsite()){
        drawInfoLine(line_num, "Internet:");
        drawInfoLine(line_num++, sen->website(), true);
    }

    if (sen->hasVAT() && data->opt->useVAT())
    {
        drawInfoLine(line_num, "USt-ID-Nr.:");
        drawInfoLine(line_num++, sen->vat(), true);
        line_num++;
    }


    PDF->setFont("default small bold", "black");
    if (rec->hasAccount() && rec_opt->useAccount())
    {
        drawInfoLine(line_num, rec->accountName());
        drawInfoLine(line_num++, rec->account(), true);
    }

    if (rec->hasReference() && rec_opt->useReference())
    {
        drawInfoLine(line_num, rec->referenceName());
        //drawInfoLine(line_num++, rec->reference(), true);
        drawInfoLine(line_num++, data->rec->reference(), true);
    }

    PDF->setFont("default small", "black");
    drawInfoLine(12, "Datum");
    if (data->opt->useDate() && data->hasDate())
    {
        drawInfoLine(12, data->date(), true);
    }
    else
    {
        drawInfoLine(12, QDate::currentDate().toString("dd.MM.yyyy"), true);
    }

    int line = contact_start_line;
    if (data->opt->useContact() && data->sen->hasContact())
        drawContact(line);
}

void PdfBill::drawSubjectLine()
{
    PDF->setFont("default bold", "black", 11);
    PDF->drawTextBody(subject_y_start, subject_y_end, "Rechnung");
}

void PdfBill::drawTable()
{
    drawTableExample();
}

void PdfBill::drawTableExample()
{
    // THIS IS JUST AN EXAMPLE
    TableProp table_prop = TableProp();
    table_prop.add(100, Qt::AlignLeft);
    // table_prop.add(40, Qt::AlignLeft);
    PDF->initTable(table_prop);

    double table_position = 120.0;
    double section_offset = 12.0;
    PDF->setTableStartPosY(table_position);
    PDF->setLineHeight(45.0);

    PDF->drawTableLine("table thick");
    PDF->offsetPosY(8);
    drawBillData( data->rec->referenceName()+": "+data->rec->reference(), "Bestellungs-Nr: "+BillNumber::numberOrder(7) );
    PDF->offsetPosY(8);


    table_prop = TableProp();
    table_prop.add(8, Qt::AlignLeft);
    table_prop.add(18, Qt::AlignLeft);
    table_prop.add(60, Qt::AlignLeft);
    table_prop.add(10, Qt::AlignRight);
    table_prop.add(18, Qt::AlignRight);
    table_prop.add(18, Qt::AlignLeft);
    PDF->initTable(table_prop);

    // SECTION POINTS
    PDF->drawTableLine("table thick");
    PDF->offsetPosY(8);
    drawRowBold( "NR.", "ARTIKEL-NR", "ARTIKEL", "MENGE", "EINZELPREIS", "MWST", "SUMME" );
    PDF->offsetPosY(8);
    PDF->drawTableLine("table thick");
    PDF->offsetPosY(section_offset);
    // START POSITIONS ===================================
    drawRow("1", "102501-001", "Etwas Teures", "1", "30.000,00 €", "19%", "30.000,00 €");
    drawRow("2", "202502-001", "T-shirt", "2", "9,99 €", "19%", "19,98 €");
    // END POSITIONS =====================================
    PDF->offsetPosY(section_offset);
    PDF->drawTableLine("table thick");
    PDF->offsetPosY(8);
    drawRow( "", "", "", "", "", "Netto", "24.316,18 €" );
    drawRow( "", "", "", "", "", "MwSt.", "5.703,80 €" );
    drawRowBold( "", "", "", "", "", "Gesamt", "30.019,98 €" );
    PDF->offsetPosY(8);
    PDF->drawTableLine("table thick");

    PDF->offsetPosY(section_offset);
    PDF->setLineHeight(55.0);
    PDF->setFont("default", "default text");
    PDF->drawLine("Wir bitten, den Betrag innerhalb von 14 Tagen ab Erhalt dieser Rechnung");
    PDF->drawLine("an das folgende Konto zu überweisen:");
    PDF->setFont("default mono", "default text");
    PDF->newLine();
    PDF->drawLine("BANK   : "+data->sen->bank());
    PDF->drawLine("IBAN   : "+data->sen->iban());
    PDF->drawLine("ZWECK  : "+data->rec->reference());
    PDF->drawLine("BETRAG : 30.019,98 €");
}

void PdfBill::drawRow(
    const QString &position,
    const QString &number,
    const QString &name,
    const QString &amount,
    const QString &sum_single,
    const QString &tax,
    const QString &sum
    )
{
    // "POSITION", "ARTIKEL-NR", "ARTIKEL", "STK", "PREIS", "MWST", "SUMME (€)"
    PDF->setFont("table thin", "default text");
    PDF->drawTableColumn(0, position);
    PDF->drawTableColumn(1, number);
    PDF->drawTableColumn(2, name);
    PDF->drawTableColumn(3, amount);
    PDF->drawTableColumn(4, sum_single);
    PDF->drawTableColumn(5, tax);
    PDF->drawTableColumn(6, sum);
    PDF->newLine();
}
void PdfBill::drawRowBold(
    const QString &position,
    const QString &number,
    const QString &name,
    const QString &amount,
    const QString &sum_single,
    const QString &tax,
    const QString &sum
    )
{
    PDF->setFont("table thin bold", "default text");
    PDF->drawTableColumn(0, position);
    PDF->drawTableColumn(1, number);
    PDF->drawTableColumn(2, name);
    PDF->drawTableColumn(3, amount);
    PDF->drawTableColumn(4, sum_single);
    PDF->drawTableColumn(5, tax);
    PDF->drawTableColumn(6, sum);
    PDF->newLine();
}

void PdfBill::drawBillData(const QString &bill_number, const QString &order_number)
{
    PDF->setFont("table thin bold", "default text");
    PDF->drawTableColumn(0, bill_number);
    PDF->drawTableColumn(1, order_number);
    PDF->newLine();
}
