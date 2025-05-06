#include "pdfletterinitializer.h"

#include "appdata.h"
#include "appio.h"
#include "letterdata.h"
#include "pdfletterdataloader.h"
#include "pdfdata.h"

void PdfLetterInitializer::init()
{
    createAppDataDirs();
    createDefaultLetterDataOptions();
}

void PdfLetterInitializer::createAppDataDirs()
{
    AppData* appData = AppData::GetInstance();
    const QString &pdf_dir = appData->dir_app_data()+"/pdf";
    const QString &pdf_templates = pdf_dir+"/templates";
    const QString &pdf_letter = pdf_templates+"/letter";
    const QString &pdf_images = pdf_dir+"/image";
    const QString &pdf_logos = pdf_images+"/logo";
    const QString &pdf_backgrounds = pdf_images+"/background";

    AppIO::makeDir(pdf_dir);
    AppIO::makeDir(pdf_templates);
    AppIO::makeDir(pdf_letter);
    AppIO::makeDir(pdf_images);
    AppIO::makeDir(pdf_logos);
    AppIO::makeDir(pdf_backgrounds);

    PdfData::setDirLogo(pdf_logos);
    PdfData::setDirBackground(pdf_backgrounds);
    PdfData::setDirTemplates(pdf_letter);
    PdfData::setTemplateInstitute(PdfData::dirTemplates()+"/letter_options_institute.json");
    PdfData::setTemplatePrivate(PdfData::dirTemplates()+"/letter_options_private.json");
}

void PdfLetterInitializer::createDefaultLetterDataOptions()
{
    // Create File Names
    LetterData * data = new LetterData();

    // Private
    const QString default_private = PdfData::templatePrivate();
    if (!AppIO::fileExists(default_private)){
        data->sen->isPrivate(true);
        data->opt->useBackground(true);
        data->opt->useLogo(true);
        data->opt->useContact(false);
        data->opt->useFooter(true);
        data->opt->useHorizontal(true);
        data->opt->useAbbreviation(false);
        data->opt->useWebsite(false);
        data->opt->useEmail(true);
        data->opt->useTelephone(true);
        data->opt->useMobile(true);
        data->opt->useBank(false);
        data->opt->useVAT(false);
        PdfLetterDataLoader::saveConfig(default_private, data, true);
    }

    // Institute
    const QString default_institute = PdfData::templateInstitute();
    if (!AppIO::fileExists(default_institute)){
        data->sen->isPrivate(false);
        data->opt->useBackground(true);
        data->opt->useLogo(true);
        data->opt->useContact(true);
        data->opt->useFooter(true);
        data->opt->useHorizontal(false);
        data->opt->useAbbreviation(false);
        data->opt->useWebsite(true);
        data->opt->useEmail(true);
        data->opt->useTelephone(true);
        data->opt->useMobile(false);
        data->opt->useBank(true);
        data->opt->useVAT(false);
        PdfLetterDataLoader::saveConfig(default_institute, data, true);
    }

    // Free Memory
    delete data;
}
