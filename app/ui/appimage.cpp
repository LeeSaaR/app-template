#include "appimage.h"


QPixmap AppImage::logo(const int &w, const int &h)
{
    return QPixmap(":/logo/applogo_128_template.png").scaled(w,h);
}

QPixmap AppImage::logo64()
{
    return logo(64,64);
}

QPixmap AppImage::logo128()
{
    return logo(128,128);
}
