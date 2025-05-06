#include "appmsgbox.h"
#include "ui_appmsgbox.h"

#include "msgboxuibutton.h"
#include "propui.h"
#include <QPushButton>
#include <QDebug>

QMap<MsgBox::Message, MsgBoxMessage*> AppMsgBox::m_messages;

AppMsgBox::AppMsgBox(const MsgBox::Message &msg, QWidget *parent, const QString& var_text)
    : QDialog(parent)
    , ui(new Ui::AppMsgBox)
{
    ui->setupUi(this);
    PropUi::setFrameHeight(ui->frame_buttons, 30);
    setMessage(msg);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint );
}

AppMsgBox::~AppMsgBox()
{
    delete ui;
}


void AppMsgBox::setMessages(const QMap<MsgBox::Message, MsgBoxMessage *> &messages)
{
    if(!m_messages.isEmpty())
        qDeleteAll(m_messages);
    m_messages = messages;
}

void AppMsgBox::clearMessages()
{
    if(!m_messages.isEmpty())
        qDeleteAll(m_messages);
}

void AppMsgBox::setMessage(const MsgBox::Message &msg, const QString& var_text)
{
    MsgBoxMessage *message = m_messages[msg];
    setTitle(message->title());
    setText( insertVar(message->message()) );
    MsgBoxButton* btn;
    foreach (btn, message->buttons())
        addButton(btn->text(), btn->exit_code());
}

QString AppMsgBox::insertVar(QString message, const QString &var_text)
{
    if (var_text.isEmpty())
        return message;

    return message.arg(var_text);
}

void AppMsgBox::setTitle(const QString &title)
{
    setWindowTitle(title);
}

void AppMsgBox::setText(const QString &text)
{
    ui->label->setText(text);
}

void AppMsgBox::addButton(const QString &name, MsgBox::ExitCode exit_code)
{
    MsgBoxUiButton* btn = new MsgBoxUiButton(this);
    btn->setAccessibleName("normal");
    btn->setText(name);
    btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn->setExitCode(exit_code);
    ui->frame_buttons->layout()->addWidget(btn);
    connect(btn, &MsgBoxUiButton::clicked, this, &AppMsgBox::onClickedButton);
}

MsgBox::ExitCode AppMsgBox::exit_code()
{
    return m_exit_code;
}

void AppMsgBox::onClickedButton()
{
    MsgBoxUiButton* btn = (MsgBoxUiButton*)sender();
    m_exit_code = btn->exit_code();
    close();
}
