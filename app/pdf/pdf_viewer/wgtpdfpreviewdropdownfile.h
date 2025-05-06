#ifndef WGTPDFPREVIEWDROPDOWNFILE_H
#define WGTPDFPREVIEWDROPDOWNFILE_H

#include <QWidget>

namespace Ui {
class WgtPdfPreviewDropDownFile;
}

class WgtPdfPreviewDropDownFile : public QWidget
{
    Q_OBJECT

public:
    explicit WgtPdfPreviewDropDownFile(QWidget *parent = nullptr);
    ~WgtPdfPreviewDropDownFile();

private:
    Ui::WgtPdfPreviewDropDownFile *ui;

public:
    QString value() const;
    void setValue(const QString &value);

private slots:
    void onActivated();
};

#endif // WGTPDFPREVIEWDROPDOWNFILE_H
