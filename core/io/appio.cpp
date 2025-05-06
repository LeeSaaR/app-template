#include "appio.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>

bool AppIO::makeConfigFile(const QString &fileName)
{
    QFile configFile(fileName);

    if (!configFile.open(QTextStream::WriteOnly | QTextStream::Text)) {
        return false;
    }


    // write file here
    configFile.write("");

    configFile.flush();
    configFile.close();

    return true;
}

bool AppIO::fileExists(const QString &absoluteFilePath)
{
    return QFile::exists(absoluteFilePath);
}

bool AppIO::makeDir(const QString &absoluteDirPath)
{
    if (QFile::exists(absoluteDirPath))
        return false;

    QDir wd;
    qDebug() << "Creating Directory:" << absoluteDirPath;
    return wd.mkdir(absoluteDirPath);
}

bool AppIO::copyFile(const QString &sourceFilePath, const QString &destinationDirPath)
{
    // set absolute destination file path
    const QString fileName = QFileInfo(sourceFilePath).fileName();
    const QString destinationFilePath = destinationDirPath + "/" + fileName;

    // skip if file exists
    if (fileExists(destinationFilePath)) {
        qDebug() << "File already exists. :" + destinationFilePath << "skipping...";
        return false;
    }

    return QFile::copy(sourceFilePath, destinationFilePath);
}

bool AppIO::isEmptyDir(const QString &absoluteDirPath)
{
    return listFiles(absoluteDirPath).isEmpty();
}

void AppIO::deleteFilesInDir(const QString &absoluteDirPath)
{
    qDebug() << __FUNCTION__;
    QString file;
    foreach (file, listFiles( absoluteDirPath ))
        deleteFile(absoluteDirPath+"/"+file);
}

void AppIO::deleteFile(const QString &absoluteFilePath)
{
    qDebug() << __FUNCTION__ << absoluteFilePath;
    QFile file(absoluteFilePath);
    file.remove();
}

void AppIO::purgeProject(const QString &project_file, const QString &data_path)
{
    qDebug() << __FUNCTION__;
    qDebug() << project_file;
    qDebug() << data_path;
    deleteFile(project_file);
    QDir dir(data_path);
    dir.removeRecursively();
}

bool AppIO::copyRenameFile(const QString &sourceFilePath, const QString &destinationFilePath)
{
    // set absolute destination file path

    // skip if file exists
    if (fileExists(destinationFilePath)) {
        qDebug() << "File already exists. :" + destinationFilePath << "skipping...";
        return false;
    }

    return QFile::copy(sourceFilePath, destinationFilePath);
}

void AppIO::saveJsonFile(const QString &absoluteFilePath, QJsonDocument jsonDoc)
{
    QFile file(absoluteFilePath);
    if (!file.open(QTextStream::WriteOnly | QTextStream::Text)) {
        qDebug() << "Open file failed!" << absoluteFilePath;
        qDebug() << "Error:" << file.errorString();
        return;
    }

    file.write(jsonDoc.toJson());
    file.flush();
    file.close();
}

QJsonDocument AppIO::loadJsonFile(const QString &absoluteFilePath)
{
    QFile file(absoluteFilePath);
    if (!file.open(QTextStream::ReadOnly | QTextStream::Text)) {
        qDebug() << "Open file failed!" << absoluteFilePath;
        qDebug() << "Error:" << file.errorString();
        return QJsonDocument();
    }

    const QString json = file.readAll();
    file.close();
    file.flush();
    return QJsonDocument::fromJson(json.toUtf8());
}

QList<QString> AppIO::listFiles(const QString &absoluteDirPath)
{
    if (!fileExists(absoluteDirPath))
        return {};

    QDir wd;
    wd.cd(absoluteDirPath);
    QList<QString> files = wd.entryList();
    files.removeOne(".");
    files.removeOne("..");
    return files;
}

QList<QString> AppIO::listFiles(const QString &absoluteDirPath, const bool &prepend_path)
{
    if (!prepend_path)
        return listFiles(absoluteDirPath);

    QStringList files = listFiles(absoluteDirPath);
    for (int i = 0; i < files.size(); i++) {
        files[i].prepend(absoluteDirPath+"/");
    }
    return files;
}

bool AppIO::readFile(QString &file_content, const QString &absoluteFilePath)
{
    QFile file(absoluteFilePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "could not read file:" << absoluteFilePath;
        return false;
    }
    file_content = file.readAll();
    file.close();
    return true;
}

bool AppIO::writeFile(const QString &file_content, const QString &absoluteFilePath)
{
    QFile file(absoluteFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "could not open/write file:" << absoluteFilePath;
        return false;
    }
    QTextStream instream(&file);
    instream << file_content;
    return true;
}

