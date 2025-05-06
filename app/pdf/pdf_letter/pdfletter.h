#ifndef PDFLETTER_H
#define PDFLETTER_H

#include "pdfletterbase.h"

class PdfLetter : public PdfLetterBase
{
public:
    PdfLetter(PdfWriter *pdfWriter) : PdfLetterBase(){};
    ~PdfLetter() override {};
    void generate() override;
    bool isValid() override;
};

#endif // PDFLETTER_H
