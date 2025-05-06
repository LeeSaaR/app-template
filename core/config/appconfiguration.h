#ifndef APPCONFIGURATION_H
#define APPCONFIGURATION_H

#include "configdata.h"
#include "configdatalist.h"

#include <QObject>
#include <QJsonDocument>
#include <QList>
#include <QString>

class AppConfiguration : public QObject
{
    Q_OBJECT

public:
    ConfigDataList* data_list = nullptr;
private:
    // ConfigData
    bool m_is_initialized = false;
    QMap<QString, ConfigData*> m_config_data;
    QMap<QString, ConfigData*> m_config_data_old;

private:
    AppConfiguration(){}

protected:
    static AppConfiguration* m_instance;

public:
    ~AppConfiguration();
    AppConfiguration(AppConfiguration &other) = delete; // copy
    void operator=(const AppConfiguration &other) = delete; // assign
    static AppConfiguration *GetInstance();

signals:
    void updateConfig();

private:
    // Initialize
    void initConfiguration();
    void loadConfigDataStructure();
    void initConfigData(
        const QString &_obj_name,
        const QString &_name,
        const QString &_value,
        const QString &_default_value,
        const ConfigData::PropType _type);

    void addConfigData(const QString &_name, const QString &top, const QString &sub);
    void setConfigData(const QString &_name, const QString &_value);

private:
    void fromJsonDoc(const QJsonDocument &jsonDoc);
    QJsonDocument toJsonDoc();

public:
    void init();
    bool is_initialized() const;
    void save();
    bool load();

    ConfigDataList* list(){return data_list;};

public:
    // Getter
    QString getConfigData(const QString &_name) const;
    QList<ConfigData*> getConfigData() const;
};

#endif // APPCONFIGURATION_H
