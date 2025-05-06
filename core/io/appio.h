#ifndef APPIO_H
#define APPIO_H

#include <QJsonDocument>
#include <QString>

#include "projectdata.h"

class AppIO
{

public:
    AppIO(){}

public:
    static bool makeConfigFile(const QString &fileName);
    static bool fileExists(const QString &absoluteFilePath);
    static bool makeDir(const QString &absoluteDirPath);
    static bool copyFile(const QString &sourceFilePath, const QString &destinationDirPath);
    static bool isEmptyDir(const QString &absoluteDirPath);
    static void deleteFilesInDir(const QString &absoluteDirPath);
    static void deleteFile(const QString &absoluteFilePath);
    static void purgeProject(const QString &project_file, const QString &data_path);
    static bool copyRenameFile(const QString &sourceFilePath, const QString &destinationFilePath);
    static void saveJsonFile(const QString &absoluteFilePath, QJsonDocument jsonDoc);
    static QJsonDocument loadJsonFile(const QString &absoluteFilePath);
    static QList<QString> listFiles(const QString &absoluteDirPath);
    static QList<QString> listFiles(const QString &absoluteDirPath, const bool &prepend_path);
    static bool readFile(QString &file_content, const QString &absoluteFilePath);
    static bool writeFile(const QString &file_content, const QString &absoluteFilePath);
};

#endif // APPIO_H
