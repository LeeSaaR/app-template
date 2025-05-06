#ifndef CONVERTDATA_H
#define CONVERTDATA_H

#include <QString>
class ConvertData
{
public:
    ConvertData(){};

    static QString seperatePascalCase(const QString &pascalCasedString);
};

#endif // CONVERTDATA_H
