#ifndef CONFIGDATASUBSECTION_H
#define CONFIGDATASUBSECTION_H

#include "configdata.h"
#include <QMap>

class ConfigDataSubSection
{
private:
    const QString m_name;
    QMap<QString, ConfigData*> m_data;

public:
    ConfigDataSubSection(const QString &_name);
    ~ConfigDataSubSection();

public:
    QString name() const;
    void addData(const QString &_name, ConfigData *newConfigData);
    ConfigData *getData(const QString &_name);
    QMap<QString, ConfigData*> getAllData();
};

#endif // CONFIGDATASUBSECTION_H
