#include "msgboxuibutton.h"

void MsgBoxUiButton::setExitCode(MsgBox::ExitCode exit_code)
{
    m_exit_code = exit_code;
}

MsgBox::ExitCode MsgBoxUiButton::exit_code() const
{
    return m_exit_code;
}
