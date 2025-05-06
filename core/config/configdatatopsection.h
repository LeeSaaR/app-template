#ifndef CONFIGDATATOPSECTION_H
#define CONFIGDATATOPSECTION_H

#include "configdatasubsection.h"

class ConfigDataTopSection
{
private:
    const QString m_name;
    QMap<QString, ConfigDataSubSection*> m_sub_section;

public:
    ConfigDataTopSection();
    ~ConfigDataTopSection();

public:
    void addSection(const QString &_name, ConfigDataSubSection *_sub_section);
    ConfigDataSubSection *getSection(const QString &_name);
    QString name() const;
};

#endif // CONFIGDATATOPSECTION_H
