#ifndef PDFLETTERBASE_H
#define PDFLETTERBASE_H

#include "pdfwriter.h"

#include "letterdata.h"

class PdfLetterBase
{
protected:
    PdfWriter* PDF = nullptr;

    const QMap<QString,QString> m_direct_title = {
        {"Herr", "Herrn"},
        {"Frau", "Frau"},
        {"", ""}
    };

    const QMap<QString,QString> m_contact_type = {
        {"male", "Ansprechpartner"},
        {"female", "Ansprechpartnerin"},
        {"enby", "Ansprechperson"},
        {"", "Ansprechperson"}
    };

    const QString m_tel_symb = "☏ ";
    const QString m_mob_symb = "✆ ";
    const QString m_sender_delimiter = " • ";

    const QString m_on_behalf              = "i.A.";
    const QString m_abbreviation_direct    = "z.H.";
    const QString m_abbreviation_represent = "o.V.i.A.";
    const QString m_confidential           = "– vertraulich –";

protected:
    // Data
    LetterData *data = nullptr;

protected:
    const double sender_y_start   =  47;
    const double sender_y_end     =  55;

    const double receiver_y_start =  62;

    const double info_y_start     =  50;
    const double info_x_start     = 125;
    const double info_x_end       = 200;
    const double infoH    = 4;
    const double x1Left   = info_x_start;
    const double x2Right  = info_x_end;
    const double x2Left   = x1Left+((info_x_end - info_x_start) * 0.5)-10;
    const double x1Right  = x2Right-((info_x_end - info_x_start) * 0.5)-5;
    double infoYT   = info_y_start;
    double infoYB   = infoYT + infoH;

    int contact_start_line = 1;

    const double subject_y_start  = 105;
    const double subject_y_end    = 114;

    const double body_y_start     = 120;
    const double body_y_end       = 260;


    const double footer_y_start = 272;
    const double footer_y_text = footer_y_start+2;

    const double footer_left   = 25;
    const double footer_right  = 190;

    const double footc1Xs = footer_left;
    const double footc1Xe = ((footer_right - footer_left) * 0.33333) + footer_left - 5;

    const double footc2Xs = ((footer_right - footer_left) * 0.33333) + footer_left+8;
    const double footc2Xe = ((footer_right - footer_left) * 0.33333)*2 + footer_left - 5;

    const double footc3Xs = ((footer_right - footer_left) * 0.33333)*2 + footer_left+14;
    const double footc3Xe = footer_right;
    const double footerH  = 4;

    const double pageNumYs = 265.5;
    const double pageNumYe = 269;
    const double pageNumXs = footer_right-30;
    const double pageNumXe = footer_right;

    double footYT = footer_y_start;
    double footYB = footYT + 4;

    int m_column_1  = 1;
    int m_column_2  = 2;
    int m_column_3  = 3;

protected:
    explicit PdfLetterBase();
    virtual ~PdfLetterBase();

protected:
    virtual bool isValid() {return false;};

public:
    virtual void generate() {};
    void setData(LetterData *data){this->data = data;}
    LetterData* letter_data(){return this->data;}
    void resetData();

protected:
    void setPdfWriter(PdfWriter *pdfWriter);

protected:
    // DRAW
    void drawSender();
    void drawReceiver();
    void receiverLinesPrivate(QStringList &lines);
    void receiverLinesInstitution(QStringList &lines);
    void receiverLinesDirect(QStringList &lines);
    virtual void drawSubjectLine();
    void drawPageContent(const int &html_page_index, const int &html_page_number);
    void drawMarks();
    void drawLogo();
    void drawBackground();
    void drawInfoLine(
        const int &line,
        const QString &text,
        const bool &drawRight = false,
        Qt::AlignmentFlag options = Qt::AlignLeft);
    //virtual void drawInfo();
    virtual void drawInfo(int line_num = 6);
    void drawContact(int &line);
    void drawFooterLine(
        const int &line,
        const int &column,
        const QString &text,
        double offset = 0);
    void drawFooter();
    void drawFooterDefault();
    void drawFooterHorizontal();
    void drawPageNumber(int pageN);
};

#endif // PDFLETTERBASE_H
