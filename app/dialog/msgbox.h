#ifndef MSGBOX_H
#define MSGBOX_H


class MsgBox
{

private:
    MsgBox() = delete;
    ~MsgBox() = delete;

public:
    enum Message {
        Generic = 1,
        SaveBeforeClose,
        FileExists,
        InfoRestart,
        CloseApp,
        AskDelete
    };

    enum ExitCode {
        Ok = 1,
        Yes,
        No,
        Save,
        Discard,
        Cancel,
        Exit,
    };
};

#endif // MSGBOX_H
