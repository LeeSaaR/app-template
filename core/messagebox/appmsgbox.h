#ifndef APPMSGBOX_H
#define APPMSGBOX_H

#include "msgboxmessage.h"
#include "msgbox.h"

#include <QDialog>

namespace Ui {
class AppMsgBox;
}

class AppMsgBox : public QDialog
{
    Q_OBJECT

private:
    Ui::AppMsgBox *ui;
    MsgBox::ExitCode m_exit_code = MsgBox::ExitCode::Cancel;
    static QMap<MsgBox::Message, MsgBoxMessage*> m_messages;

public:
    explicit AppMsgBox(const MsgBox::Message &msg, QWidget *parent = nullptr, const QString& var_text = "");
    ~AppMsgBox();

public:
    static void setMessages(const QMap<MsgBox::Message, MsgBoxMessage*> &messages);
    void clearMessages();
    void setMessage(const MsgBox::Message &msg, const QString& var_text = "");
    QString insertVar(QString message, const QString& var_text = "");
    void setTitle(const QString &title);
    void setText(const QString &text);
    void addButton(const QString &name, MsgBox::ExitCode exit_code);
    MsgBox::ExitCode exit_code();

private slots:
    void onClickedButton();
};

#endif // APPMSGBOX_H
