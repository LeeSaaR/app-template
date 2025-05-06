#include "widgetlettereditor.h"
#include "ui_widgetlettereditor.h"

// #include "appdata.h"
// #include "apptext.h"
// #include "propwgt.h"
// #include "propui.h"
// #include "widgetprop.h"

#include <QLabel>
#include <QTabBar>
#include <QDebug>

WidgetLetterEditor::WidgetLetterEditor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetLetterEditor)
{
    qDebug() << __FUNCTION__;
    ui->setupUi(this);
    init();
}

WidgetLetterEditor::~WidgetLetterEditor()
{
    qDebug() << __FUNCTION__;
    disconnect(tabs, &QTabWidget::currentChanged, this, &WidgetLetterEditor::onClickedPreview);
    if (editor) delete editor;
    if (pdfViewer) delete pdfViewer;
    delete ui;
}

void WidgetLetterEditor::init()
{
    // Buttons
    initTabWidget();
}

void WidgetLetterEditor::initTabWidget()
{
    tabs = ui->tabWidget;
    tabs->clear();
    initTabEditor();
    initTabPreview();
    tabs->setCurrentIndex(0);
    connect(tabs, &QTabWidget::currentChanged, this, &WidgetLetterEditor::onClickedPreview);
}

void WidgetLetterEditor::initTabEditor()
{
    editor = new QLabel("Editor", this);
    tabs->addTab(editor, "Editor");
}

void WidgetLetterEditor::initTabPreview()
{
    if (pdfViewer) delete pdfViewer;
    pdfViewer = new PdfViewerWidget(this);
    tabs->addTab(pdfViewer, "Preview");
}

void WidgetLetterEditor::onClickedPreview(const int& index)
{
    qDebug() << __FUNCTION__;
    if (index == 0) return;
    pdfViewer->reloadDocument();
}

