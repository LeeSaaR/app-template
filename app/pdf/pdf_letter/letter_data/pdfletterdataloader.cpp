#include "pdfletterdataloader.h"

#include "appio.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

void PdfLetterDataLoader::loadConfig(const QString& letter_data_config_file, LetterData *letter)
{
    qDebug() << __FUNCTION__;
    QJsonDocument jsonDoc = AppIO::loadJsonFile(letter_data_config_file);
    QJsonObject objMain = jsonDoc.object();

    letter->sen->isPrivate( objMain["isPrivate"].toBool() );
    letter->logoFile( objMain["fileLogo"].toString() );
    letter->backgroundFile( objMain["fileBackground"].toString() );
    letter->opt->useAbbreviation( objMain["useAbbreviation"].toBool() );
    letter->opt->useBackground( objMain["useBackground"].toBool() );
    letter->opt->useBank( objMain["useBank"].toBool() );
    letter->opt->useContact( objMain["useContact"].toBool() );
    letter->opt->useEmail( objMain["useEmail"].toBool() );
    letter->opt->useFooter( objMain["useFooter"].toBool() );
    letter->opt->useHorizontal( objMain["useHorizontal"].toBool() );
    letter->opt->useLogo( objMain["useLogo"].toBool() );
    letter->opt->useMobile( objMain["useMobile"].toBool() );
    letter->opt->useTelephone( objMain["useTelephone"].toBool() );
    letter->opt->useWebsite( objMain["useWebsite"].toBool() );
}

void PdfLetterDataLoader::saveConfig(const QString &letter_data_config_file, LetterData *letter, const bool& isDefault)
{
    QJsonObject objMain;

    objMain["isDefault"]       = isDefault;
    objMain["isPrivate"]       = letter->sen->isPrivate();
    objMain["fileLogo"]        = letter->logoFile();
    objMain["fileBackground"]  = letter->backgroundFile();
    objMain["useAbbreviation"] = letter->opt->useAbbreviation();
    objMain["useBank"]         = letter->opt->useBank();
    objMain["useBackground"]   = letter->opt->useBackground();
    objMain["useContact"]      = letter->opt->useContact();
    objMain["useEmail"]        = letter->opt->useEmail();
    objMain["useFooter"]       = letter->opt->useFooter();
    objMain["useHorizontal"]   = letter->opt->useHorizontal();
    objMain["useLogo"]         = letter->opt->useLogo();
    objMain["useMobile"]       = letter->opt->useMobile();
    objMain["useTelephone"]    = letter->opt->useTelephone();
    objMain["useWebsite"]      = letter->opt->useWebsite();

    QJsonDocument jsonDoc;
    jsonDoc.setObject(objMain);
    AppIO::saveJsonFile(letter_data_config_file, jsonDoc);
}

bool PdfLetterDataLoader::toBool(QJsonValue val)
{
    return QVariant(val.toString()).toBool();
}
