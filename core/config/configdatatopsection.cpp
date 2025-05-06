#include "configdatatopsection.h"



ConfigDataTopSection::ConfigDataTopSection()
{

}

ConfigDataTopSection::~ConfigDataTopSection()
{

}

void ConfigDataTopSection::addSection(const QString &_name, ConfigDataSubSection *_sub_section)
{
    m_sub_section[_name] = _sub_section;
}

ConfigDataSubSection *ConfigDataTopSection::getSection(const QString &_name)
{
    return m_sub_section[_name];
}

QString ConfigDataTopSection::name() const
{
    return m_name;
}
