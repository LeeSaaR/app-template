#include "dialogpdfpreview.h"
#include "ui_dialogpdfpreview.h"

#include "appdata.h"
#include "appio.h"
#include "appmsgbox.h"
#include "appwindow.h"
#include "letterdata.h"
#include "pdfdata.h"
#include "pdfletterdataloader.h"
#include "pdfletterpreview.h"
#include "widgetprop.h"

#include <QDebug>
#include <QTextEdit>

DialogPdfPreview::DialogPdfPreview(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPdfPreview)
{
    ui->setupUi(this);
    init();
}

DialogPdfPreview::~DialogPdfPreview()
{
    if (letter) delete letter;
    if (pdfViewer) delete pdfViewer;
    delete ui;
}

void DialogPdfPreview::init()
{
    initUi();
    initFileAndPath();
    initTemplateFiles();
    initPdfViewer();
    initLetterData();
    initOptions();
    updatePdfViewer();
}

void DialogPdfPreview::initUi()
{
    WidgetProp::showMaximized(this);
    AppData * appData = AppData::GetInstance();
    setWindowTitle(appData->appName()+" - Templates");
    connect(ui->btn_save, &QPushButton::clicked, this, &DialogPdfPreview::onSave);
}

void DialogPdfPreview::initFileAndPath()
{
    AppData * appData = AppData::GetInstance();
    preview_file = appData->dir_temp()+"/test_preview.pdf";
}

void DialogPdfPreview::initLetterData()
{
    letter = new LetterData();
    previewPrivate();
    pdfWriter = new PdfWriter();
    pdf_preview = new PdfLetterPreview(pdfWriter);
    pdf_preview->setData(letter);
}

void DialogPdfPreview::initOptions()
{
    qDebug() << __FUNCTION__;
    loadTemplate();
    LetterOptions* sen_opt = letter->opt;

    addOption("Logo", sen_opt->useLogo(), false);
    connect(opts_simple["Logo"], &WgtPdfPreviewLetterOption::clickedOption, this, &DialogPdfPreview::toggleLogo);
    addFile("Logo", letter->logoFile());
    opts_file["Logo"]->setTooltipText("900x600 px | 96 dpi | 3:2 | .png | transparent");
    connect(opts_file["Logo"], &WgtPdfPreviewFileSelect::selectedFile, this, &DialogPdfPreview::onSelectedLogo);
    opts_file["Logo"]->setDefaultPath(PdfData::dirLogo());
    opts_file["Logo"]->setDefaultText("Logo auswählen");

    addOption("Hintergrund", sen_opt->useBackground(), false);
    connect(opts_simple["Hintergrund"], &WgtPdfPreviewLetterOption::clickedOption, this, &DialogPdfPreview::toggleBackground);
    addFile("Hintergrund", letter->backgroundFile());
    opts_file["Hintergrund"]->setTooltipText("2480x3508 px | 300 dpi | 3:4 | .png | transparent");
    connect(opts_file["Hintergrund"], &WgtPdfPreviewFileSelect::selectedFile, this, &DialogPdfPreview::onSelectedBackground);
    opts_file["Hintergrund"]->setDefaultPath(PdfData::dirBackground());
    opts_file["Hintergrund"]->setDefaultText("Hintergrund auswählen");

    addOption("Kontaktperson", sen_opt->useContact());

    addOption("Fußzeile", sen_opt->useFooter());
    connect(opts_simple["Fußzeile"], &WgtPdfPreviewLetterOption::clickedOption, this, &DialogPdfPreview::toggleFooter);
    addOption("Horizontal", sen_opt->useHorizontal());
    addOption("Vorname abkürzen", sen_opt->useAbbreviation());
    addOption("Webseite", sen_opt->useWebsite());
    addOption("Email", sen_opt->useEmail());
    addOption("Festnetz", sen_opt->useTelephone());
    addOption("Mobil", sen_opt->useMobile());
    addOption("Bankdaten", sen_opt->useBank());
}

void DialogPdfPreview::initPdfViewer()
{
    qDebug() << __FUNCTION__;
    setStyleSheet(AppWindow::get()->styleSheet());
    pdfViewer = new PdfViewerWidget(this);
    pdfViewer->selectZoom("80%");
    ui->frame_viewer->layout()->addWidget(pdfViewer);
}

