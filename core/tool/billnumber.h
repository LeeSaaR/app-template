#ifndef BILLNUMBER_H
#define BILLNUMBER_H

#include <QMap>
#include <QChar>
#include <QString>

class BillNumber
{
private:
    static QMap<int, QChar> m_code;
    BillNumber(){};
public:
    static QString numberBill(const int &number, const bool &decoded = false);
    static QString numberOrder(const int &number, const bool &decoded = false);
    static QString convertNumber(const int &num);
};

#endif // BILLNUMBER_H
