#ifndef PDFDATA_H
#define PDFDATA_H

#include <QRegularExpression>
#include <QString>

class PdfData
{
private:
    PdfData();
    static QString m_dir_background;
    static QString m_dir_logo;
    static QString m_dir_pdf;
    static QString m_dir_templates;

    static QString m_template_institute;
    static QString m_template_private;
    static QString m_template_current;

    static QRegularExpression rx;

public:
    static QString dirBackground();
    static QString dirLogo();
    static QString dirPdf();
    static QString dirTemplates();

    static QString templateInstitute();
    static QString templatePrivate();
    static QString templateCurrent();

    static void setDirBackground(const QString &dir);
    static void setDirLogo(const QString &dir);
    static void setDirPdf(const QString &dir);
    static void setDirTemplates(const QString &dir);

    static void setTemplateInstitute(const QString &file);
    static void setTemplatePrivate(const QString &file);
    static void setTemplateCurrent(const QString &file);

    static bool validateFileName(QString &new_name, QString &file_name, QString &new_template_file);
};

#endif // PDFDATA_H
