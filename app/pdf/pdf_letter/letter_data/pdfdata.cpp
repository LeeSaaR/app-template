#include "pdfdata.h"


QString PdfData::m_dir_background = "";
QString PdfData::m_dir_logo = "";
QString PdfData::m_dir_pdf = "";
QString PdfData::m_dir_templates = "";

QString PdfData::m_template_institute = "";
QString PdfData::m_template_private = "";
QString PdfData::m_template_current = "";

QRegularExpression PdfData::rx;

QString PdfData::dirBackground()
{
    return  m_dir_background;
}

QString PdfData::dirLogo()
{
    return  m_dir_logo;
}

QString PdfData::dirPdf()
{
    return m_dir_pdf;
}

QString PdfData::dirTemplates()
{
    return m_dir_templates;
}

QString PdfData::templateInstitute()
{
    return m_template_institute;
}

QString PdfData::templatePrivate()
{
    return m_template_private;
}

QString PdfData::templateCurrent()
{
    return m_template_current;
}

void PdfData::setDirBackground(const QString &dir)
{
    m_dir_background = dir;
}

void PdfData::setDirLogo(const QString &dir)
{
    m_dir_logo = dir;
}

void PdfData::setDirPdf(const QString &dir)
{
    m_dir_pdf = dir;
}

void PdfData::setDirTemplates(const QString &dir)
{
    m_dir_templates = dir;
}

void PdfData::setTemplateInstitute(const QString &file)
{
    m_template_institute = file;
}

void PdfData::setTemplatePrivate(const QString &file)
{
    m_template_private = file;
}

void PdfData::setTemplateCurrent(const QString &file)
{
    m_template_current = file;
}

bool PdfData::validateFileName(QString &new_name, QString &file_name, QString &new_template_file)
{
    if (file_name.isEmpty()) return false;
    rx.setPattern("[/?!.,_:!§$%&{\\}\\]\\[()]");
    file_name.replace(rx, "");
    file_name.replace("\\", "");

    if (file_name.isEmpty()) return false;

    // prepare file name
    new_name = file_name;
    file_name.replace(" ", "_");
    file_name.append(".json");
    new_template_file = dirTemplates()+"/"+file_name;
    return true;
}
