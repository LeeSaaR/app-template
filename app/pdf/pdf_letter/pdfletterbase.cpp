#include "pdfletterbase.h"

#include <QDebug>
#include <QDate>
#include <QStaticText>
#include "pdfdata.h"

PdfLetterBase::PdfLetterBase()
    : PDF(new PdfWriter())
{
    qDebug() << __FUNCTION__;
}

PdfLetterBase::~PdfLetterBase()
{
    qDebug() << __FUNCTION__;
    if (PDF != nullptr)
        delete PDF;
    data = nullptr;
}

// METHODS

void PdfLetterBase::resetData()
{
    qDebug() << __FUNCTION__;
    data = nullptr;
}

// DRAW
void PdfLetterBase::drawSender()
{
    qDebug() << __FUNCTION__;
    PDF->setFont("default tiny", "black");
    QStringList sender_line;
    if (data->sen->isPrivate())
    {
        sender_line.append(data->sen->name(CommonLetterData::Full));
    }
    else
    {
        sender_line.append(data->sen->institution());
    }

    sender_line.append(data->sen->address1());
    sender_line.append(data->sen->address2());

    PDF->drawTextBody(sender_y_start, sender_y_end, sender_line.join(m_sender_delimiter));
}

void PdfLetterBase::drawReceiver()
{
    qDebug() << __FUNCTION__;

    QStringList lines;

    if (data->rec->isPrivate())
    {
        receiverLinesPrivate(lines);
    }
    else
    {
        receiverLinesInstitution(lines);
    }

    lines.append(data->rec->address1());
    lines.append(data->rec->address2());

    // Draw
    PDF->setFont("default", "black", 10);
    double line_height  = 4;
    double y_start = receiver_y_start;
    double y_end   = y_start + line_height;

    for (const QString & line : std::as_const(lines))
    {
        PDF->drawTextBody(y_start, y_end, line);
        y_start    = y_end;
        y_end     += line_height;
    }
}

void PdfLetterBase::receiverLinesPrivate(QStringList &lines)
{
    ReceiverData* rec = data->rec;
    ReceiverOptions* rec_opt = data->rec->opt;
    if (rec_opt->useTitle() && rec->hasTitle())
    {
        /* CASE 1:
         * L1: title academic_title
         * L2: name_first name_last
         */
        QStringList title_line;
        title_line.append(rec->title());
        if (rec->hasTitleAcademic())
            title_line.append(rec->titleAcademic());
        lines.append(title_line.join(" "));
    }
    else
    {
        /* CASE 2:
         * L1:
         * L2: name_first name_last
         */
        lines.append("");
    }

    lines.append(rec->name(CommonLetterData::Full));
}

void PdfLetterBase::receiverLinesInstitution(QStringList &lines)
{
    ReceiverData* rec = data->rec;
    ReceiverOptions* rec_opt = data->rec->opt;
    if (!rec_opt->useDepartment()
        && !rec_opt->useConfidential()
        && !rec_opt->useDirect())
    {
        /* CASE 1:
             * L1:
             * L2: institution_name
             * L3: address_1
             * L4: address_2
             */
        lines.append("");
        lines.append(rec->institution());
    }
    else
    {
        /*
         * Case 2a:
         * L1: institution_name
         * L2: - confidential -
         * L3: address1
         * L4: address2
         *
         * Case 2a:
         * L1: institution_name
         * L2: - confidential -
         * L3: department and/or direct
         * L4: address1
         * L5: address2
         *
         * Case 2b
         * L1: institution_name
         * L2: department and/or direct
         * L3: address1
         * L4: address2
         */
        // L1: insitution
        lines.append(rec->institution());

        // L2: - CONFIDENTIAL - optional
        if (rec_opt->useConfidential())
            lines.append(m_confidential);

        // L2 or L3: department
        receiverLinesDirect(lines);
    }
}

