#include "projecthandler.h"
#include "appdata.h"
#include "projectsjsonio.h"
#include "projectdata.h"
#include "appio.h"
#include "apptool.h"

#include <QDebug>

ProjectHandler *ProjectHandler::m_instance = nullptr;

ProjectHandler *ProjectHandler::GetInstance()
{
    if (m_instance == nullptr)
        m_instance = new ProjectHandler();
    return m_instance;
}

void ProjectHandler::clearProjectList()
{
    m_project_file_data = nullptr;
    while (!m_project_list.isEmpty()) {
        ProjectFileData* project = m_project_list.last();
        m_project_list.removeLast();
        delete project;
    }
}

void ProjectHandler::clearDeadProjects()
{
    // Delete Dead Projects From List
    QList<ProjectFileData*> delete_from_project_list;
    ProjectFileData* project;
    foreach (project, m_project_list)
        if (!projectExists(project->file_path()))
            delete_from_project_list.append(project);

    AppTool::subtractList<ProjectFileData>(delete_from_project_list, m_project_list);
    updateProjectList();
}

bool ProjectHandler::projectExists(const QString &file_path)
{
    AppData* appData = AppData::GetInstance();
    switch (m_file_path_type) {
    case ProjectData::InCentralDir:
        return AppIO::fileExists(appData->dir_project()+"/"+file_path);
        break;
    case ProjectData::OnFileSystem:
        return AppIO::fileExists(file_path);
        break;
    default:
        return false;
        break;
    }
}

ProjectData::FilePathType ProjectHandler::file_path_type() const
{
    return m_file_path_type;
}

void ProjectHandler::updateProjectList()
{
    ProjectsJsonIO::saveProjects(m_project_list);
}

void ProjectHandler::loadProjects()
{
    if (!m_project_list.isEmpty())
        clearProjectList();

    ProjectsJsonIO::loadProjects(m_project_list);
    clearDeadProjects();
}

void ProjectHandler::loadProjectData()
{
    qDebug() << __FUNCTION__;
    ProjectData* projectData = ProjectData::GetInstance();
    projectData->load();
    qDebug() << "loaded project:" << projectData->projectName();
    qDebug() << projectData->projectFile();
    qDebug() << projectData->databaseFile();
    qDebug() << projectData->db_connection();
}

void ProjectHandler::addProjectFileData(ProjectFileData* new_project_file_data)
{
    // is called when new project is created
    loadProjects();
    m_project_file_data = new_project_file_data;
    m_project_list.prepend(new_project_file_data);
    updateProjectList();
    loadProjectData();
}

void ProjectHandler::reset()
{
    start_action = AppState::New;
    m_project_file_data = nullptr;
}

void ProjectHandler::resetCurrentProject()
{
    m_project_file_data = nullptr;
}

void ProjectHandler::setProject(const int &project_index)
{
    qDebug() << __FUNCTION__;
    this->m_project_file_data = m_project_list[project_index];
    m_project_list.removeOne(this->m_project_file_data);
    m_project_list.prepend(this->m_project_file_data);
    updateProjectList();
    loadProjectData();
}

void ProjectHandler::setStartAction(AppState action)
{
    start_action = action;
}

void ProjectHandler::printProjects()
{
    ProjectFileData *project;
    foreach (project, m_project_list)
        qDebug() << project->name() << project->file_path();
}

AppState ProjectHandler::startAction() const
{
    return start_action;
}

QList<ProjectFileData *> ProjectHandler::projects() const
{
    return m_project_list;
}

ProjectFileData *ProjectHandler::projectFileData()
{
    return m_project_file_data;
}
