#ifndef WIDGETPROJECTNAME_H
#define WIDGETPROJECTNAME_H

#include "wgtnewproject.h"
#include "wgttextline.h"
#include <QWidget>


class WgtNewProject;

namespace Ui {
class WidgetProjectName;
}

class WidgetProjectName : public WgtNewProject
{
    Q_OBJECT

public:
    explicit WidgetProjectName(QWidget *parent = nullptr);
    ~WidgetProjectName();

private:
    Ui::WidgetProjectName *ui;
    WgtTextLine* text_line_project_name;

public:
    void transferNewProjectData() override;
};

#endif // WIDGETPROJECTNAME_H