void PdfLetterBase::receiverLinesDirect(QStringList &lines)
{
    // if confidential, then L3
    // if not confidential, then L2
    ReceiverData* rec = data->rec;
    ReceiverOptions* rec_opt = data->rec->opt;

    QStringList dep_line;
    const bool uses_department = rec_opt->useDepartment() && rec->hasDepartment();
    const bool uses_direct = rec_opt->useDirect() && rec->hasDirect();

    if(uses_department)
        dep_line.append(rec->department());

    if (uses_direct)
    {
        if (uses_department)
            dep_line.last().append(',');

        dep_line.append(m_abbreviation_direct);
        dep_line.append(rec->direct());

        if (rec_opt->useRepresentative())
            dep_line.append(m_abbreviation_represent);
    }
    lines.append(dep_line.join(" "));
}

void PdfLetterBase::drawSubjectLine()
{
    qDebug() << __FUNCTION__;
    PDF->setFont("default bold", "black", 11);
    PDF->drawTextBody(subject_y_start, subject_y_end, data->subject());
}

void PdfLetterBase::drawPageContent(const int &html_page_index, const int &html_page_number)
{
    PDF->setFont("default", "black", 11);
    if (html_page_index < 1) {
        PDF->drawHtmlBody(data->htmlPages().at(html_page_index), 120);
    }
    else {
        PDF->addPage();
        if (data->opt->useBackground() && data->hasBackground())
            PDF->drawImage(32.239, 74.057,QImage(data->backgroundFile()));

        drawPageNumber(html_page_number);
        drawFooter();
        PDF->drawHtmlBody(data->htmlPages().at(html_page_index), 25);
    }
}

void PdfLetterBase::drawMarks()
{
    qDebug() << __FUNCTION__;
    PDF->setPen("marks");

    double s  = 3.5;
    double l1 = 4;
    double l2 = 6;
    double h1 = 105;
    double h2 = 297-105;
    double h3 = 297*0.5;

    PDF->drawLine(s, h1, s+l1,  h1);
    PDF->drawLine(s, h2, s+l1,  h2);
    PDF->drawLine(s, h3, s+l2, h3);
}

void PdfLetterBase::drawLogo()
{
    qDebug() << __FUNCTION__;
    // logo must have 3:2 ratio and be a png with transparent background
    // optimal size: 900x600 px 96 dpi
    if (data->opt->useLogo() && data->hasLogo()) {
        QString file_path = data->logoFile();
        if (file_path.at(0) != ":")
            file_path.prepend(PdfData::dirLogo()+"/");

        //PDF->drawLogo(125,0,QImage(data->logoFile()));
        PDF->drawLogo(125,0,QImage(file_path));
    }
}

void PdfLetterBase::drawBackground()
{
    // background image must have A4 format (about 3:4) and be a png with transparent background
    // optimal size: 2480x3508 px 300 dpi
    if (data->opt->useBackground() && data->hasBackground()){
        QString file_path = data->backgroundFile();
        if (file_path.at(0) != ":")
            file_path.prepend(PdfData::dirBackground()+"/");
        //PDF->drawBackground(0, 0,QImage(data->backgroundFile()));
        PDF->drawBackground(0, 0,QImage(file_path));
    }
}

void PdfLetterBase::drawInfoLine(const int &line, const QString &text, const bool &drawRight, Qt::AlignmentFlag options)
{
    qDebug() << __FUNCTION__;
    infoYT = info_y_start + infoH * (line-1);
    infoYB = infoYT + infoH;
    if (drawRight)
    {
        PDF->drawText(x1Right, infoYT, x2Right, infoYB, text, options);
    }
    else {
        PDF->drawText(x1Left, infoYT, x2Left, infoYB, text, options);
    }

}

