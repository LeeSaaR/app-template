#ifndef PROJECTCREATOR_H
#define PROJECTCREATOR_H

#include <QString>

class ProjectCreator
{
protected:
    static ProjectCreator* m_instance;

private:
    ProjectCreator(){}

public:
    ProjectCreator(ProjectCreator &other) = delete;
    void operator=(const ProjectCreator &other) = delete;
    static ProjectCreator *GetInstance();

private:
    QString m_project_name;

public:
    void setProjectName(const QString& project_name);
    void createProject();
    void createFolder(const QString& folder);
    void createDatabase(const QString& database_file_name);
};

#endif // PROJECTCREATOR_H
