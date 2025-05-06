#ifndef WIDGETLETTEREDITOR_H
#define WIDGETLETTEREDITOR_H

#include "pdfviewerwidget.h"

#include <QTabWidget>
#include <QWidget>

namespace Ui {
class WidgetLetterEditor;
}

class WidgetLetterEditor : public QWidget
{
    Q_OBJECT

private:
    Ui::WidgetLetterEditor *ui;
    PdfViewerWidget* pdfViewer = nullptr;
    QTabWidget* tabs = nullptr;
    QWidget* editor = nullptr;

public:
    explicit WidgetLetterEditor(QWidget *parent = nullptr);
    ~WidgetLetterEditor();

private:
    void init();
    void initTabEditor();
    void initTabPreview();
    void initTabWidget();

private slots:
    void onClickedPreview(const int &index);
};

#endif // WIDGETLETTEREDITOR_H
