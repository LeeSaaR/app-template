#ifndef MSGBOXBUTTON_H
#define MSGBOXBUTTON_H

#include "msgbox.h"

#include <QString>
#include <QMessageBox>

class MsgBoxButton
{
private:
    const QString m_text;
    const MsgBox::ExitCode m_exit_code;
public:
    MsgBoxButton(const QString &text, const MsgBox::ExitCode &exit_code)
        : m_text(text), m_exit_code(exit_code) {};
    QString text() const & {return m_text;};
    MsgBox::ExitCode exit_code() const & {return m_exit_code;};
};

#endif // MSGBOXBUTTON_H
