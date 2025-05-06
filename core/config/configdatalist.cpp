#include "configdatalist.h"

#include <QDebug>

ConfigDataList::ConfigDataList() {
}

void ConfigDataList::addSection(const QString &section_name)
{
    if (!m_sections.contains(section_name)) {
        ConfigSectionTop* sec = new ConfigSectionTop();
        m_sections[section_name] = sec;
        m_sections[section_name]->setName(section_name);
        tops.append(m_sections[section_name]);
    }
}


void ConfigDataList::addData(ConfigData *data)
{
    addSection(data->top());
    m_sections[data->top()]->add(data, subs);
    configs.append(data);
}

ConfigSectionTop *ConfigDataList::top(const QString &name) {
    return m_sections[name];
}

ConfigSectionSub *ConfigDataList::sub(const QString &name) {

    ConfigSectionSub* section;
    foreach (section, subs) {
        if (section->name() == name)
            return section;
    }
    return nullptr;
}

ConfigData *ConfigDataList::data(const QString &name) {

    ConfigData* config_data;
    foreach (config_data, configs) {
        if (config_data->name() == name)
            return config_data;
    }
    return nullptr;
}

ConfigData *ConfigDataList::data(const QString &top, const QString &sub, const QString &name)
{
    return m_sections[top]->get(sub)->get(name);
}

QList<ConfigSectionTop *> ConfigDataList::list()
{
    return tops;
}

void ConfigDataList::clear()
{
    configs.clear();
    ConfigSectionSub* su;
    foreach (su, subs) {
        su->clear();
    }
    subs.clear();

    ConfigSectionTop* to;
    foreach (to, tops) {
        to->clear();
    }
    tops.clear();
}
