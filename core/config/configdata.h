#ifndef CONFIGDATA_H
#define CONFIGDATA_H

#include <QString>
#include <QMap>
//#include "appconfiguration.h"


class ConfigData;

class ConfigData
{
private:
    QString m_top;
    QString m_sub;

public:
    enum PropType {
        Dir = 0,
        DropDown = 1,
        DropDownFile,
        File,
        Text
    };

private:
    QString m_object_name;
    QString m_name;
    QString m_value;
    QString m_default_value;
    PropType m_type;
    QList<QString> m_values = {};

public:
    explicit ConfigData(const QString &top, const QString &sub) : m_top(top), m_sub(sub) { }
    ~ConfigData();

    void init(const QString &_object_name,
              const QString &_name,
              const QString &_value,
              const QString &_default_value,
              const PropType &_type);

public:
    static PropType getPropType(const int &index);

public:
    QString top() const {return m_top;}
    QString sub() const {return m_sub;}
    QString object_name() const;
    QString name() const;
    PropType type() const;
    QString value() const;
    QList<QString> values() const;
    QString defaultValue() const;
    void setValue(const QString &value);
    void setValues(const QList<QString> &values);
    void setDefaultValue(const QString &value);
};

#endif // CONFIGDATA_H
