#include "projectdata.h"

#include <QDebug>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>

#include "appdata.h"
#include "appio.h"
#include "projecthandler.h"
#include "appwindow.h"

ProjectData* ProjectData::m_instance = nullptr;

ProjectData* ProjectData::GetInstance()
{
    if (m_instance == nullptr)
        m_instance = new ProjectData();

    return m_instance;
}

ProjectData::~ProjectData()
{
}

bool ProjectData::load()
{
    reset();
    setProjectFileData();
    // NAME
    m_project_name = m_project_file_data->name();

    // PROJECT FILE
    AppData *appData = AppData::GetInstance();
    switch (m_file_path_type) {
    case InCentralDir:
        m_project_file = appData->dir_project()+"/"+m_project_file_data->file_path();
        break;
    case OnFileSystem:
        m_project_file = m_project_file_data->file_path();
        break;
    default:
        m_project_file = appData->dir_project()+"/"+m_project_file_data->file_path();
        break;
    }

    // DATABASE FILE
    QJsonDocument jsonDoc   = AppIO::loadJsonFile(m_project_file);
    QJsonObject objMain     = jsonDoc.object();
    QJsonValue val_database = objMain.value("Database");
    QJsonValue val_folder   = objMain.value("Folder");

    m_project_folder = appData->dir_data()+"/"+val_folder.toString();

    switch (m_file_path_type) {
    case InCentralDir:
        m_database_file = m_project_folder+"/"+val_database.toString();
        break;
    case OnFileSystem:
        m_project_file = val_database.toString();
        break;
    default:
        m_database_file = m_project_folder+"/"+val_database.toString();
        break;
    }

    // DATABASE CONNECTION NAME
    QFileInfo file_info(m_database_file);
    m_database_connection = "conn_"+file_info.baseName();

    AppWindow* appWindow = AppWindow::get();
    appWindow->setWindowTitle(appData->appName()+" - "+m_project_name);
    return true;
}

void ProjectData::reset()
{
    m_project_file_data = nullptr;
    m_project_name.clear();
    m_project_file.clear();
    m_project_folder.clear();
    m_database_file.clear();
    m_database_connection.clear();
}


QString ProjectData::projectName() const
{
    return m_project_file_data->name();
}

QString ProjectData::projectFile() const
{
    return m_project_file;
}

QString ProjectData::projectFolder() const
{
    return m_project_folder;
}

QString ProjectData::databaseFile() const
{
    return m_database_file;
}

QString ProjectData::db_connection() const
{
    return m_database_connection;
}

void ProjectData::setProjectFileData()
{
    ProjectHandler* project_handler = ProjectHandler::GetInstance();
    m_project_file_data = project_handler->projectFileData();
}
