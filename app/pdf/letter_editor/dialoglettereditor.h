#ifndef DIALOGLETTEREDITOR_H
#define DIALOGLETTEREDITOR_H

#include "appstates.h"
#include "widgetlettereditor.h"

#include <QTabWidget>
#include <QDialog>

namespace Ui {
class DialogLetterEditor;
}

class DialogLetterEditor : public QDialog
{
    Q_OBJECT

private:
    Ui::DialogLetterEditor *ui;
    WidgetLetterEditor* editor = nullptr;
    QTabWidget* tabs = nullptr;
    AppState exit_state;

public:
    explicit DialogLetterEditor(QWidget *parent = nullptr);
    ~DialogLetterEditor();

private:
    void init();
    void initWidgetLetterEditor();
};

#endif // DIALOGLETTEREDITOR_H
