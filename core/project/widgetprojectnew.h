#ifndef WIDGETPROJECTNEW_H
#define WIDGETPROJECTNEW_H

#include "appstates.h"
#include "widgetprojectname.h"
#include "wgtnewproject.h"

#include <QPushButton>
#include <QStackedWidget>
#include <QWidget>

namespace Ui {
class WidgetProjectNew;
}

class WidgetProjectNew : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetProjectNew(QWidget *parent = nullptr);
    ~WidgetProjectNew();

private:
    Ui::WidgetProjectNew *ui;
    QStackedWidget* pages;
    AppState exit_state = AppState::None;
    //WidgetProjectName *wgt_project_name;
    QList<WgtNewProject *> wgt_list;

signals:
    void enableButtonBack(bool enable);
    void enableButtonNext(bool enable);
    void enableButtonApply(bool enable);
    void finishedDialog(AppState exit_state);

private:
    bool hasPreviousPage();
    bool hasNextPage();
    void setPage(int page_index);
    void previousPage();
    void nextPage();
    int currentPage();
    int lastPage();
    void enableBack();
    void enableNext();
    void enableApply();
    void enableButtons();
    void createNewProject();

private:
    void init();
    void addPage(QWidget *wgt);

public:
    void initPages(QList<WgtNewProject *> wgts_derived);
    void initConnections(QPushButton* btn_exit, QPushButton* cancel, QPushButton* back, QPushButton* next, QPushButton* apply);
    void setButtonStates();
    bool hasMultiplePages();

public slots:
    void onExit();
    void onBack();
    void onNext();
    void onCancel();
    void onApply();
};

#endif // WIDGETPROJECTNEW_H
