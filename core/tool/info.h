#ifndef INFO_H
#define INFO_H

#include <QString>

class Info
{
private:
    Info();
public:
    static void msg(const QString& text);
    static void prog(const int& val);
    static void text(const QString& text);
};

#endif // INFO_H