void DialogPdfPreview::initTemplateFiles(const QString &created_template)
{
    disconnect(ui->comboBox, &QComboBox::activated, this, &DialogPdfPreview::onActivateCombobox);
    ui->comboBox->clear();
    const QList<QString> template_files = AppIO::listFiles(PdfData::dirTemplates());
    for (const QString &file : std::as_const(template_files)){
        QString item_name = file;
        item_name.replace("_", " ");
        item_name.replace(".json", "");
        if (item_name == "letter options institute")
            item_name = "Institut";
        if (item_name == "letter options private")
            item_name = "Privat";
        ui->comboBox->addItem(item_name, PdfData::dirTemplates()+"/"+file);
    }
    connect(ui->comboBox, &QComboBox::activated, this, &DialogPdfPreview::onActivateCombobox);

    if (created_template.isEmpty())
        currentTemplateFromSelection();
    else
        ui->comboBox->setCurrentText(created_template);
}

void DialogPdfPreview::addOption(const QString& name, const bool &enable, const bool &connect_slot)
{
    qDebug() << __FUNCTION__;
    WgtPdfPreviewLetterOption * option = new WgtPdfPreviewLetterOption(this);
    option->init(name, enable);
    opts_simple[name] = option;
    ui->frame_options->layout()->addWidget(option);
    if (connect_slot)
        connect(option, &WgtPdfPreviewLetterOption::clickedOption, this, &DialogPdfPreview::onClickedOption);

}

void DialogPdfPreview::addFile(const QString &name, const QString &file_path)
{
    qDebug() << __FUNCTION__;
    WgtPdfPreviewFileSelect* file_dropdown = new WgtPdfPreviewFileSelect(this);
    file_dropdown->setValue(file_path);
    ui->frame_options->layout()->addWidget(file_dropdown);
    opts_file[name] = file_dropdown;
}

void DialogPdfPreview::loadTemplate()
{
    PdfLetterDataLoader::loadConfig(template_current, letter);
}

void DialogPdfPreview::saveTemplate()
{
    PdfLetterDataLoader::saveConfig(new_template_file, letter);
}

void DialogPdfPreview::previewPrivate()
{
    letter->opt->useVAT(letter->sen->isPrivate());
    if (letter->sen->isPrivate()) {
        letter->sen->bankAccount("Kim Mustermann");
    }
    else {
        letter->sen->bankAccount("Deine Firma GmbH");
    }
}

void DialogPdfPreview::currentTemplateFromSelection()
{
    template_current = ui->comboBox->currentData().toString();
}

void DialogPdfPreview::transferOptionsToData()
{
    qDebug() << __FUNCTION__;
    LetterOptions* sen_opt = letter->opt;

    letter->logoFile( opts_file["Logo"]->filePath() );
    letter->backgroundFile( opts_file["Hintergrund"]->filePath() );
    sen_opt->useLogo( opts_simple["Logo"]->isChecked() );
    sen_opt->useBackground( opts_simple["Hintergrund"]->isChecked() );
    sen_opt->useContact(opts_simple["Kontaktperson"]->isChecked());
    sen_opt->useFooter(opts_simple["Fußzeile"]->isChecked());
    sen_opt->useHorizontal(opts_simple["Horizontal"]->isChecked());
    sen_opt->useAbbreviation(opts_simple["Vorname abkürzen"]->isChecked());
    sen_opt->useWebsite(opts_simple["Webseite"]->isChecked());
    sen_opt->useEmail(opts_simple["Email"]->isChecked());
    sen_opt->useTelephone(opts_simple["Festnetz"]->isChecked());
    sen_opt->useMobile(opts_simple["Mobil"]->isChecked());
    sen_opt->useBank(opts_simple["Bankdaten"]->isChecked());
}

