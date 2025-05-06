#include "configsectionsub.h"

#include <QDebug>

void ConfigSectionSub::setName(const QString &name)
{
    m_name = name;
}

void ConfigSectionSub::add(ConfigData *data)
{
    m_data_list[data->name()] = data;
}

ConfigData *ConfigSectionSub::get(const QString &name)
{
    return m_data_list[name];
}

QList<ConfigData *> ConfigSectionSub::list()
{
    QList<ConfigData *> list;
    QMapIterator<QString, ConfigData*> it(m_data_list);
    while (it.hasNext()) {
        it.next();
        list.append(it.value());
    }
    return list;
}

void ConfigSectionSub::clear()
{
    qDeleteAll(m_data_list);
}

