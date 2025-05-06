#include "configdata.h"

#include <QDebug>

ConfigData::~ConfigData()
{

}

void ConfigData::init(
    const QString &_object_name,
    const QString &_name,
    const QString &_value,
    const QString &_default_value,
    const PropType &_type)
{
    m_object_name   = _object_name;
    m_name          = _name;
    m_value         = _value;
    m_default_value = _default_value;
    m_type          = _type;
}

ConfigData::PropType ConfigData::getPropType(const int &index)
{
    //qDebug() << __FUNCTION__;
    switch (index) {
    case 0:
        return PropType::Dir;
        break;
    case 1:
        return PropType::DropDown;
        break;
    case 2:
        return PropType::DropDownFile;
        break;
    case 3:
        return PropType::File;
        break;
    case 4:
        return PropType::Text;
        break;
    default:
        return PropType::Text;
        break;
    }
}

QString ConfigData::object_name() const
{
    return m_object_name;
}

QString ConfigData::name() const
{
    return m_name;
}

ConfigData::PropType ConfigData::type() const
{
    return m_type;
}

QString ConfigData::value() const
{
    return m_value;
}

QList<QString> ConfigData::values() const
{
    return m_values;
}

void ConfigData::setValue(const QString &value)
{
    m_value = value;
}

void ConfigData::setValues(const QList<QString> &values)
{
    m_values = values;
}

QString ConfigData::defaultValue() const
{
    return m_default_value;
}

void ConfigData::setDefaultValue(const QString &value)
{
    m_default_value = value;
}
