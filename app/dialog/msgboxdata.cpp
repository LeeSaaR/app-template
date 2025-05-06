#include "msgboxdata.h"

#include <QMap>
#include <QDebug>
#include "appdata.h"
#include "appmsgbox.h"
#include "msgbox.h"
#include "msgboxmessage.h"
#include "apptext.h"

void MsgBoxData::initData()
{
    AppData* appData = AppData::GetInstance();
    QMap<MsgBox::Message, MsgBoxMessage*> messages;

    // MESSAGE
    MsgBoxMessage *message = new MsgBoxMessage();
    message->setTitle(appData->appName());
    message->setMessage("Do you want to <b>save</b> before closing?");
    message->addButton(AppText::btn_discard(), MsgBox::Discard);
    message->addButton(AppText::btn_save(), MsgBox::Save);
    message->addButton(AppText::btn_cancel(), MsgBox::Cancel);
    messages[MsgBox::Message::SaveBeforeClose] = message;
    message = nullptr;

    // MESSAGE
    message = new MsgBoxMessage();
    message->setTitle(appData->appName());
    message->setMessage("Restart to apply changes?");
    message->addButton(AppText::btn_no(), MsgBox::No);
    message->addButton(AppText::btn_yes(), MsgBox::Yes);
    messages[MsgBox::Message::InfoRestart] = message;
    message = nullptr;

    // MESSAGE
    message = new MsgBoxMessage();
    message->setTitle(appData->appName());
    message->setMessage("File already exists.\nDo you wnat to overwrite?");
    message->addButton(AppText::btn_no(), MsgBox::No);
    message->addButton(AppText::btn_yes(), MsgBox::Yes);
    messages[MsgBox::Message::FileExists] = message;
    message = nullptr;

    // MESSAGE
    message = new MsgBoxMessage();
    message->setTitle(appData->appName());
    message->setMessage("Just an Info!");
    message->addButton(AppText::btn_ok(), MsgBox::Ok);
    messages[MsgBox::Message::Generic] = message;
    message = nullptr;

    // MESSAGE
    message = new MsgBoxMessage();
    message->setTitle(appData->appName());
    message->setMessage("Delete?");
    message->addButton(AppText::btn_no(), MsgBox::No);
    message->addButton(AppText::btn_yes(), MsgBox::Yes);
    messages[MsgBox::Message::AskDelete] = message;
    message = nullptr;

    // AppMsgBox defined here
    AppMsgBox::setMessages(messages);
}
