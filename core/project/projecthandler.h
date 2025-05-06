#ifndef PROJECTHANDLER_H
#define PROJECTHANDLER_H

#include "projectfiledata.h"
#include "appstates.h"
#include "projectdata.h"
#include <QList>

class ProjectHandler
{
protected:
    static ProjectHandler* m_instance;
    AppState start_action;
    AppState state_new_project = AppState::None;
    ProjectFileData* m_project_file_data;
    QList<ProjectFileData*> m_project_list;
    bool m_exit;
    ProjectData::FilePathType m_file_path_type = ProjectData::InCentralDir;
    // ProjectData::FilePathType file_path_type = ProjectData::OnFileSystem;

private:
    ProjectHandler(){}

public:
    ProjectHandler(ProjectHandler &other) = delete;
    void operator=(const ProjectHandler &other) = delete;
    static ProjectHandler *GetInstance();

signals:
    void triggeredNewProject();

private:
    void clearProjectList();
    void clearDeadProjects();

public:
    bool projectExists(const QString &file_path);
    ProjectData::FilePathType file_path_type() const;
    void updateProjectList();
    void loadProjects();
    void loadProjectData();
    void addProjectFileData(ProjectFileData* new_project_file_data);
    void reset();
    void resetCurrentProject();
    void printProjects();
    AppState startAction() const;

public:
    QList<ProjectFileData*> projects() const;
    ProjectFileData *projectFileData();

public:
    void setProject(const int &project_index);
    void setStartAction(AppState action);
};

#endif // PROJECTHANDLER_H
