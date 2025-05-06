#ifndef CONFIGSECTIONSUB_H
#define CONFIGSECTIONSUB_H

#include "configdata.h"

#include <QList>
#include <QString>

class ConfigSectionSub
{
private:
    QString m_name;
    QMap<QString, ConfigData*> m_data_list;

public:
    ConfigSectionSub(){};
    QString name() const {return m_name;};
    void setName(const QString &name);
    void add(ConfigData* data);
    ConfigData* get(const QString &name);
    QList<ConfigData*> list();
    void clear();
};

#endif // CONFIGSECTIONSUB_H
