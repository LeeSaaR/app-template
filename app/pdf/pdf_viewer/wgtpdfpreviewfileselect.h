#ifndef WGTPDFPREVIEWFILESELECT_H
#define WGTPDFPREVIEWFILESELECT_H

#include <QWidget>

namespace Ui {
class WgtPdfPreviewFileSelect;
}

class WgtPdfPreviewFileSelect : public QWidget
{
    Q_OBJECT

public:
    explicit WgtPdfPreviewFileSelect(QWidget *parent = nullptr);
    ~WgtPdfPreviewFileSelect();

    void setText(const QString &file_path);
    void setValue(const QString &file_path);
    void setDefaultPath(const QString &path);
    void setDefaultText(const QString &text);
    void setTooltipText(const QString &text);
    QString filePath() const;
    QString selected_file;

signals:
    void selectedFile();

private:
    Ui::WgtPdfPreviewFileSelect *ui;
    QString m_value;
    QString m_default_path;
    QString m_default_text;


private slots:
    void onClickedButton();
};

#endif // WGTPDFPREVIEWFILESELECT_H
