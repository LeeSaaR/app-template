#ifndef PDFVIEWER_H
#define PDFVIEWER_H

#include "dialogpdfviewer.h"

#include <QObject>

class PdfViewer : public QObject
{
    Q_OBJECT
private:
    //explicit PdfViewer(QObject *parent = nullptr):QObject(parent){};
private:
    explicit PdfViewer(QObject* parent = nullptr) : QObject{parent}{}; // Prevent construction
    PdfViewer(const PdfViewer&) = delete; // Prevent construction by copying
    PdfViewer& operator=(const PdfViewer&) = delete; // Prevent assignment
    ~PdfViewer(){}; // Prevent unwanted destruction
    static PdfViewer* m_instance;

public:
    static PdfViewer* GetInstance(QObject* parent = nullptr);
    static void DeleteInstance();

private:
    DialogPdfViewer* pdf_viewer = nullptr;
    bool m_isOpen = false;

public:
    bool isOpen() {return m_isOpen;};
    void setIsOpen(const bool &is_open) {m_isOpen = is_open;};
    void open();
    void close();
    void openDocument(const QString &file_path);
    void openDocument(const QString &file_path, const QString& tab_name);

private slots:
    void onClose();
};

#endif // PDFVIEWER_H
