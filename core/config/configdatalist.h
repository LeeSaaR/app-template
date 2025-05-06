#ifndef CONFIGDATALIST_H
#define CONFIGDATALIST_H

#include "configsectiontop.h"
#include <QMap>
#include <QString>

class ConfigDataList
{
public:
    QMap<QString, ConfigSectionTop*> m_sections;
    QList<QString> m_section_names;

private:
    QList<ConfigSectionTop*> tops;
    QList<ConfigSectionSub*> subs;
    QList<ConfigData*> configs;

public:
    ConfigDataList();
    void addSection(const QString &section_name);
    void addData(ConfigData* data);
    ConfigSectionTop* top(const QString &name);
    ConfigSectionSub* sub(const QString &name);
    ConfigData* data(const QString &name);
    ConfigData* data(const QString &top, const QString &sub, const QString &name);
    QList<ConfigSectionTop*> list();
    void clear();
};

#endif // CONFIGDATALIST_H
