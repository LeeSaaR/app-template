#include "projectcreator.h"
#include "projectfiledata.h"
#include "projecthandler.h"

#include <QJsonDocument>
#include <QJsonObject>
#include "appdata.h"
#include "appio.h"
#include "dbioconnector.h"
// #include "dbmodelexample.h"

ProjectCreator *ProjectCreator::m_instance = nullptr;

ProjectCreator *ProjectCreator::GetInstance()
{
    if (m_instance == nullptr)
        m_instance = new ProjectCreator();
    return m_instance;
}

void ProjectCreator::setProjectName(const QString &project_name)
{
    m_project_name = project_name;
}

void ProjectCreator::createProject()
{
    AppData* appData = AppData::GetInstance();

    // make project file name
    QString project_file = m_project_name.toLower();
    project_file.replace(" ", "_");
    project_file.replace("ä", "ae");
    project_file.replace("ö", "oe");
    project_file.replace("ü", "ue");
    project_file.replace("Ä", "Ae");
    project_file.replace("Ö", "Oe");
    project_file.replace("Ü", "Ue");
    project_file.replace("ß", "ss");
    QString destination_file_name;
    QString database_file_name;
    QString project_folder;
    bool file_exists;
    int counter = 0;
    do  {
        QString try_project_file = project_file;
        if (counter > 0) {
            try_project_file += "_0"+QString::number(counter);
        }
        const QString try_file = appData->dir_project() +"/"+ try_project_file +".json";
        file_exists = AppIO::fileExists(try_file);
        if (!file_exists) {
            project_folder = try_project_file;
            project_file = try_project_file +".json";
            destination_file_name = try_file;
            database_file_name += try_project_file +".db";
        }
        counter++;
    }
    while (file_exists);

    // create file
    AppIO::copyRenameFile(appData->file_project_struct(), destination_file_name);
    QJsonDocument jsonDoc = AppIO::loadJsonFile(destination_file_name);

    // New Values
    QJsonValue val_name     = m_project_name;
    QJsonValue val_database = database_file_name;
    QJsonValue val_folder   = project_folder;

    // Write Values
    QJsonObject objMain = jsonDoc.object();
    objMain.insert("Name", val_name);
    objMain.insert("Database", val_database);
    objMain.insert("Folder", val_folder);
    jsonDoc.setObject(objMain);
    AppIO::saveJsonFile(destination_file_name, jsonDoc);

    ProjectFileData* project_file_data = new ProjectFileData(m_project_name, project_file);

    ProjectHandler *project_handler = ProjectHandler::GetInstance();
    project_handler->addProjectFileData(project_file_data);
    createFolder(project_folder);
    createDatabase(project_folder+"/"+database_file_name);
}

void ProjectCreator::createFolder(const QString &folder)
{
    qDebug() << __FUNCTION__;
    AppData* appData = AppData::GetInstance();
    const QString full_dir_path = appData->dir_data()+"/"+folder;
    AppIO::makeDir(full_dir_path);
}

void ProjectCreator::createDatabase(const QString &database_file_name)
{
    qDebug() << __FUNCTION__;
    AppData* appData = AppData::GetInstance();
    const QString full_file_path = appData->dir_data()+"/"+database_file_name;

    QFileInfo file_info(full_file_path);
    const QString connection_name = "conn_"+file_info.baseName();

    DBIOConnector* connector = DBIOConnector::get();
    //connector->createDatabase(full_file_path, connection_name, DBModelExample::get());
}


