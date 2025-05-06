#ifndef PROJECTDATA_H
#define PROJECTDATA_H

#include <QFile>
#include "projectfiledata.h"

class ProjectData
{
private:
    ProjectFileData* m_project_file_data; // Owner: ProjectHandler
    QString m_project_name;
    QString m_project_file;
    QString m_project_folder;
    QString m_database_file;
    QString m_database_connection;
private:
    ProjectData(){}
protected:
    static ProjectData* m_instance;
public:
    ~ProjectData();
    ProjectData(ProjectData &other) = delete; // copy
    void operator=(const ProjectData &other) = delete; // assign
    static ProjectData *GetInstance();

    enum FilePathType {
        InCentralDir = 1,
        OnFileSystem
    };

private:
    FilePathType m_file_path_type = InCentralDir;
public:
    bool load();
    void reset();
public:
    QString projectName() const;
    QString projectFile() const;
    QString projectFolder() const;
    QString databaseFile() const;
    QString db_connection() const;
    void setDatabaseFile();
    void setProjectFileData();
};

#endif // PROJECTDATA_H
