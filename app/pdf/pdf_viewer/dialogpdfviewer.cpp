#include "dialogpdfviewer.h"
#include "ui_dialogpdfviewer.h"

#include "appdata.h"
#include "appwindow.h"
#include "widgetprop.h"
#include <QDebug>
#include <QSize>

DialogPdfViewer::DialogPdfViewer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPdfViewer)
{
    ui->setupUi(this);
    init();
}

DialogPdfViewer::~DialogPdfViewer()
{
    qDebug() << __FUNCTION__;
    delete ui;
}

void DialogPdfViewer::init()
{
    initUi();
    tabs = ui->tab_wgt_viewer;
    tabs->setTabsClosable(true);
    tabs->setMovable(true);
    connect(tabs, &QTabWidget::tabCloseRequested, this, &DialogPdfViewer::onTabCloseRequest);
}

void DialogPdfViewer::initUi()
{
    WidgetProp::showMaximized(this);
    setStyleSheet(AppWindow::get()->styleSheet());
    AppData* appData = AppData::GetInstance();
    setWindowTitle(appData->appName()+" - PDF Viewer");
}

void DialogPdfViewer::openDocInTab(const QString &full_file_path)
{
    PdfViewerWidget* viewer = new PdfViewerWidget(this);
    const QString doc_name = viewer->loadDocument(full_file_path);
    tabs->addTab(viewer, doc_name);
    m_viewers_list.append(viewer);
}

void DialogPdfViewer::openDocInTab(const QString &full_file_path, const QString &tab_name)
{
    PdfViewerWidget* viewer = new PdfViewerWidget(this);
    viewer->loadDocument(full_file_path);
    tabs->addTab(viewer, tab_name);
    m_viewers_list.append(viewer);
}

void DialogPdfViewer::onTabCloseRequest(const int &tab_index)
{
    PdfViewerWidget* viewer = (PdfViewerWidget*)tabs->widget(tab_index);
    m_viewers_list.removeOne(viewer);
    tabs->removeTab(tab_index);
    delete viewer;
}

void DialogPdfViewer::closeEvent(QCloseEvent *event)
{
    qDebug() << __FUNCTION__;
    emit notifyClose();
    event->accept();
}
