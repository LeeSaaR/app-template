#ifndef MSGBOXDATA_H
#define MSGBOXDATA_H

/*
 * STATIC CLASS:
 * This class defines the messages of AppMsgBox.
 * It is only called on AppInitializer::init()
 * and on AppInitializer::updateApp()
*/

class MsgBoxData
{

private:
    MsgBoxData() = delete;
    ~MsgBoxData() = delete;

public:
    static void initData();
};

#endif // MSGBOXDATA_H
