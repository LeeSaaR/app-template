#ifndef PDFLETTERDATALOADER_H
#define PDFLETTERDATALOADER_H

#include "letterdata.h"

#include <QJsonObject>

class PdfLetterDataLoader
{
private:
    PdfLetterDataLoader();
public:
    static void loadConfig(const QString &letter_data_config_file, LetterData* letter);
    static void saveConfig(const QString &letter_data_config_file, LetterData* letter, const bool& isDefault = false);
    static bool toBool(QJsonValue val);
};

#endif // PDFLETTERDATALOADER_H
