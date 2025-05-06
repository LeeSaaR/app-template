#ifndef PROPUI_H
#define PROPUI_H

#include <QFrame>

class PropUi
{
public:
    PropUi() = delete;

    static int frame_title_padding();
    static int frame_title_height();
    static int frame_title_height_startup();
    static void setFrameHeight(QFrame *frame, const int &height);
    static void setFramePadding(QFrame *frame, const int &padding);
};

#endif // PROPUI_H
