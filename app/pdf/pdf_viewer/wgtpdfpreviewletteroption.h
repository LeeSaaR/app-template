#ifndef WGTPDFPREVIEWLETTEROPTION_H
#define WGTPDFPREVIEWLETTEROPTION_H

#include <QWidget>

namespace Ui {
class WgtPdfPreviewLetterOption;
}

class WgtPdfPreviewLetterOption : public QWidget
{
    Q_OBJECT

public:
    explicit WgtPdfPreviewLetterOption(QWidget *parent = nullptr);
    ~WgtPdfPreviewLetterOption();

    QString name;

    void init(const QString &name, const bool& enable);
    const bool isChecked()const;
    void setTooltipText(const QString &text);
    void setChecked(const bool &check);


signals:
    void clickedOption();

private:
    Ui::WgtPdfPreviewLetterOption *ui;
};

#endif // WGTPDFPREVIEWLETTEROPTION_H
