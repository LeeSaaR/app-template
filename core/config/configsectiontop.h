#ifndef CONFIGSECTIONTOP_H
#define CONFIGSECTIONTOP_H

#include "configsectionsub.h"

#include <QMap>
#include <QString>

class ConfigSectionTop
{
private:
    QString m_name;
    QMap<QString, ConfigSectionSub*> m_sections;

public:
    ConfigSectionTop();
    QString name() const {return m_name;};
    void setName(const QString &name);
    void addSection(const QString &section_name, ConfigData *data, QList<ConfigSectionSub*> &subs);
    void add(ConfigData* data, QList<ConfigSectionSub*> &subs);
    ConfigSectionSub* get(const QString &name);
    QList<ConfigSectionSub*> list();
    void clear();
};

#endif // CONFIGSECTIONTOP_H
