#include "configsectiontop.h"

#include <QDebug>

ConfigSectionTop::ConfigSectionTop() {}

void ConfigSectionTop::setName(const QString &name)
{
    m_name = name;
}

void ConfigSectionTop::addSection(const QString &section_name, ConfigData *data, QList<ConfigSectionSub*> &subs)
{
    if (!m_sections.contains(section_name)) {
        m_sections[section_name] = new ConfigSectionSub();
        m_sections[section_name]->setName(section_name);
        subs.append(m_sections[section_name]);
    }
}

void ConfigSectionTop::add(ConfigData *data, QList<ConfigSectionSub*> &subs)
{
    addSection(data->sub(), data, subs);
    m_sections[data->sub()]->add(data);
}

ConfigSectionSub *ConfigSectionTop::get(const QString &name)
{
    return m_sections[name];
}

QList<ConfigSectionSub *> ConfigSectionTop::list()
{
    QList<ConfigSectionSub *> list;
    QMapIterator<QString, ConfigSectionSub*> it(m_sections);
    while (it.hasNext()) {
        it.next();
        list.append(it.value());
    }
    return list;
}

void ConfigSectionTop::clear()
{
    qDeleteAll(m_sections);
}
