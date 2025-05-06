#include "configdatasubsection.h"

ConfigDataSubSection::ConfigDataSubSection(const QString &_name)
    : m_name(_name)
{

}

ConfigDataSubSection::~ConfigDataSubSection()
{

}

QString ConfigDataSubSection::name() const
{
    return m_name;
}

void ConfigDataSubSection::addData(const QString &_name, ConfigData *newConfigData)
{
    m_data[_name] = newConfigData;
}

ConfigData *ConfigDataSubSection::getData(const QString &_name)
{
    return m_data[_name];
}

QMap<QString, ConfigData *> ConfigDataSubSection::getAllData()
{
    return m_data;
}


