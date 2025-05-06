#include "widgetprojectlist.h"
#include "ui_widgetprojectlist.h"

#include "projecthandler.h"

#include <QDebug>
#include <QListWidgetItem>

WidgetProjectList::WidgetProjectList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetProjectList)
{
    ui->setupUi(this);
    ui->list_projects->setSpacing(0);
    listProjects();
    connect(ui->list_projects, &QListWidget::currentRowChanged, this, &WidgetProjectList::onClickedItem);
}

WidgetProjectList::~WidgetProjectList()
{
    delete ui;
}

void WidgetProjectList::addItem(ProjectFileData *project)
{
    QListWidgetItem* item = new QListWidgetItem(project->name());
    ui->list_projects->addItem(item);
    ui->list_projects->setFocusPolicy(Qt::NoFocus);
}

void WidgetProjectList::listProjects()
{
    ProjectHandler *project_handler = ProjectHandler::GetInstance();
    project_handler->loadProjects();
    if (project_handler->projects().isEmpty())
        return;

    ProjectFileData* project;
    foreach (project, project_handler->projects())
        addItem(project);

}

void WidgetProjectList::setOpenProject()
{
    qDebug() << __FUNCTION__;
    ProjectHandler* project_handler = ProjectHandler::GetInstance();
    project_handler->setStartAction(AppState::Open);
    if (getProjectIndex() == -1) return;
    project_handler->setProject( getProjectIndex() );
}

bool WidgetProjectList::noSelection()
{
    return ui->list_projects->selectedItems().isEmpty();
}

int WidgetProjectList::getProjectIndex() const
{
    return m_project_index;
}

void WidgetProjectList::onClickedItem(int rowIndex)
{
    m_project_index = rowIndex;
    emit enableOpen(true);
}
