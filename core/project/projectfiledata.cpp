#include "projectfiledata.h"

ProjectFileData::ProjectFileData(const QString &_name, const QString &_file_path)
    : m_name(_name)
    , m_file_path(_file_path)
{

}

QString ProjectFileData::name() const
{
    return m_name;
}

QString ProjectFileData::file_path() const
{
    return m_file_path;
}