/*void PdfLetterBase::drawInfo()
{
    qDebug() << __FUNCTION__;
    // Info is the upper right information under the Logo
    PDF->setFont("default small", "black");

    SenderData* sen = data->sen;
    ReceiverData* rec = data->rec;
    ReceiverOptions* rec_opt = data->rec->opt;
    int line_num = 6;

    if (sen->hasVAT() && data->opt->useVAT())
    {
        drawInfoLine(line_num, "USt-ID-Nr.:");
        drawInfoLine(line_num++, sen->vat(), true);
        line_num++;
    }

    if (rec->hasAccount() && rec_opt->useAccount())
    {
        drawInfoLine(line_num, rec->accountName());
        drawInfoLine(line_num++, rec->account(), true);
    }

    if (rec->hasReference() && rec_opt->useReference())
    {
        drawInfoLine(line_num, rec->referenceName());
        drawInfoLine(line_num++, rec->reference(), true);
    }

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

}*/

void PdfLetterBase::drawInfo(int line_num)
{
    qDebug() << __FUNCTION__;
    // Info is the upper right information under the Logo
    PDF->setFont("default small", "black");

    SenderData* sen = data->sen;
    ReceiverData* rec = data->rec;
    ReceiverOptions* rec_opt = data->rec->opt;

    if (sen->hasVAT() && data->opt->useVAT())
    {
        drawInfoLine(line_num, "USt-ID-Nr.:");
        drawInfoLine(line_num++, sen->vat(), true);
        line_num++;
    }

    if (rec->hasAccount() && rec_opt->useAccount())
    {
        drawInfoLine(line_num, rec->accountName());
        drawInfoLine(line_num++, rec->account(), true);
    }

    if (rec->hasReference() && rec_opt->useReference())
    {
        drawInfoLine(line_num, rec->referenceName());
        drawInfoLine(line_num++, rec->reference(), true);
    }

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

void PdfLetterBase::drawContact(int &line)
{
    qDebug() << __FUNCTION__;
    ContactData * contact = data->sen->contact;
    drawInfoLine(line, m_contact_type[contact->gender()]);
    QStringList name_list;
    if (contact->hasTitle()) name_list.append(contact->title());
    name_list.append(contact->name());
    drawInfoLine(line++, name_list.join(" "), true);
    if (contact->hasTelephone())
        drawInfoLine(line++, m_tel_symb+contact->telephone(), true);

    if (contact->hasMobile())
        drawInfoLine(line++, m_mob_symb+contact->mobile(), true);

    if (contact->hasEmail())
        drawInfoLine(line++, contact->email(), true);
}

void PdfLetterBase::drawFooterLine(const int &line, const int &column, const QString &text, double offset)
{
    qDebug() << __FUNCTION__;
    footYT = footer_y_text + footerH * (line-1);
    footYB = footYT + footerH;
    switch (column) {
    case 1:
        PDF->drawText(footc1Xs + offset, footYT, footc1Xe, footYB, text);
        break;
    case 2:
        PDF->drawText(footc2Xs + offset, footYT, footc2Xe, footYB, text);
        break;
    case 3:
        PDF->drawText(footc3Xs + offset, footYT, footc3Xe, footYB, text);
        break;
    default:
        break;
    }
}

void PdfLetterBase::drawFooter()
{
    qDebug() << __FUNCTION__;
    PDF->setPen("footer");
    PDF->drawLine(footer_left, footer_y_start, footer_right,  footer_y_start);
    if (!data->opt->useFooter()) return;

    PDF->setFont("default footer", "black");

    if (data->opt->useHorizontal()) {
        drawFooterHorizontal();
    }
    else {
        drawFooterDefault();
    }

}

void PdfLetterBase::drawFooterDefault()
{
    qDebug() << __FUNCTION__;

    {
        int line = 1;
        if (data->sen->isPrivate())
        {
            CommonLetterData::Name type =
                (data->opt->useAbbreviation()) ? CommonLetterData::Abbreviation : CommonLetterData::Full;
            drawFooterLine(line++, m_column_1, data->sen->name(type));
        }
        else
        {
            drawFooterLine(line++, m_column_1, data->sen->institution());
        }
        drawFooterLine(line++, m_column_1, data->sen->address1());
        drawFooterLine(line++, m_column_1, data->sen->address2());
    }

    {
        int line = 1;
        if (data->opt->useWebsite() && data->sen->hasWebsite())
            drawFooterLine(line++, m_column_2, data->sen->website());
        if (data->opt->useEmail() && data->sen->hasEmail())
            drawFooterLine(line++, m_column_2, data->sen->email());
        if (data->opt->useTelephone() && data->sen->hasTelephone())
            drawFooterLine(line++, m_column_2, m_tel_symb+data->sen->telephone());
        if (data->opt->useMobile() && data->sen->hasMobile())
            drawFooterLine(line++, m_column_2, m_mob_symb+data->sen->mobile());
    }

    if (data->opt->useBank() && data->sen->hasBankData()) {
        int line = 1;
        if (data->sen->hasBankAccount())
            drawFooterLine(line++, m_column_3, data->sen->bankAccount());
        if (data->sen->hasBank())
            drawFooterLine(line++, m_column_3, data->sen->bank());
        drawFooterLine(line++, m_column_3, data->sen->iban());
        if (data->sen->hasBIC())
            drawFooterLine(line++, m_column_3, data->sen->bic());
    }
}

void PdfLetterBase::drawFooterHorizontal()
{
    qDebug() << __FUNCTION__;
    QStringList text_list;
    if (data->sen->isPrivate())
    {
        CommonLetterData::Name type =
            (data->opt->useAbbreviation()) ? CommonLetterData::Abbreviation : CommonLetterData::Full;
        text_list.append(data->sen->name(type)+"    |");
    }
    else
    {
        text_list.append(data->sen->institution()+"    |");
    }

    text_list.append(data->sen->address1()+"    |");
    text_list.append(data->sen->address2());

    footYT = footer_y_text;
    footYB = footYT + footerH;
    PDF->drawText(footc1Xs, footYT, footc3Xe, footYB, text_list.join("    "), Qt::AlignCenter);

    text_list.clear();
    if (data->opt->useWebsite() && data->sen->hasWebsite())
        text_list.append(data->sen->website());
    if (data->opt->useEmail() && data->sen->hasEmail())
        text_list.append(data->sen->email());
    if (data->opt->useTelephone() && data->sen->hasTelephone())
        text_list.append(m_tel_symb+data->sen->telephone());
    if (data->opt->useMobile() && data->sen->hasMobile())
        text_list.append(m_mob_symb+data->sen->mobile());

    if (!text_list.isEmpty())
    {
        footYT = footYB;
        footYB = footYT + footerH;
        PDF->drawText(footc1Xs, footYT, footc3Xe, footYB, text_list.join("    |    "), Qt::AlignCenter);
    }


    if (data->opt->useBank() && data->sen->hasBankData())
    {
        text_list.clear();

        if (data->sen->hasBankAccount())
            text_list.append(data->sen->bankAccount());
        if (data->sen->hasBank())
            text_list.append(data->sen->bank());
        text_list.append(data->sen->iban());
        if (data->sen->hasBIC())
            text_list.append(data->sen->bic());

        if (!text_list.isEmpty()) {
            footYT = footYB;
            footYB = footYT + footerH;
            PDF->drawText(footc1Xs, footYT, footc3Xe, footYB, text_list.join("    |    "), Qt::AlignCenter);
        }
    }
}

void PdfLetterBase::drawPageNumber(int pageN)
{
    PDF->setFont("default footer", "black");
    const QString text = "Seite "+ QString::number(pageN) + " von "+QString::number(data->pageCount());
    PDF->drawText(pageNumXs, pageNumYs, pageNumXe, pageNumYe, text, Qt::AlignRight);
}





