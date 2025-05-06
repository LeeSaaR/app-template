#include "widgetprojectname.h"
#include "ui_widgetprojectname.h"


#include "propwgt.h"
#include "projectcreator.h"
#include "apptext.h"

WidgetProjectName::WidgetProjectName(QWidget *parent) :
    WgtNewProject(parent),
    ui(new Ui::WidgetProjectName)
{
    ui->setupUi(this);
    text_line_project_name = new WgtTextLine(this);
    text_line_project_name->setName( AppText::lbl_project_name() );
    ui->frame_content->layout()->addWidget(text_line_project_name);
    PropWgt::setWidth(ui->frame_content, 500);
}

WidgetProjectName::~WidgetProjectName()
{
    delete ui;
}

void WidgetProjectName::transferNewProjectData()
{
    ProjectCreator* project_creator = ProjectCreator::GetInstance();
    if (text_line_project_name->text().isEmpty())
        project_creator->setProjectName("Unbenannt");
    else
        project_creator->setProjectName(text_line_project_name->text());
}
