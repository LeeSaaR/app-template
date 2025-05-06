#ifndef PDFVIEWERWIDGET_H
#define PDFVIEWERWIDGET_H

#include <QKeyEvent>
#include <QPdfDocument>
#include <QWidget>

namespace Ui {
class PdfViewerWidget;
}

class PdfViewerWidget : public QWidget
{
    Q_OBJECT
private:
    Ui::PdfViewerWidget *ui;
    QPdfDocument * m_document = nullptr;
    bool m_document_is_open = false;
    int m_zoom_percent = 150;
    QString current_file = "";

public:
    explicit PdfViewerWidget(QWidget *parent = nullptr);
    ~PdfViewerWidget();

    void initComboBoxZoom();

public:
    const QString loadDocument(const QString &file);
    void reloadDocument();
    void closeDocument();
    void setZoomFactor(const int &percent);
    void selectZoom(const QString &percent);
    void setZoomFactor();
    void increaseZoom();
    void decreaseZoom();
    bool isOpen();

private slots:
    void onActivatedZoom();

protected:
    void keyPressEvent(QKeyEvent *event) override;

};

#endif // PDFVIEWERWIDGET_H
