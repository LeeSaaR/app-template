#ifndef PROJECTFILEDATA_H
#define PROJECTFILEDATA_H

#include <QString>

class ProjectFileData
{
private:
    const QString m_name;
    const QString m_file_path;
public:
    ProjectFileData(const QString& _name, const QString& _file_path);
    QString name() const;
    QString file_path() const;
};

#endif // PROJECTFILEDATA_H
