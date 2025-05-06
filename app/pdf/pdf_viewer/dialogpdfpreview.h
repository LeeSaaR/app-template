#ifndef DIALOGPDFPREVIEW_H
#define DIALOGPDFPREVIEW_H

#include "pdfviewerwidget.h"
#include "appio.h"
#include "letterdata.h"
#include "wgtpdfpreviewletteroption.h"
#include "pdfletterpreview.h"
#include "wgtpdfpreviewfileselect.h"
#include <QDialog>
#include <QRegularExpression>

namespace Ui {
class DialogPdfPreview;
}

class DialogPdfPreview : public QDialog
{
    Q_OBJECT

private:
    Ui::DialogPdfPreview *ui;
    PdfViewerWidget* pdfViewer = nullptr;
    LetterData* letter;
    QMap<QString, WgtPdfPreviewLetterOption*> opts_simple;
    QMap<QString, WgtPdfPreviewFileSelect*> opts_file;
    PdfLetterPreview* pdf_preview;
    PdfWriter* pdfWriter;
    QString preview_file;
    QString template_dir;
    QString template_default_private;
    QString template_default_institute;
    QString template_current;
    QString dir_logo;
    QString dir_background;
    QString new_template_file;

public:
    explicit DialogPdfPreview(QWidget *parent = nullptr);
    ~DialogPdfPreview();

private:
    void init();
    void initUi();
    void initFileAndPath();
    void initLetterData();
    void initOptions();
    void initPdfViewer();
    void initTemplateFiles(const QString &created_template = "");
    void addOption(const QString& name, const bool &enable, const bool &connect_slot = true);
    void addFile(const QString& name, const QString &file_path);
    void previewPrivate();
    void currentTemplateFromSelection();
    void reloadTemplateFiles();
    void loadTemplate();
    void saveTemplate();

    void transferOptionsToData();
    void transferDataToOptions();
    void updatePdfViewer();
    void updateDataFromOptions();
    void updateDataToOptions();
    void updateImage(const QString &map_name, const QString &dir_img);

public slots:
    void onSelectedLogo();
    void onSelectedBackground();
    void onClickedOption();
    void onSave();
    void toggleFooter();
    void toggleLogo();
    void toggleBackground();
    void onActivateCombobox();
};

#endif // DIALOGPDFPREVIEW_H
