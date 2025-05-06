#include "pdfviewerwidget.h"
#include "./ui_pdfviewerwidget.h"

#include <QDebug>
#include <QScrollBar>

PdfViewerWidget::PdfViewerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PdfViewerWidget),
    m_document(new QPdfDocument(this))
{
    qDebug() << __FUNCTION__;
    ui->setupUi(this);
    QPalette palette = ui->pdfView->palette();
    palette.setBrush(QPalette::Dark, QColor(30,30,30));
    ui->pdfView->setPalette(palette);
    initComboBoxZoom();
    connect(ui->comboBox, &QComboBox::activated, this, &PdfViewerWidget::onActivatedZoom);
}

PdfViewerWidget::~PdfViewerWidget()
{
    qDebug() << __FUNCTION__;
    if (m_document) delete m_document;
    delete ui;
}

void PdfViewerWidget::initComboBoxZoom()
{
    qDebug() << __FUNCTION__;
    ui->comboBox->addItem("250%", 250);
    ui->comboBox->addItem("200%", 200);
    ui->comboBox->addItem("180%", 180);
    ui->comboBox->addItem("150%", 150);
    ui->comboBox->addItem("120%", 120);
    ui->comboBox->addItem("100%", 100);
    ui->comboBox->addItem("90%",   90);
    ui->comboBox->addItem("80%",   80);
    ui->comboBox->setCurrentText("150%");
}

const QString PdfViewerWidget::loadDocument(const QString &file)
{
    qDebug() << __FUNCTION__;
    closeDocument();
    m_document->load(file);
    QString documentTitle = m_document->metaData(QPdfDocument::MetaDataField::Title).toString();
    setWindowTitle(documentTitle);
    ui->pdfView->setDocument(m_document);
    ui->pdfView->setPageMode(QPdfView::PageMode::MultiPage);
    setZoomFactor(m_zoom_percent);
    m_document_is_open = true;
    return documentTitle;
}

void PdfViewerWidget::reloadDocument()
{
    if (current_file.isEmpty()) return;
    loadDocument(current_file);
}

void PdfViewerWidget::closeDocument()
{
    if (m_document_is_open) m_document->close();
    m_document->close();
    m_document_is_open = false;
}

void PdfViewerWidget::setZoomFactor(const int &percent)
{
    qDebug() << __FUNCTION__;
    m_zoom_percent = percent;
    // factor = percent * 0.01
    ui->pdfView->setZoomFactor(m_zoom_percent * 0.01);
}

void PdfViewerWidget::selectZoom(const QString &percent)
{
    ui->comboBox->setCurrentText(percent);
    m_zoom_percent = ui->comboBox->currentData().toInt();
    onActivatedZoom();
}

void PdfViewerWidget::setZoomFactor()
{
    ui->pdfView->setZoomFactor(m_zoom_percent * 0.01);
}

void PdfViewerWidget::increaseZoom()
{
    if (m_zoom_percent <= 380)
    {
        m_zoom_percent += 20;
        setZoomFactor();
    }
}

void PdfViewerWidget::decreaseZoom()
{
    if (m_zoom_percent > 20)
    {
        m_zoom_percent -= 20;
        setZoomFactor();
    }
}

bool PdfViewerWidget::isOpen()
{
    return m_document_is_open;
}

void PdfViewerWidget::onActivatedZoom()
{
    if (m_document_is_open)
    {
        setZoomFactor(ui->comboBox->currentData().toInt());
    }
}

void PdfViewerWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->modifiers() == (Qt::ControlModifier | Qt::KeypadModifier)) {

        switch (event->key()) {
        case Qt::Key_Plus:
            increaseZoom();
            break;

        case Qt::Key_Minus:
            decreaseZoom();
            break;

        default:
            break;
        }
    }
    event->accept();
}
