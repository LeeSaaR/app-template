#ifndef WIDGETPROJECTLIST_H
#define WIDGETPROJECTLIST_H

#include <QWidget>
#include "projectfiledata.h"

namespace Ui {
class WidgetProjectList;
}

class WidgetProjectList : public QWidget
{
    Q_OBJECT

private:
    Ui::WidgetProjectList *ui;
    int m_project_index = -1;

public:
    explicit WidgetProjectList(QWidget *parent = nullptr);
    ~WidgetProjectList();

signals:
    void enableOpen(bool enable);
private:
    void addItem(ProjectFileData *project);
    void listProjects();

public:
    void setOpenProject();
    bool noSelection();
    int getProjectIndex() const;

private slots:
    void onClickedItem(int rowIndex);
};

#endif // WIDGETPROJECTLIST_H
