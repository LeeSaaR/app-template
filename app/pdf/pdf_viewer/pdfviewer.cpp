#include "pdfviewer.h"

PdfViewer* PdfViewer::m_instance = nullptr;

PdfViewer *PdfViewer::GetInstance(QObject* parent)
{
    if (m_instance == nullptr)
        m_instance = new PdfViewer(parent);
    return m_instance;
}

void PdfViewer::DeleteInstance()
{
    delete m_instance;
    m_instance = nullptr;
}

void PdfViewer::open()
{
    if (isOpen())
        return;

    pdf_viewer = new DialogPdfViewer();
    QObject::connect(
        pdf_viewer, &DialogPdfViewer::notifyClose,
        this, &PdfViewer::onClose);

    pdf_viewer->show();
    setIsOpen(true);
}

void PdfViewer::openDocument(const QString &file_path)
{
    pdf_viewer->openDocInTab(file_path);
}

void PdfViewer::openDocument(const QString &file_path, const QString& tab_name)
{
    pdf_viewer->openDocInTab(file_path, tab_name);
}

void PdfViewer::onClose()
{
    qDebug() << __FUNCTION__;
    QObject::disconnect(pdf_viewer, &DialogPdfViewer::notifyClose, this, &PdfViewer::onClose);
    delete pdf_viewer;
    pdf_viewer = nullptr;
    setIsOpen(false);
}
