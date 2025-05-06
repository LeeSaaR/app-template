#ifndef MSGBOXMESSAGE_H
#define MSGBOXMESSAGE_H

#include "msgboxbutton.h"

#include <QMessageBox>
#include <QList>

class MsgBoxMessage
{
private:

    QString m_title;
    QString m_message;
    QList<MsgBoxButton*> btns;

public:
    MsgBoxMessage(){}
    QString title() const {
        return m_title;
    };
    void setTitle(const QString &newTitle) {
        m_title = newTitle;
    };

    void addButton(const QString &text, const MsgBox::ExitCode &exit_code) {
        MsgBoxButton* btn = new MsgBoxButton(text, exit_code);
        btns.append(btn);
    };

    QString message() const {
        return m_message;
    };

    void setMessage(const QString &newMessage) {
        m_message = newMessage;
    };

    QList<MsgBoxButton*> buttons() {return btns;};
};

#endif // MSGBOXMESSAGE_H
