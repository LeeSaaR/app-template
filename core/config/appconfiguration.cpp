#include "appconfiguration.h"
/* To add more ConfigData Properties:
* Add a property in the config.json file with a unique name.
* Set Display Name (Name) and ConfigData::PropType (Type)
* as a String in config_struct.json file.
* If the added property is a DropDown or DropDownFile go to
* AppConfiguration::initConfigData() and use
* ConfigData::setValues(QList<QString> &values)
* to add the drop down options as below
*
* From Outside this Class ConfigData is accessible with:
* QString AppConfiguration::getConfigData(const QString &_name)
*/

#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>

#include "appio.h"
#include "appdata.h"
#include "propoptions.h"

AppConfiguration* AppConfiguration::m_instance = nullptr;

AppConfiguration* AppConfiguration::GetInstance()
{
    if (m_instance == nullptr)
        m_instance = new AppConfiguration();

    return m_instance;
}

AppConfiguration::~AppConfiguration()
{
}

// Initialize
void AppConfiguration::initConfiguration()
{
    if (data_list){
        data_list->clear();
        delete data_list;
    }
    data_list = new ConfigDataList();
    load();
}

void AppConfiguration::loadConfigDataStructure()
{
    AppData* appData = AppData::GetInstance();
    QJsonDocument jsonDoc = AppIO::loadJsonFile(appData->file_config_struct());

    QJsonObject objMain = jsonDoc.object();

    QList<QString> top_section_names = objMain.keys();
    QString top_section_name;
    foreach (top_section_name, top_section_names) {
        // Init Top Sections

        QJsonObject objTopSection = objMain.value(top_section_name).toObject();
        QList<QString> sub_section_names = objTopSection.keys();
        QString sub_section_name;
        foreach (sub_section_name, sub_section_names) {
            // Init Sub Sections

            QJsonObject objSubSection = objTopSection.value(sub_section_name).toObject();
            QList<QString> config_data_names = objSubSection.keys();
            QString config_data_name;
            foreach (config_data_name, config_data_names) {
                // Init Config Data
                QJsonObject objConfigData = objSubSection.value(config_data_name).toObject();
                QString configDataName = objConfigData["Name"].toString();
                int configDataPropType = objConfigData["Type"].toString().toInt();

                addConfigData(config_data_name, top_section_name, sub_section_name );
                initConfigData(
                    config_data_name,
                    configDataName,
                    "",
                    "",
                    ConfigData::getPropType(configDataPropType) );
            }
        }
    }

    PropOptions *options = PropOptions::GetInstance();
    // Set drop down options
    m_config_data["CurrentTheme"]->setValues(options->Themes());
    m_config_data["MenuPosition"]->setValues(options->MenuPositions());
    m_config_data["Language"]->setValues(options->Languages());
    // Set other options here:
}

void AppConfiguration::initConfigData(
    const QString &_obj_name,
    const QString &_name,
    const QString &_value,
    const QString &_default_value,
    const ConfigData::PropType _type
    )
{
    ConfigData *data = m_config_data[_obj_name];
    data->init( _obj_name, _name, _value, _default_value, _type );
    data_list->addData(data);
}

void AppConfiguration::addConfigData(const QString &_name, const QString &top, const QString &sub)
{
    ConfigData *data = new ConfigData(top, sub);
    m_config_data[_name] = data;
}

void AppConfiguration::setConfigData(const QString &_name, const QString &_value)
{
    m_config_data[_name]->setValue(_value);
}

void AppConfiguration::fromJsonDoc(const QJsonDocument &jsonDoc)
{
    // Main Object
    QJsonObject objMain = jsonDoc.object();

    for (const QString &top : objMain.keys()) {
        QJsonObject objTop = objMain[top].toObject();

        for (const QString &sub : objTop.keys()) {
            QJsonObject objSub = objTop[sub].toObject();

            for (const QString &config_name : objSub.keys()) {
                QString value = objSub.value(config_name).toString();
                setConfigData(config_name, value);
            }
        }
    }
}

QJsonDocument AppConfiguration::toJsonDoc()
{
    QJsonObject objMain;

    QMapIterator<QString, ConfigData*> it(m_config_data);
    while (it.hasNext())
    {
        it.next();
        ConfigData* data    = it.value();
        const QString name  = it.key();
        const QString value = data->value();
        const QString top   = data->top();
        const QString sub   = data->sub();

        QJsonObject objTop = objMain[top].toObject();
        QJsonObject objSub = objTop[sub].toObject();

        objSub[name] = value;
        objTop[sub]  = objSub;
        objMain[top] = objTop;
    }

    QJsonDocument jsonDoc;
    jsonDoc.setObject(objMain);
    return jsonDoc;
}

void AppConfiguration::init()
{
    initConfiguration();
    m_is_initialized = true;
}

bool AppConfiguration::is_initialized() const
{
    return m_is_initialized;
}


void AppConfiguration::save()
{
    qDebug() << __FUNCTION__;
    AppData* appData = AppData::GetInstance();
    QJsonDocument jsonDoc = toJsonDoc();
    AppIO::saveJsonFile(appData->file_config(), jsonDoc);
    emit updateConfig();
}

bool AppConfiguration::load()
{
    loadConfigDataStructure();
    AppData* appData = AppData::GetInstance();
    QJsonDocument jsonDoc = AppIO::loadJsonFile(appData->file_config());
    fromJsonDoc(jsonDoc);
    return true;
}

QString AppConfiguration::getConfigData(const QString &_name) const
{
    return m_config_data[_name]->value();
}

QList<ConfigData *> AppConfiguration::getConfigData() const
{
    QList<ConfigData*> data;
    QMapIterator<QString, ConfigData*> map_data(m_config_data);
    while (map_data.hasNext()) {
            map_data.next();
            data.append(map_data.value());
    }
    return data;
}


