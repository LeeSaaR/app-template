#include "billnumber.h"

#include <QDate>

QMap<int, QChar> BillNumber::m_code = {
    {0, 'X'},
    {1, 'T'},
    {2, 'Z'},
    {3, 'U'},
    {4, 'G'},
    {5, 'J'},
    {6, 'K'},
    {7, 'V'},
    {8, 'M'},
    {9, 'P'}
};

QString BillNumber::numberBill(const int &number, const bool &decoded)
{
    QString out;
    QString year = QDate::currentDate().toString("yy");
    QString day = QString::number(QDate::currentDate().dayOfYear());
    if (day.size() == 1) day.prepend("00");
    if (day.size() == 2) day.prepend("0");
    if (decoded) {
        // year
        out.append("B"+convertNumber(year.toInt())+"-");
        // day
        for (const QChar &s : std::as_const(day))
            out.append(m_code[QString(s).toInt()]);
        // bill
        out.append("-C"+convertNumber(number));
    }
    else {
        out.append("B"+year+"-");
        out.append(day);
        out.append("-C"+QString::number(number));
    }

    return out;
}

QString BillNumber::numberOrder(const int &number, const bool &decoded)
{
    QString out;
    QString year = QDate::currentDate().toString("yy");
    QString day = QString::number(QDate::currentDate().dayOfYear());
    if (day.size() == 1) day.prepend("00");
    if (day.size() == 2) day.prepend("0");
    if (decoded) {
        // year
        out.append("O"+convertNumber(year.toInt())+"-");
        // day
        for (const QChar &s : std::as_const(day))
            out.append(m_code[QString(s).toInt()]);
        // bill
        out.append("-"+convertNumber(number));
    }
    else {
        out.append("O"+year+"-");
        out.append(day);
        out.append("-"+QString::number(number));
    }

    return out;
}

QString BillNumber::convertNumber(const int &num)
{
    QString out;
    const QString str_num = QString::number(num);
    for (const QChar &s : std::as_const(str_num))
        out.append(m_code[QString(s).toInt()]);
    return out;
}
