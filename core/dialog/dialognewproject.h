#ifndef DIALOGNEWPROJECT_H
#define DIALOGNEWPROJECT_H

# include "widgetprojectnew.h"
#include "appstates.h"

#include <QDialog>

namespace Ui {
class DialogNewProject;
}

class DialogNewProject : public QDialog
{
    Q_OBJECT
private:
    Ui::DialogNewProject *ui;
    WidgetProjectNew* pages;
    AppState exit_state = AppState::None;
public:
    explicit DialogNewProject(QWidget *parent = nullptr);
    ~DialogNewProject();
public:
    void init();
    void initPagesStack();
private:
    void enableNextBackButtons();
public:
    AppState state() const;
public slots:
    void onFinishedDialog(const AppState& exit_state);
};

#endif // DIALOGNEWPROJECT_H
