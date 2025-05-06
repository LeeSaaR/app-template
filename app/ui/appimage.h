#ifndef APPIMAGE_H
#define APPIMAGE_H

#include <QPixmap>

class AppImage
{
private:
    AppImage() = delete;

public:
    // IMAGES
    static QPixmap logo(const int &w, const int &h);
    static QPixmap logo64();
    static QPixmap logo128();
};

#endif // APPIMAGE_H
