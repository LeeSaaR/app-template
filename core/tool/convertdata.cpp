#include "convertdata.h"

#include <QChar>

QString ConvertData::seperatePascalCase(const QString &pascalCasedString)
{
    QString seperatedString = "";
    for (QChar c : pascalCasedString) {
        if (c.isUpper())
            seperatedString.append(' ');
        seperatedString.append(c);
    }
    seperatedString.remove(0,1);
    return seperatedString;
}
