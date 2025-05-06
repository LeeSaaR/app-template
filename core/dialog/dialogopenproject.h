#ifndef DIALOGOPENPROJECT_H
#define DIALOGOPENPROJECT_H


#include "widgetprojectlist.h"
#include "appstates.h"

#include <QDialog>

namespace Ui {
class DialogOpenProject;
}

class DialogOpenProject : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOpenProject(QWidget *parent = nullptr);
    ~DialogOpenProject();

private:
    Ui::DialogOpenProject *ui;
    AppState exit_state = AppState::None;
    WidgetProjectList* project_list;

private:
    void init();
    void initConnections();
    void initProjectList();
    void initWindow();
    void initTexts();

public:
    AppState state() const;

private slots:
    void enableButtonOpen(bool enable);
    void onOpen();
    void onCancel();
    void onExit();
};

#endif // DIALOGOPENPROJECT_H