void DialogPdfPreview::transferDataToOptions()
{
    qDebug() << __FUNCTION__;
    LetterOptions* opt = letter->opt;
    opts_file["Logo"]->setText(letter->logoFile());
    opts_file["Hintergrund"]->setText(letter->backgroundFile());
    opts_simple["Logo"]->setChecked(opt->useLogo());
    opts_simple["Hintergrund"]->setChecked(opt->useBackground());
    opts_simple["Kontaktperson"]->setChecked(opt->useContact());
    opts_simple["Fußzeile"]->setChecked(opt->useFooter());
    opts_simple["Horizontal"]->setChecked(opt->useHorizontal());
    opts_simple["Vorname abkürzen"]->setChecked(opt->useAbbreviation());
    opts_simple["Webseite"]->setChecked(opt->useWebsite());
    opts_simple["Email"]->setChecked(opt->useEmail());
    opts_simple["Festnetz"]->setChecked(opt->useTelephone());
    opts_simple["Mobil"]->setChecked(opt->useMobile());
    opts_simple["Bankdaten"]->setChecked(opt->useBank());
}

void DialogPdfPreview::updatePdfViewer()
{
    pdf_preview->generate();
    pdfViewer->loadDocument(preview_file);
}

void DialogPdfPreview::updateDataFromOptions()
{
    transferOptionsToData();
    updatePdfViewer();
}

void DialogPdfPreview::updateDataToOptions()
{
    transferDataToOptions();
    updatePdfViewer();
}

void DialogPdfPreview::updateImage(const QString &map_name, const QString &dir_img)
{
    // selected full file path from dialog
    QString source_file = opts_file[map_name]->selected_file;
    QFileInfo file_info(source_file);

    // generate file path: [root]/pdf/image/logo/filname.json
    const QString file_name = file_info.fileName();
    QString target_file = dir_img+"/"+file_name;

    bool is_file_from_appdata_images = file_info.absolutePath() == dir_img;

    if (!is_file_from_appdata_images) {
        bool overwrite_file = true;
        if (AppIO::fileExists(target_file)){
            // Does file exists? Ask to overwrite
            AppMsgBox* msgBox = new AppMsgBox(MsgBox::FileExists, this);
            msgBox->exec();
            MsgBox::ExitCode exit_code = msgBox->exit_code();
            delete msgBox;
            switch (exit_code) {
            case MsgBox::ExitCode::No: // DON'T OVERWRITE
                return;
                break;
            case MsgBox::ExitCode::Yes: // OVERWRITE
                overwrite_file = true;
                break;
            default:
                return;
                break;
            }
        }
        if (overwrite_file)
            AppIO::copyFile(source_file, dir_img);
    }

    opts_file[map_name]->setValue(file_name);
    updateDataFromOptions();
}

void DialogPdfPreview::onSelectedLogo()
{
    updateImage("Logo", PdfData::dirLogo());
}

void DialogPdfPreview::onSelectedBackground()
{
    updateImage("Hintergrund", PdfData::dirBackground());
}

void DialogPdfPreview::onClickedOption()
{
    qDebug() << __FUNCTION__;
    updateDataFromOptions();
}

void DialogPdfPreview::onSave()
{
    qDebug() << __FUNCTION__;
    QString file_name = ui->lineEdit->text().toLower();
    QString new_name;
    if (!PdfData::validateFileName(new_name, file_name, new_template_file)) return;

    saveTemplate();
    ui->lineEdit->clear();

    initTemplateFiles(new_name);
}

void DialogPdfPreview::toggleFooter()
{
    const bool toggle = opts_simple["Fußzeile"]->isChecked();

    opts_simple["Horizontal"]->setVisible(toggle);
    opts_simple["Webseite"]->setVisible(toggle);
    opts_simple["Email"]->setVisible(toggle);
    opts_simple["Festnetz"]->setVisible(toggle);
    opts_simple["Mobil"]->setVisible(toggle);
    opts_simple["Bankdaten"]->setVisible(toggle);
    opts_simple["Vorname abkürzen"]->setVisible(toggle);
}

void DialogPdfPreview::toggleLogo()
{
    qDebug() << __FUNCTION__;
    const bool toggle = opts_simple["Logo"]->isChecked();
    opts_file["Logo"]->setVisible(toggle);
    onClickedOption();
}

void DialogPdfPreview::toggleBackground()
{
    const bool toggle = opts_simple["Hintergrund"]->isChecked();
    opts_file["Hintergrund"]->setVisible(toggle);
    onClickedOption();
}

void DialogPdfPreview::onActivateCombobox()
{
    qDebug() << __FUNCTION__;
    currentTemplateFromSelection();
    loadTemplate();
    previewPrivate();
    updateDataToOptions();
}
