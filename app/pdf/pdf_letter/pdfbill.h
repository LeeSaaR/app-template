#ifndef PDFBILL_H
#define PDFBILL_H

#include "pdfletterbase.h"

class PdfBill : public PdfLetterBase
{
public:
    PdfBill(PdfWriter *pdfWriter) : PdfLetterBase(){};
    ~PdfBill() override {};
    void generate() override;

private:
    bool isValid() override;
    void drawInfo(int line_num = 1) override;
    void drawSubjectLine() override;
    void drawTable();
    void drawTableExample();
    void drawRow(
        const QString &position,
        const QString &number,
        const QString &name,
        const QString &amount,
        const QString &sum_single,
        const QString &tax,
        const QString &sum);
    void drawRowBold(
        const QString &position,
        const QString &number,
        const QString &name,
        const QString &amount,
        const QString &sum_single,
        const QString &tax,
        const QString &sum);

    void drawBillData(
        const QString &bill_number,
        const QString &order_number);
};

#endif // PDFBILL_H
