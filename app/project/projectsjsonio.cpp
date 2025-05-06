#include "projectsjsonio.h"

#include "appio.h"
#include "appdata.h"
#include <QJsonDocument>
#include <QJsonObject>

void ProjectsJsonIO::loadProjects(QList<ProjectFileData*> &projects)
{
    AppData* appData = AppData::GetInstance();
    QJsonDocument jsonDoc = AppIO::loadJsonFile(appData->file_projects());

    QJsonObject objMain = jsonDoc.object();
    QList<QString> projectObjectIndecies = objMain.keys();
    QString index;
    foreach (index, projectObjectIndecies) {
        // Init Top Sections

        QJsonObject project     = objMain.value(index).toObject();
        const QString name      = project.value("name").toString();
        const QString file_path = project.value("file_path").toString();
        projects.append(new ProjectFileData(name, file_path));
    }
}

void ProjectsJsonIO::saveProjects(QList<ProjectFileData *> &projects)
{
    AppData* appData = AppData::GetInstance();
    QJsonDocument jsonDoc = AppIO::loadJsonFile(appData->file_projects());

    QJsonObject objMain = QJsonObject();
    for (int i = 0 ; i < projects.size(); i++) {
        QJsonObject obj_project = QJsonObject();
        obj_project.insert("name", projects[i]->name());
        obj_project.insert("file_path", projects[i]->file_path());

        objMain.insert(QString::number(i), obj_project);
    }

    jsonDoc.setObject(objMain);
    AppIO::saveJsonFile(appData->file_projects(), jsonDoc);
}
