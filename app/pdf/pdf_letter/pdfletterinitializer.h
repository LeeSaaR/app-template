#ifndef PDFLETTERINITIALIZER_H
#define PDFLETTERINITIALIZER_H

class PdfLetterInitializer
{
private:
    PdfLetterInitializer(){}
public:
    static void init();
    static void createAppDataDirs();
    static void createDefaultLetterDataOptions();
};

#endif // PDFLETTERINITIALIZER_H
