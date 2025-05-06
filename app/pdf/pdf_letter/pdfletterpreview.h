#ifndef PDFLETTERPREVIEW_H
#define PDFLETTERPREVIEW_H

#include "pdfletterbase.h"

class PdfLetterPreview : public PdfLetterBase
{
public:
    PdfLetterPreview(PdfWriter* pdfWriter) : PdfLetterBase(){};
    ~PdfLetterPreview(){};

public:
    void generate() override;

private:
    void testData();

protected:
    bool isValid() override;
};

#endif // PDFLETTERPREVIEW_H
