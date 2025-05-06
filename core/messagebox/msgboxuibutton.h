#ifndef MSGBOXUIBUTTON_H
#define MSGBOXUIBUTTON_H

#include "msgbox.h"
#include <QPushButton>


class MsgBoxUiButton : public QPushButton
{
    Q_OBJECT
private:
    MsgBox::ExitCode m_exit_code;
public:
    MsgBoxUiButton(QWidget* parent) : QPushButton(parent){}
    MsgBox::ExitCode exit_code() const;
    void setExitCode(MsgBox::ExitCode exit_code);
};

#endif // MSGBOXUIBUTTON_H
