#ifndef DIALOGPDFVIEWER_H
#define DIALOGPDFVIEWER_H

#include "pdfviewerwidget.h"
#include <QDialog>
#include <QTabWidget>

namespace Ui {
class DialogPdfViewer;
}

class DialogPdfViewer : public QDialog
{
    Q_OBJECT

private:
    Ui::DialogPdfViewer *ui;
    QTabWidget* tabs;
    QList<PdfViewerWidget*> m_viewers_list;


public:
    explicit DialogPdfViewer(QWidget *parent = nullptr);
    ~DialogPdfViewer();

signals:
    void notifyClose();

private:
    void init();
    void initUi();

public:
    void openDocInTab(const QString &full_file_path);
    void openDocInTab(const QString &full_file_path, const QString& tab_name);

private slots:
    void onTabCloseRequest(const int &tab_index);

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // DIALOGPDFVIEWER_H
