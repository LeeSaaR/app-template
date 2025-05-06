#include "propui.h"


int PropUi::frame_title_padding()
{
    return 16;
}

int PropUi::frame_title_height()
{
    return 64;
}

int PropUi::frame_title_height_startup()
{
    return 64+16;
}

void PropUi::setFrameHeight(QFrame *frame, const int &height)
{
    frame->setMinimumHeight(height);
    frame->setMaximumHeight(height);
}

void PropUi::setFramePadding(QFrame *frame, const int &padding)
{
    frame->setContentsMargins(padding, padding, padding, padding);
}


