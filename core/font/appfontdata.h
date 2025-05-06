#ifndef APPFONTDATA_H
#define APPFONTDATA_H

#include <QString>

class AppFontData
{
public:
    AppFontData() = delete;
    ~AppFontData() = delete;

    static void initApplicationFonts();
    static void addToFontDatabase(const QString &fontFileName);
};

#endif // APPFONTDATA_H
